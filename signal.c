//  Collaboration with Mary Nwosu 
//  hello_signal.c

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

int alarmTriggered = 0;

void myhandler(int signum) {          //signal handler
  printf("Hello World!\n");
  alarmTriggered = 1;
}

int main(int argc, char * argv[]) {
  signal(SIGALRM, myhandler);        //register handler to handle SIGALRM

  while(1) {
    alarm(1);                       //Schedule a SIGALRM for 1 second
    while(!alarmTriggered)
      ;
                                
    printf("Turing was right!\n");
    alarmTriggered = 0;
  }
  return 0;                         //never reached
}
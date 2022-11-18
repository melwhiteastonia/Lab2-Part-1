//  timer.c
//  Collaboration with Mary Nwosu 

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//variable dec
int total_alarms = 0;
int alarmTriggered = 0;
time_t start, stop;

void increment_alarm() {
  total_alarms += 1;
}

void sigint_handler(int signum) {     //signal interrupt handler
  stop = time(NULL);
  printf("\nTotal alarms occured in the code: %d\n", total_alarms);
  printf("The program was executed for %lf seconds.\n", (double)(stop-start));
  exit(0);
}

void myhandler(int signum) {          //signal handler
  printf("Hello World!\n");
  alarmTriggered = 1;
}

int main(int argc, char * argv[]) {
  start = time(NULL);
  signal(SIGALRM, myhandler);        //register handler to handle SIGALRM
  signal(SIGINT, sigint_handler);

  while(1) {
    alarm(1);                       //Schedule a SIGALRM for 1 second
    increment_alarm();

    while(!alarmTriggered)
      ;
                                
    printf("Turing was right!\n");
    alarmTriggered = 0;
  }
  return 0;                         //never reached
}
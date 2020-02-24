#include <sys/types.h>
#include <sys/times.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    int status;
    time_t secondsStart; // The program prints the number of seconds since
    secondsStart = time(NULL);
    printf("\nSTART: %ld", secondsStart);

    pid_t childPID; // creating a child process
    childPID = 0;
    pid_t parentPID;
    pid_t selfPID;
    clock_t fromStart;

    struct tms populateTimes;
  
    childPID = fork();   
    waitpid(childPID, &status, 0); // The program will wait for the child to finish

    selfPID = getpid();
    parentPID = getppid();
    
    printf("\nPPID: %d, PID: %d", parentPID, selfPID);
    if (childPID != 0) {
        printf(", CPID: %d, RETVAL: %d", childPID, status);
    }

    fromStart = times(&populateTimes);
    printf("\nUSER: %ld, SYS: %ld" , populateTimes.tms_utime, populateTimes.tms_stime);
    printf("\nCUSER: %ld, CSYS: %ld" , populateTimes.tms_utime, populateTimes.tms_stime);

    // if applicable 
    //  fork getppid & getpid

        // return status of its child
        // void exit(int status);
        // waitpid(pid_t pid, int *status, int options);

    time_t secondsStop; // The program prints the number of seconds since
    secondsStop = time(NULL);
    printf("\nSTOP: %ld", secondsStop);

    exit(0);
}

/* 
time-4-baby-and-me.txt:
1410281230 26485 26846 26484 26485 26846 0

read from file?
    START: 1410281230
    PPID:26485, PID: 26846
    PPID:26484, PID: 26485, CPID: 26846, RETVAL: 0

program reports:
    USER: 233354, SYS:  2334455
    CUSER:234434, CSYS: 233223
    STOP: 1410281240

*/

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
 

// method signatures
void printPIDInfo (pid_t parentPID,  pid_t selfPID, pid_t childPID, int status);
void printCurrentTime();

int main() {


    int status;
    pid_t childPID; // creating a child process
    childPID = 0;
    pid_t parentPID;
    pid_t selfPID;
    selfPID = 0;
    clock_t fromStart;

    // print out start time in seconds
    printf("START: ");
    printCurrentTime();
    fflush(NULL);

    childPID = fork();
    waitpid(childPID, &status, 0); // The program will wait for the child to finish

    selfPID = getpid();     // get current process' PID
    parentPID = getppid();  // get current process' parent's PID

    printPIDInfo(parentPID, selfPID, childPID, status);

    // print out stop time in seconds
    if (childPID > 0) {
        printf("STOP: "); 
        printCurrentTime();
    }
    
    exit(0);
}

 // The program prints the current time in seconds
void printCurrentTime() {
    time_t currentTime;
    currentTime = time(NULL);
    printf("%ld\n", currentTime);

}

//printing out pids and sys/user times
void printPIDInfo (pid_t parentPID,  pid_t selfPID, pid_t childPID, int status) {
    printf("PPID: %d, PID: %d", parentPID, selfPID);

    if (childPID > 0) {   
        struct tms populateTimes;
        printf(", CPID: %d, RETVAL: %d", childPID, WIFEXITED(status));
        times(&populateTimes);
        printf("\nUSER: %ld, SYS: %ld" , populateTimes.tms_utime, populateTimes.tms_stime);
        printf("\nCUSER: %ld, CSYS: %ld\n" , populateTimes.tms_cutime, populateTimes.tms_cstime);
    }
    else { 
        printf("\n");
    }
}

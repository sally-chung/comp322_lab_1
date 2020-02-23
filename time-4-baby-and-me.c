#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>

int main() {

    time_t secondsStart; // The program prints the number of seconds since
    secondsStart = time(NULL;)
    pid_t childPID; // creating a child process
    pid_t fork(void);    
    pid_t waitpid(pid_t pid, int *status, int options); // The program will wait for the child to finish


    pid_t getppid(void);    // gets PID of parent
    pid_t getpid(void);     // gets its own PID
    // if applicable 
    //  fork getppid & getpid

        // return status of its child
        // void exit(int status);
        // waitpid(pid_t pid, int *status, int options);

    time_t secondsFinish; // The program prints the number of seconds since
    secondsFinish = time(NULL;)

    
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

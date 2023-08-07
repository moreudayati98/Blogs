#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t pids[10];
    int i;

    for (i = 9; i >= 0; --i) {
        pids[i] = fork();
        if (pids[i] == 0) {
            printf("Child%d\n", i);
            sleep(i+1); //last process will sleep for 10 sec
            _exit(0);
        }
    }

	sleep(50); // processes are in zombie state
   
   for (i = 9; i >= 0; --i) {
        printf("parent%d\n", i);
        waitpid(pids[i], NULL, 0);
    }

    return 0;
}

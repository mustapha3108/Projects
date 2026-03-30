#include <stdio.h>
#include <unistd.h> // fork
#include <stdlib.h> // exit
#include <sys/wait.h>

int main()
{

    int pid[3];

    for (int i = 0; i < 3; i++)
    {
        pid[i] = fork();
        if (pid[i] == 0)
        {
            sleep(1);
            switch (i)
            {
            case 0:
                exit(5);
                break;
            case 1:
                exit(10);
                break;
            case 2:
                exit(3);
                break;
            }
        }
    }

    int res[3];
    int status;
    for (int i = 0; i < 3; i++)
    {
        /*
        pid_t finished = wait(&status);
        res[i] = WEXITSTATUS(status);
        printf("Child %d exited with %d \n", finished, res[i]);
        */

       waitpid(pid[i], &status, 0);
       res[i] = WEXITSTATUS(status);

    }

    printf("%d \n", res[0] + res[1] * res[2]);

    return 0;
}

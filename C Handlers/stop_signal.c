#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void myhandler(int mysignal)
{
    printf("Exiting\n");
    exit(0);
}

int main(int argc, char *argv[])
{
    signal(SIGTSTP, myhandler);

    while (1)
    {
        printf("pid = %d\n", getpid());
        sleep(1);
    }
    return 0;
}

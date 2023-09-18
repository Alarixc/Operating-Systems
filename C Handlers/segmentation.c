#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void myhandle(int signum)
{
    printf("There is a segmentation fault!\nPlease check!");
    exit(2);
}

int main()
{
    int *p = NULL;
    signal(SIGSEGV, myhandle);
    *p = 1;

    return 0;
}

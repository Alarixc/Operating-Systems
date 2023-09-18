#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void myhandle(int signum)
{
    printf("There is a divide by zero error\n");
    exit(2);
}

int main()
{
    int result;
    int v1, v2;
    v1 = 100;
    v2 = 0;
    printf("dividing: %d/%d\n", v1, v2);
    signal(SIGFPE, myhandle);
    result = v1 / v2;

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    id_t pid;
    fork();
    pid = getpid();
    int n, i, sum = 0;
    printf("Enter number: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i++)
    {
        sum += i;
    }

    printf("\nSum: %d\n", sum);
}

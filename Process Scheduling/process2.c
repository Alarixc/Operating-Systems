#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int i, n;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;
    printf("Fibonacci Series: %d, %d, ", t1, t2);
    for (i = 3; i <= n; ++i)
    {
        printf("%d, ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    pid_t pid;

    if (argc != 2)
    {
        printf("arg missing or exceeding\n");
        exit(0);
    }

    if (atoi(argv[1]) < 0)
    {
        printf("negative number entered %d", atoi(argv[1]));
        exit(0);
    }

    pid = fork();

    if (pid < 0)
    {
        printf("failed to create child\n");
        exit(0);
    }

    else if (pid == 0)
    {
        int ans = 0, i, j, k = 2, n;
        n = atoi(argv[1]);
        int arr[n], sum[n];

        arr[0] = 1;
        for (i = 1; i < n; i++)
        {
            arr[i] = arr[i - 1] * k;
            k++;
        }
        for (j = 0; j < n; j++)
        {
            sum[j] = 0;
            for (i = 0; i <= j; i++)
            {
                printf(" %d ", arr[i]);
                sum[j] += arr[i];
            }
            printf("\n");
        }

        for (i = 0; i < n; i++)
        {
            if ((sum[i] % 2) == 0)
                sum[i] = -1;
        }

        exit(0);
    }

    else
    {
        wait(NULL);
    }
}

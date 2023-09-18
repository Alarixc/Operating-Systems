#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun1()
{
    int i, n;
    int t1 = 0, t2 = 1;
    int nextTerm = t1 + t2;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: %d, %d, ", t1, t2);

    for (i = 3; i <= n; ++i)
    {
        printf("%d, ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
}

void *fun2()
{
    int n, square;
    printf("Enter the number that you want to square: ");
    scanf("%d", &n);

    square = n * n;
    printf("Square of %d is %d", n, square);
}

int main()
{
    pthread_t thread1, thread2;
    int iret1, iret2;

    iret1 = pthread_create(&thread1, NULL, fun1, NULL);
    iret2 = pthread_create(&thread2, NULL, fun2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}

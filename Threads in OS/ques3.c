#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun1()
{
    int i, fact = 1, number;
    printf("Enter a number: ");
    scanf("%d", &number);
    for (i = 1; i <= number; i++)
    {
        fact = fact * i;
    }
    printf("Factorial of %d is: %d", number, fact);
    printf("\n");
}

void *fun2()
{
    int n, i, m = 0, flag = 0;
    printf("Enter the number to check prime:");
    scanf("%d", &n);
    m = n / 2;
    for (i = 2; i <= m; i++)
    {
        if (n % i == 0)
        {
            printf("Number is not prime");
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Number is prime\n");
    printf("%d\n", n);
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

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun1()
{
    int n, r, sum = 0, temp;
    printf("Enter the number=");
    scanf("%d", &n);
    temp = n;
    while (n > 0)
    {
        r = n % 10;
        sum = sum + (r * r * r);
        n = n / 10;
    }
    if (temp == sum)
        printf("Armstrong  number\n");
    else
        printf("Not an armstrong number\n");
}

void *fun2()
{
    int n, reverse = 0, remainder;
    printf("\n");
    printf("Enter an integer: ");
    scanf("%d", &n);

    while (n != 0)
    {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    printf("Reversed number = %d", reverse);
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

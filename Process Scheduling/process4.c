#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
void main()
{
    int n, rev = 0, rem, num;
    printf("Enter number: ");
    scanf("%d", &n);
    num = n;
    while (n != 0)
    {
        rem = n % 10;
        rev = rev * 10 + rem;
        n /= 10;
    }
    if (num == rev)
        printf("\n%d is a palindrome\n", num);
    else
        printf("\n%d is not a palindrome\n", num);
    fork();
    if (num % 2 == 0)
        printf("\n%d is an even number\n", num);
    else
        printf("\n%d is a odd number\n", num);
}

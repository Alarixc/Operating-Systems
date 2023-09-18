#include <stdio.h>
int main()
{
    int i, j, n, time, remain, flag = 0, quantum;
    int wt = 0, tat = 0, at[10], bt[10], rt[10], tatime = 0, wtime = 0, p[10];
    printf("Enter no. of process: ");
    scanf("%d", &n);
    remain = n;
    for (i = 0; i < n; i++)
    {
        printf("\nEnter the arrival and burst time of the process[%d]\n", i + 1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        printf("\n");
    }
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);
    printf("\nPROCESS\t\tBURST\tTURN AROUND TIME\tWAITING TIME\n");
    for (time = 0, i = 0; remain != 0;)
    {
        if (rt[i] <= quantum && rt[i] > 0)
        {
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if (rt[i] > 0)
        {
            rt[i] -= quantum;
            time += quantum;
        }
        if (rt[i] == 0 && flag == 1)
        {
            remain--;
            printf("\n%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], time - at[i], time - at[i] - bt[i]);
            wt += time - at[i] - bt[i];
            tat = tat + time - at[i];
            flag = 0;
        }
        if (i == n - 1)
        {
            i = 0;
        }
        else if (at[i + 1] <= time)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    printf("\nAverage turn around time:%.2f", wt * 1.0 / n);
    printf("\nAverage waiting time:%.2f", tat * 1.0 / n);
    printf("\n");
    return 0;
}

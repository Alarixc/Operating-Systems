#include <stdio.h>
int main()
{
    int bt[10], p[10], wt[10], tat[10], pr[10], i, j, n, total = 0, pos, temp, wtime = 0, tatime = 0;
    float avg_wt, avg_tat;
    printf("Enter no. of process: ");
    scanf("%d", &n);
    printf("Enter the burst time and priority for processes: ");
    for (i = 0; i < n; i++)
    {
        printf("\nP[%d]\n", i + 1);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;
        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        total += wt[i];
    }
    avg_wt = (float)total / n;
    total = 0;
    printf("\nPROCESS\t\tBURST\t\tWAITING TIME\tTURN AROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nGANT CHART\n\n");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d |", p[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", wt[i]);
    }
    for (i = 4; i < n; i++)
    {
        printf("%d\t", wt[n - 1] + bt[n - 1]);
    }
    for (i = 0; i < n; i++)
    {
        tatime = tatime + tat[i];
        wtime = wtime + wt[i];
    }
    avg_tat = (float)total / n;
    printf("\n\nTotal waiting time:%d", wtime);
    printf("\nTotal turn around time:%d", tatime);
    printf("\n\nAverage waiting time:%.2f", avg_wt);
    printf("\nAverage turn around time:%.2f\n", avg_tat);
}

#include <stdio.h>
void main()
{
    int i, n, br[10], wt[10], wat[10], tr[10], ttr = 0, twt = 0, twat = 0;
    float awat, atur;
    printf("Enter no.of process: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the burst time for process %d: ", (i + 1));
        scanf("%d", &br[i]);
    }
    printf("\nPROCESS\t\tBURST\t\tWAITING TIME\tTURN AROUND TIME\n");
    wt[0] = 0;
    for (i = 0; i < n; i++)
    {
        wt[i + 1] = wt[i] + br[i];
        tr[i] = wt[i] + br[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d\n", i + 1, br[i], wt[i], tr[i]);
    }
    for (i = 0; i < n; i++)
    {
        ttr = ttr + tr[i];
        twat = twat + wt[i];
    }
    printf("\nGANT CHART\n\n");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf(" P%d |", i + 1);
    }
    printf("\n");
    for (i = 0; i < n; i++)
    {
        printf("--------");
    }
    printf("\n");
    for (i = 0; i <= n; i++)
    {
        printf("%d\t", wt[i]);
    }
    awat = (float)twat / n;
    atur = (float)ttr / n;
    printf("\n\nTotal waiting time:%d", twat);
    printf("\nTotal turn around time:%d", ttr);
    printf("\n\nAverage waiting time:%.2f", awat);
    printf("\nAverage turn around time:%.2f\n", atur);
}

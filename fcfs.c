#include <stdio.h>

int main() {
    int n, i, j;
    int bt[20], p[20], wt[20], tat[20];
    float wavg = 0, tatavg = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Input burst times and process IDs
    for (i = 0; i < n; i++) {
        printf("Enter Burst Time for Process %d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1; // Assign process numbers
    }

    // Calculate Waiting Time and Turnaround Time
    wt[0] = 0; // First process has zero waiting time
    tat[0] = bt[0]; // Turnaround time for first process

    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1]; // Waiting time formula
        tat[i] = wt[i] + bt[i]; // Turnaround time formula
        wavg += wt[i];
        tatavg += tat[i];
    }

    // Compute averages
    tatavg+=tat[0];
    wavg /= n;
    tatavg /= n;

    // Print process details
    printf("\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f", wavg);
    printf("\nAverage Turnaround Time: %.2f\n", tatavg);

    return 0;
}

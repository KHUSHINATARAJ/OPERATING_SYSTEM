#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int main() {
    int n, m;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    int alloc[MAX][MAX], max[MAX][MAX], avail[MAX];
    int need[MAX][MAX], finished[MAX] = {0}, safe_sequence[MAX];

    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the maximum matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the available resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (!finished[i]) {
                int j;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j])
                        break;
                }

                if (j == m) {
                    for (int k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safe_sequence[count++] = i;
                    finished[i] = 1;
                    found = true;
                }
            }
        }

        if (!found) {
            printf("System is in an unsafe state.\n");
            return -1;
        }
    }

    printf("Safe sequence is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", safe_sequence[i]);
    printf("\n");

    return 0;
}

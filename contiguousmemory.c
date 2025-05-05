#include <stdio.h>
#include <limits.h>

void memoryAllocation(int blocks[], int m, int processes[], int n, char* type) {
    int allocation[n];
    for (int i = 0; i < n; i++) allocation[i] = -1;

    for (int i = 0; i < n; i++) {
        int index = -1;

        for (int j = 0; j < m; j++) {
            if (blocks[j] >= processes[i]) {
                if ((strcmp(type, "First-fit") == 0) || 
                    (strcmp(type, "Best-fit") == 0 && (index == -1 || blocks[j] < blocks[index])) ||
                    (strcmp(type, "Worst-fit") == 0 && (index == -1 || blocks[j] > blocks[index]))) {
                    index = j;
                }
            }
        }

        if (index != -1) {
            allocation[i] = index;
            blocks[index] -= processes[i];
        }
    }

    printf("%s Allocation:\n", type);
    printf("Process\tSize\tBlock\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%s\n", i, processes[i], allocation[i] != -1 ? "Allocated" : "Not Allocated");
    }
    printf("\n");
}

int main() {
    int blocks[] = {100, 500, 200, 300, 600};
    int processes[] = {212, 417, 112, 426};
    int m = sizeof(blocks) / sizeof(blocks[0]);
    int n = sizeof(processes) / sizeof(processes[0]);

    int blocks1[m], blocks2[m], blocks3[m];
    for (int i = 0; i < m; i++) {
        blocks1[i] = blocks2[i] = blocks3[i] = blocks[i];
    }

    memoryAllocation(blocks1, m, processes, n, "First-fit");
    memoryAllocation(blocks2, m, processes, n, "Best-fit");
    memoryAllocation(blocks3, m, processes, n, "Worst-fit");

    return 0;
}

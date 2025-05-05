#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct {
    char name[10];
    int arrival_time, burst_time, waiting_time, turnaround_time;
} Process;

void display(Process p[], int n) {
    printf("\nName\tArrival\tBurst\tWaiting\tTurnaround\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t%d\t%d\n", p[i].name, p[i].arrival_time, p[i].burst_time, p[i].waiting_time, p[i].turnaround_time);
    }
}

void sort_by_arrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrival_time > p[j + 1].arrival_time) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void fcfs(Process p[], int n) {
    int total_waiting = 0, total_turnaround = 0;
    p[0].waiting_time = 0;
    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
    }
    for (int i = 0; i < n; i++) {
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_waiting += p[i].waiting_time;
        total_turnaround += p[i].turnaround_time;
    }
    display(p, n);
    printf("\nAverage Waiting Time: %.2f", (float)total_waiting / n);
    printf("\nAverage Turnaround Time: %.2f\n", (float)total_turnaround / n);
}

int main() {
    Process system_queue[MAX], user_queue[MAX];
    int sys_count = 0, user_count = 0, total_processes;

    printf("Enter total number of processes: ");
    scanf("%d", &total_processes);

    for (int i = 0; i < total_processes; i++) {
        Process p;
        printf("\nEnter process name: ");
        scanf("%s", p.name);
        printf("Enter arrival time: ");
        scanf("%d", &p.arrival_time);
        printf("Enter burst time: ");
    sort_by_arrival(system_queue, sys_count);
    fcfs(system_queue, sys_count);
        printf("Is this a system process (1) or user process (2)? ");
    sort_by_arrival(user_queue, user_count);
    fcfs(user_queue, user_count);
        scanf("%d", &type);
        if (type == 1) {
            system_queue[sys_count++] = p;
        } else {
            user_queue[user_count++] = p;
        }
    }

    printf("\nScheduling System Processes (Higher Priority):\n");
    fcfs(system_queue, sys_count);

    printf("\nScheduling User Processes:\n");
    fcfs(user_queue, user_count);

    return 0;
}

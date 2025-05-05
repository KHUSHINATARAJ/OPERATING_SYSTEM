#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5  // Number of philosophers

sem_t chopsticks[N];

void* philosopher(void* num) {
    int id = *(int*)num;

    printf("Philosopher %d is thinking...\n", id);
    sem_wait(&chopsticks[id]);
    sem_wait(&chopsticks[(id + 1) % N]);

    printf("Philosopher %d is eating...\n", id);
    sleep(2);

    sem_post(&chopsticks[id]);
    sem_post(&chopsticks[(id + 1) % N]);
    printf("Philosopher %d has finished eating.\n", id);

    return NULL;
}

int main() {
    pthread_t threads[N];
    int ids[N];

    for (int i = 0; i < N; i++) {
        sem_init(&chopsticks[i], 0, 1);
        ids[i] = i;
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&threads[i], NULL, philosopher, &ids[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < N; i++) {
        sem_destroy(&chopsticks[i]);
    }

    return 0;
}

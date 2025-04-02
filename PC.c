#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

sem_t empty; 
sem_t full;  
pthread_mutex_t mutex; 
int buffer[BUFFER_SIZE];
int in = 0, out = 0, x = 0;

void *producer(void *arg) {
    while (1) {
        sleep(1); 
        sem_wait(&empty); 
        pthread_mutex_lock(&mutex); 

        
        buffer[in] = ++x;
        printf("Producer has produced: Item %d\n", buffer[in]);
        in = (in + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); 
        sem_post(&full); 
    }
}

void *consumer(void *arg) {
    while (1) {
        sleep(2);
        sem_wait(&full);
        pthread_mutex_lock(&mutex); // Lock critical section

        // Consume item
        int item = buffer[out];
        printf("Consumer has consumed: Item %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        pthread_mutex_unlock(&mutex); // Unlock critical section
        sem_post(&empty); // Signal that buffer has an empty slot
    }
}

int main() {
    pthread_t prodThread, consThread;

    
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);
    pthread_mutex_init(&mutex, NULL);

   
    pthread_create(&prodThread, NULL, producer, NULL);
    pthread_create(&consThread, NULL, consumer, NULL);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    
    pthread_join(prodThread, NULL);
    pthread_join(consThread, NULL);

   
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}

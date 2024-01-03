#include "esotericFunMiscellaneous.h"

long int *sortedValues;
int currentIndex;
sem_t lock;
pthread_t *threads;
int LENGTH;

void interruptHandler(int signum) {
    for(int i = 0; i < LENGTH; i++)
        pthread_cancel(threads[i]);

    for(int i = 0; i < LENGTH; i++)
        pthread_join(threads[i], NULL);
    sem_destroy(&lock);
    free(threads);
    free(sortedValues);

    exit(signum);
}

void *sortingBucket(void *arg) {
    long int value = *((int *)arg);
    sleep(value);
    sem_wait(&lock);
    sortedValues[currentIndex++] = value;
    sem_post(&lock);
    pthread_exit(NULL);
}

void sleepSort(long int *arr, int len) {
    LENGTH = len;
    currentIndex ^= currentIndex;
    signal(SIGINT, interruptHandler);
    sortedValues = malloc(len * sizeof(long int));
    threads = malloc(len * sizeof(pthread_t));
    sem_init(&lock, 0, LENGTH);
    for(int i = 0; i < LENGTH; i++)
        pthread_create(&threads[i], NULL, sortingBucket, (void *)&(arr[i]));
    for(int i = 0; i < LENGTH; i++)
        pthread_join(threads[i], NULL);
    for(int i = 0; i < LENGTH; i++)
        arr[i] = sortedValues[i];
    sem_destroy(&lock);
    free(threads);
    free(sortedValues);
}


#include "esotericFunMiscellaneous.h"

#if defined unix || defined __unix || defined __unix__ || defined __APPLE__ || defined __MACH__ || defined __linux__
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
    long int value = *((long int *)arg);
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
#endif

#if defined _WIN32 || defined _WIN64 || defined __CYGWIN__
long int *sortedValues;
int currentIndex;
HANDLE *threads;
HANDLE lock;
int LENGTH;

void interruptHandler(int signum) {
    for(int i = 0; i < LENGTH; i++)
        TerminateThread(threads[i], 0);

    for(int i = 0; i < LENGTH; i++)
        CloseHandle(threads[i]);
    CloseHandle(lock);
    free(threads);
    free(sortedValues);

    ExitProcess(signum);
}

DWORD WINAPI sortingBucket(LPVOID arg) {
    long int value = *((long int *)arg);
    sleep(value);
    WaitForSingleObject(lock, INFINITE);
    sortedValues[currentIndex++] = value;
    ReleaseSemaphore(lock, 1, NULL);
    return 0;
}

void sleepSort(long int *arr, int len) {
    LENGTH = len;
    currentIndex ^= currentIndex;
    signal(SIGINT, interruptHandler);
    sortedValues = malloc(len * sizeof(long int));
    threads = malloc(len * sizeof(HANDLE));
    lock = CreateSemaphore(NULL, LENGTH, LENGTH, NULL);
    for(int i = 0; i < LENGTH; i++)
        threads[i] = CreateThread(NULL, 0, sortingBucket, (LPVOID)&(arr[i]), 0, NULL);
    WaitForMultipleObjects(LENGTH, threads, TRUE, INFINITE);
    for(int i = 0; i < LENGTH; i++)
        CloseHandle(threads[i]);
    for(int i = 0; i < LENGTH; i++)
        arr[i] = sortedValues[i];
    CloseHandle(lock);
    free(threads);
    free(sortedValues);
}
#endif
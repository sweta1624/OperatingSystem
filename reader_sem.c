//Readers Writer problem using POSIX Semaphore
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_READERS 5
#define NUM_WRITERS 2
int data = 0;
int readersCount = 0;
sem_t readersMutex;
sem_t writersMutex;
sem_t resourceAccess;
void* reader(void* arg)
{
 int readerId = (int)arg;
 while (1) {
 sem_wait(&readersMutex);
 readersCount++;
 if (readersCount == 1) {
 sem_wait(&resourceAccess);
 }
 sem_post(&readersMutex);
 // Reading data
 printf("Reader %d reads data: %d\n", readerId, data);
 sem_wait(&readersMutex);
 readersCount--;
 if (readersCount == 0) {
 sem_post(&resourceAccess);
 }
 sem_post(&readersMutex);
 usleep((rand() % 1000) * 1000);
 }
 pthread_exit(NULL);
}
void* writer(void* arg)
{
 int writerId = (int)arg;
 while (1) {
 sem_wait(&writersMutex);
 sem_wait(&resourceAccess);
 // Writing data
 data++;
 printf("Writer %d writes data: %d\n", writerId, data);
 sem_post(&resourceAccess);
 sem_post(&writersMutex);
 
 usleep((rand() % 1000) * 1000);
 }
 pthread_exit(NULL);
}
int main()
{
 int i;
 pthread_t readers[NUM_READERS];
 pthread_t writers[NUM_WRITERS];
 int readerIds[NUM_READERS];
 int writerIds[NUM_WRITERS];
 // Initialize semaphores
 sem_init(&readersMutex, 0, 1);
 sem_init(&writersMutex, 0, 1);
 sem_init(&resourceAccess, 0, 1);
 // Create reader threads
 for (i = 0; i < NUM_READERS; i++) {
 readerIds[i] = i + 1;
 pthread_create(&readers[i], NULL, reader, &readerIds[i]);
 }
 // Create writer threads
 for (i = 0; i < NUM_WRITERS; i++) {
 writerIds[i] = i + 1;
 pthread_create(&writers[i], NULL, writer, &writerIds[i]);
 }
 // Wait for reader threads to finish
 for (i = 0; i < NUM_READERS; i++) {
 pthread_join(readers[i], NULL);
 }
 // Wait for writer threads to finish
 for (i = 0; i < NUM_WRITERS; i++) {
 pthread_join(writers[i], NULL);
 }
 // Clean up 
 sem_destroy(&readersMutex);
 sem_destroy(&writersMutex);
 sem_destroy(&resourceAccess);
 return 0;
}

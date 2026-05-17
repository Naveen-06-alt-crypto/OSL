#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int b = 20;
int readcount = 0;

sem_t mutex, wrt;

void *writer(void *arg)
{
    int val = *(int*)arg;

    sem_wait(&wrt);

    printf("Writer: Updating value to %d\n", val);
    b = val;

    sleep(1);

    sem_post(&wrt);
    return NULL;
}

void *reader(void *arg)
{
    int id = *(int*)arg;

    sem_wait(&mutex);
    readcount++;

    if(readcount == 1)
        sem_wait(&wrt);

    sem_post(&mutex);

    printf("Reader %d: Reading value = %d\n", id, b);
    sleep(1);

    sem_wait(&mutex);
    readcount--;

    if(readcount == 0)
        sem_post(&wrt);

    sem_post(&mutex);

    return NULL;
}

int main()
{
    pthread_t w1, w2, r1, r2;

    int wv1, wv2;
    int r1_id = 1, r2_id = 2;

    // ✅ user input here (safe)
    printf("Enter value for Writer 1: ");
    scanf("%d", &wv1);

    printf("Enter value for Writer 2: ");
    scanf("%d", &wv2);

    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    pthread_create(&w1, NULL, writer, &wv1);
    pthread_create(&r1, NULL, reader, &r1_id);
    pthread_create(&r2, NULL, reader, &r2_id);
    pthread_create(&w2, NULL, writer, &wv2);

    pthread_join(w1, NULL);
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}

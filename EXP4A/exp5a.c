#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define SHMSZ 27

int main()
{
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    if((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
    {
        printf("Cannot Allocate Shared Memory\n");
        exit(1);
    }

    if((shm = shmat(shmid, NULL, 0)) == (char *) -1)
    {
        printf("Cannot Attach Shared Memory\n");
        exit(1);
    }

    s = shm;

    for(char c = 'a'; c <= 'z'; c++)
    {
        *s++ = c;
    }
    *s = '\0';

    // wait for reader
    while(*shm != '*')
        sleep(1);

    return 0;
}

#include <stdio.h>
#include <string.h>

#define DISK 15

// Disk blocks
int disk[DISK];

// Pointer array
int next[DISK];

// File structure
struct File
{
    char name[20];

    int start;
};

struct File f[5];

int fc = 0;

// Find free block
int freeBlock()
{
    for(int i = 0; i < DISK; i++)
    {
        if(disk[i] == 0)
        {
            disk[i] = 1;

            return i;
        }
    }

    return -1;
}

// Allocate linked blocks
void allocate(char name[], int count)
{
    int first = -1;

    int prev = -1;

    for(int i = 0; i < count; i++)
    {
        int b = freeBlock();

        next[b] = -1;

        // Link blocks
        if(prev != -1)
        {
            next[prev] = b;
        }
        else
        {
            first = b;
        }

        prev = b;
    }

    // Store file info
    strcpy(f[fc].name, name);

    f[fc].start = first;

    fc++;
}

int main()
{
    // Initialize disk
    memset(disk, 0, sizeof(disk));

    // Allocate files
    allocate("FileA", 3);

    allocate("FileB", 4);

    // Display linked allocation
    for(int i = 0; i < fc; i++)
    {
        printf("%s : ", f[i].name);

        int cur = f[i].start;

        while(cur != -1)
        {
            printf("%d -> ", cur);

            cur = next[cur];
        }

        printf("NULL\n");
    }

    return 0;
}

#include <stdio.h>
#include <string.h>

#define DISK 20

// Disk blocks
int disk[DISK];

// File structure
struct File
{
    char name[20];

    int idx;       // Index block

    int data[10];  // Data blocks

    int count;     // Number of blocks
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

// Allocate indexed file
void allocate(char name[], int blocks)
{
    struct File *t = &f[fc];

    strcpy(t->name, name);

    // Allocate index block
    t->idx = freeBlock();

    // Allocate data blocks
    for(int i = 0; i < blocks; i++)
    {
        t->data[i] = freeBlock();
    }

    t->count = blocks;

    fc++;
}

int main()
{
    // Initialize disk
    memset(disk, 0, sizeof(disk));

    // Allocate files
    allocate("FileA", 3);

    allocate("FileB", 4);

    // Display allocation
    for(int i = 0; i < fc; i++)
    {
        printf("%s Index = %d Blocks: ",
               f[i].name,
               f[i].idx);

        for(int j = 0; j < f[i].count; j++)
        {
            printf("%d ",
                   f[i].data[j]);
        }

        printf("\n");
    }

    return 0;
}

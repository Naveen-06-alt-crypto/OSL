#include <stdio.h>
#include <string.h>

#define DISK 20

// Disk blocks
int disk[DISK];

// File structure
struct File
{
    char name[20];

    int start;

    int len;
};

// File table
struct File table[10];

int tc = 0;

// Allocate contiguous blocks
int allocate(char name[], int len)
{
    int start = -1;

    int count = 0;

    for(int i = 0; i < DISK; i++)
    {
        // Free block
        if(disk[i] == 0)
        {
            if(count == 0)
            {
                start = i;
            }

            count++;
        }
        else
        {
            count = 0;
        }

        // Enough contiguous blocks found
        if(count == len)
        {
            // Allocate blocks
            for(int j = start;
                j < start + len;
                j++)
            {
                disk[j] = 1;
            }

            // Store file details
            strcpy(table[tc].name, name);

            table[tc].start = start;

            table[tc].len = len;

            tc++;

            return start;
        }
    }

    return -1;
}

int main()
{
    // Initially disk empty
    memset(disk, 0, sizeof(disk));

    // Allocate files
    allocate("FileA", 4);

    allocate("FileB", 3);

    allocate("FileC", 5);

    // Display allocation table
    for(int i = 0; i < tc; i++)
    {
        printf("%s : Start = %d Length = %d\n",
               table[i].name,
               table[i].start,
               table[i].len);
    }

    return 0;
}

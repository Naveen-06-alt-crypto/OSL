#include <stdio.h>

int main()
{
    // Memory blocks
    int blockSize[5] = {100, 500, 200, 300, 600};

    // Processes
    int processSize[4] = {212, 417, 112, 426};

    int allocation[4];

    // Initially no process is allocated
    for(int i = 0; i < 4; i++)
    {
        allocation[i] = -1;
    }

    // First Fit Allocation
    for(int i = 0; i < 4; i++)   // Process loop
    {
        for(int j = 0; j < 5; j++)   // Block loop
        {
            // Check if block can hold process
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j + 1;

                // Reduce remaining memory
                blockSize[j] = blockSize[j] - processSize[i];

                break;
            }
        }
    }

    // Display Result
    printf("Process No\tProcess Size\tBlock No\n");

    for(int i = 0; i < 4; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
        {
            printf("%d\n", allocation[i]);
        }
        else
        {
            printf("Not Allocated\n");
        }
    }

    return 0;
}

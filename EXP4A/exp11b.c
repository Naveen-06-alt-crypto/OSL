#include <stdio.h>

int main()
{
    // Memory blocks
    int blockSize[5] = {100, 500, 200, 300, 600};

    // Processes
    int processSize[4] = {212, 417, 112, 426};

    int allocation[4];

    // Initially no allocation
    for(int i = 0; i < 4; i++)
    {
        allocation[i] = -1;
    }

    // Best Fit Allocation
    for(int i = 0; i < 4; i++)
    {
        int bestIdx = -1;

        for(int j = 0; j < 5; j++)
        {
            // Check block is enough
            if(blockSize[j] >= processSize[i])
            {
                // Select smallest suitable block
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                {
                    bestIdx = j;
                }
            }
        }

        // Allocate memory
        if(bestIdx != -1)
        {
            allocation[i] = bestIdx + 1;

            // Reduce remaining memory
            blockSize[bestIdx] =
                blockSize[bestIdx] - processSize[i];
        }
    }

    // Display output
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

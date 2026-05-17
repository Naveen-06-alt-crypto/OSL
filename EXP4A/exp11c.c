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

    // Worst Fit Allocation
    for(int i = 0; i < 4; i++)
    {
        int worstIdx = -1;

        for(int j = 0; j < 5; j++)
        {
            // Check block is enough
            if(blockSize[j] >= processSize[i])
            {
                // Select largest suitable block
                if(worstIdx == -1 ||
                   blockSize[j] > blockSize[worstIdx])
                {
                    worstIdx = j;
                }
            }
        }

        // Allocate memory
        if(worstIdx != -1)
        {
            allocation[i] = worstIdx + 1;

            // Reduce remaining memory
            blockSize[worstIdx] =
                blockSize[worstIdx] - processSize[i];
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

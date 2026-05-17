#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Disk request queue
    int queue[7] = {82, 170, 43, 140, 24, 16, 190};

    int head = 50;
    int total = 0;

    printf("FCFS Disk Scheduling\n");

    printf("Initial Head Position: %d\n", head);

    printf("\nSequence\tSeek Distance\n");

    // Process requests one by one
    for(int i = 0; i < 7; i++)
    {
        // Calculate seek distance
        int dist = abs(queue[i] - head);

        total = total + dist;

        printf("%d -> %d\t\t%d\n",
               head, queue[i], dist);

        // Move head
        head = queue[i];
    }

    // Final result
    printf("\nTotal Seek Distance = %d\n", total);

    printf("Average Seek Distance = %.2f\n",
           (float)total / 7);

    return 0;
}

#include <stdio.h>

#define NF 3

int main()
{
    // Page reference string
    int ref[13] = {7,0,1,2,0,3,0,4,2,3,0,3,2};

    int frames[NF];
    int time[NF];

    int faults = 0;
    int t = 0;

    // Initialize frames
    for(int i = 0; i < NF; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("Page\tFrames\n");

    // Traverse pages
    for(int i = 0; i < 13; i++, t++)
    {
        int found = -1;

        // Check page exists
        for(int j = 0; j < NF; j++)
        {
            if(frames[j] == ref[i])
            {
                found = j;
                break;
            }
        }

        // Page Fault
        if(found == -1)
        {
            int lru = 0;

            // Find least recently used page
            for(int j = 1; j < NF; j++)
            {
                if(time[j] < time[lru])
                {
                    lru = j;
                }
            }

            // Replace page
            frames[lru] = ref[i];

            // Update time
            time[lru] = t;

            faults++;
        }
        else
        {
            // Update recently used time
            time[found] = t;
        }

        // Display frames
        printf("%d\t", ref[i]);

        for(int j = 0; j < NF; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if(found == -1)
            printf("Page Fault");

        printf("\n");
    }

    // Final output
    printf("\nTotal Page Faults = %d\n", faults);

    printf("Hit Ratio = %.2f\n",
           (float)(13 - faults) / 13);

    return 0;
}

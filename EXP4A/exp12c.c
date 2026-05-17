#include <stdio.h>

int main()
{
    // Reference string
    int ref[13] = {7,0,1,2,0,3,0,4,2,3,0,3,2};

    // Frames
    int frames[3];

    int faults = 0;

    // Initialize frames
    for(int i = 0; i < 3; i++)
    {
        frames[i] = -1;
    }

    printf("Page\tFrames\n");

    // Traverse pages
    for(int i = 0; i < 13; i++)
    {
        int found = 0;

        // Check page already exists
        for(int j = 0; j < 3; j++)
        {
            if(frames[j] == ref[i])
            {
                found = 1;
                break;
            }
        }

        // If page fault occurs
        if(found == 0)
        {
            int pos = -1;
            int farthest = i;

            // Find optimal page to replace
            for(int j = 0; j < 3; j++)
            {
                int k;

                // Check future usage
                for(k = i + 1; k < 13; k++)
                {
                    if(frames[j] == ref[k])
                    {
                        break;
                    }
                }

                // Page never used again
                if(k == 13)
                {
                    pos = j;
                    break;
                }

                // Select farthest future use
                if(k > farthest)
                {
                    farthest = k;
                    pos = j;
                }
            }

            // Default replacement
            if(pos == -1)
            {
                pos = 0;
            }

            // Replace page
            frames[pos] = ref[i];

            faults++;
        }

        // Display frames
        printf("%d\t", ref[i]);

        for(int j = 0; j < 3; j++)
        {
            if(frames[j] == -1)
                printf("- ");
            else
                printf("%d ", frames[j]);
        }

        if(found == 0)
            printf("Page Fault");

        printf("\n");
    }

    // Final result
    printf("\nTotal Page Faults = %d\n", faults);

    printf("Hit Ratio = %.2f\n",
           (float)(13 - faults) / 13);

    return 0;
}

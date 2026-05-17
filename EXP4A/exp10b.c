#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of segments: ");
    scanf("%d",&n);

    int base[n], limit[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter base of segment %d: ",i);
        scanf("%d",&base[i]);

        printf("Enter limit of segment %d: ",i);
        scanf("%d",&limit[i]);
    }

    while(1)
    {
        int segment, offset;

        printf("\nEnter segment: ");
        scanf("%d",&segment);

        printf("Enter offset: ");
        scanf("%d",&offset);

        // segment validation
        if(segment >= n)
        {
            printf("Invalid segment number\n");
            continue;
        }

        // offset validation
        if(offset < limit[segment])
        {
            int pa = base[segment] + offset;
            printf("Physical Address = %d\n", pa);
        }
        else
        {
            printf("Illegal Address\n");
        }
    }

    return 0;
}

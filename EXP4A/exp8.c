#include <stdio.h>

int alloc[10][10];
int request[10][10];
int avail[10];
int work[10];
int finish[10];

int n, r;

void read()
{
    int i, j;

    printf("Number of Processes: ");
    scanf("%d", &n);

    printf("Number of Resources: ");
    scanf("%d", &r);

    printf("Enter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &request[i][j]);

    printf("Enter Available Resources:\n");
    for (j = 0; j < r; j++)
        scanf("%d", &avail[j]);
}

void detect()
{
    int i, j, k, flag;

    for (j = 0; j < r; j++)
        work[j] = avail[j];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    while (1)
    {
        flag = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int possible = 1;

                for (j = 0; j < r; j++)
                {
                    if (request[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if (possible)
                {
                    for (k = 0; k < r; k++)
                        work[k] += alloc[i][k];

                    finish[i] = 1;
                    flag = 1;
                }
            }
        }

        if (flag == 0)
            break;
    }

    int deadlock = 0;

    printf("\nDeadlocked Processes: ");
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
        }
    }

    if (!deadlock)
        printf("None (No Deadlock)");

    printf("\n");
}

int main()
{
    read();
    detect();
    return 0;
}

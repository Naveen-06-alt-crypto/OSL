#include <stdio.h>

int max[10][10], alloc[10][10], need[10][10];
int avail[10], work[10], finish[10];
int n, r = 3;

void read()
{
    int i, j;
    printf("Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Allocation Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&alloc[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            scanf("%d",&max[i][j]);

    printf("Enter Available Resources:\n");
    for(j=0;j<r;j++)
        scanf("%d",&avail[j]);

    for(i=0;i<n;i++)
        for(j=0;j<r;j++)
            need[i][j]=max[i][j]-alloc[i][j];
}

void print()
{
    int i,j;

    printf("\nNeed Matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<r;j++)
            printf("%d ",need[i][j]);
        printf("\n");
    }

    printf("\nAvailable:\n");
    for(j=0;j<r;j++)
        printf("%d ",avail[j]);
    printf("\n");
}

int safety()
{
    int i,j,k,count=0,flag;
    int safe[10];

    for(j=0;j<r;j++)
        work[j]=avail[j];

    for(i=0;i<n;i++)
        finish[i]=0;

    while(count<n)
    {
        flag=0;

        for(i=0;i<n;i++)
        {
            if(finish[i]==0 &&
               need[i][0]<=work[0] &&
               need[i][1]<=work[1] &&
               need[i][2]<=work[2])
            {
                for(k=0;k<r;k++)
                    work[k]+=alloc[i][k];

                safe[count++]=i;
                finish[i]=1;
                flag=1;
            }
        }

        if(flag==0)
            break;
    }

    if(count==n)
    {
        printf("\nSafe Sequence: ");
        for(i=0;i<n;i++)
            printf("P%d ",safe[i]);

        printf("\nSystem is in SAFE state\n");
        return 1;
    }
    else
    {
        printf("\nSystem is in UNSAFE state\n");
        return 0;
    }
}

void resource()
{
    int p,i,y;
    int req[10];

    printf("\nEnter process number: ");
    scanf("%d",&p);

    printf("Enter request: ");
    for(i=0;i<r;i++)
        scanf("%d",&req[i]);

    for(i=0;i<r;i++)
    {
        if(req[i]>need[p][i])
        {
            printf("Request exceeds need\n");
            return;
        }

        if(req[i]>avail[i])
        {
            printf("Resources not available\n");
            return;
        }
    }

    // allocate temporarily
    for(i=0;i<r;i++)
    {
        avail[i]-=req[i];
        alloc[p][i]+=req[i];
        need[p][i]-=req[i];
    }

    y=safety();

    if(!y)
    {
        // rollback
        for(i=0;i<r;i++)
        {
            avail[i]+=req[i];
            alloc[p][i]-=req[i];
            need[p][i]+=req[i];
        }
        printf("Request denied\n");
    }
    else
    {
        printf("Request granted\n");
        print();
    }
}

int main()
{
    read();
    print();

    if(safety())
        resource();
    else
        printf("System not safe. Request denied\n");

    return 0;
}

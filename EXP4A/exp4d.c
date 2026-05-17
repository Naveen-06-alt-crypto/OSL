#include<stdio.h>

int main()
{
    int n,tq,time=0,front=0,rear=0,co=0;
    scanf("%d %d",&n,&tq);

    int At[n],Bt[n],Rt[n],Ft[n],Tat[n],Wt[n];
    int visited[n],queue[100];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&At[i],&Bt[i]);
        Rt[i]=Bt[i];
        visited[i]=0;
    }

    for(int i=0;i<n;i++)
    {
        if(At[i]<=time)
        {
            queue[rear++]=i;
            visited[i]=1;
        }
    }

    while(co<n)
    {
        if(front==rear)
        {
            time++;
            continue;
        }

        int i=queue[front++];

        if(Rt[i]>tq)
        {
            time+=tq;
            Rt[i]-=tq;
        }
        else
        {
            time+=Rt[i];
            Rt[i]=0;

            Ft[i]=time;
            Tat[i]=Ft[i]-At[i];
            Wt[i]=Tat[i]-Bt[i];
            co++;
        }

        for(int j=0;j<n;j++)
        {
            if(At[j]<=time && visited[j]==0)
            {
                queue[rear++]=j;
                visited[j]=1;
            }
        }

        if(Rt[i]>0)
            queue[rear++]=i;
    }

    float avg_tat=0, avg_wt=0;

    printf("\nAT\tBT\tFT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",
        At[i],Bt[i],Ft[i],Tat[i],Wt[i]);

        avg_tat+=Tat[i];
        avg_wt+=Wt[i];
    }

    printf("\nAverage TAT=%.2f",avg_tat/n);
    printf("\nAverage WT=%.2f",avg_wt/n);
}

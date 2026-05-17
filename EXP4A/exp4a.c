#include<stdio.h>

int main()
{
    int n,time=0;
    printf("Enter no of processes: ");
    scanf("%d",&n);

    int At[n],Bt[n],Ft[n],Tat[n],Wt[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter AT and BT: ");
        scanf("%d %d",&At[i],&Bt[i]);
    }

    for(int i=0;i<n;i++)
    {
        if(time < At[i])
            time = At[i];

        Ft[i]=time+Bt[i];
        Tat[i]=Ft[i]-At[i];
        Wt[i]=Tat[i]-Bt[i];

        time=Ft[i];
    }

    float avg_tat=0, avg_wt=0;

    printf("\nAT\tBT\tFT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",At[i],Bt[i],Ft[i],Tat[i],Wt[i]);
        avg_tat += Tat[i];
        avg_wt += Wt[i];
    }

    avg_tat/=n;
    avg_wt/=n;

    printf("\nAverage TAT = %.2f",avg_tat);
    printf("\nAverage WT = %.2f",avg_wt);
}

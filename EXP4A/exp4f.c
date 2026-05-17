#include<stdio.h>

int main()
{
    int n,time=0,co=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int At[n],Bt[n],Pr[n],Rt[n],Ft[n],Tat[n],Wt[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter AT, BT, Priority: ");
        scanf("%d %d %d",&At[i],&Bt[i],&Pr[i]);
        Rt[i]=Bt[i];
    }

    while(co<n)
    {
        int bp=-1;
        int mp=9999;

        for(int i=0;i<n;i++)
        {
            if(At[i]<=time && Rt[i]>0)
            {
                if(Pr[i] < mp)
                {
                    mp = Pr[i];
                    bp = i;
                }
            }
        }

        if(bp==-1)
        {
            time++;
            continue;
        }

        Rt[bp]--;
        time++;

        if(Rt[bp]==0)
        {
            Ft[bp]=time;
            Tat[bp]=Ft[bp]-At[bp];
            Wt[bp]=Tat[bp]-Bt[bp];
            co++;
        }
    }

    float avg_tat=0, avg_wt=0;

    printf("\nAT\tBT\tPri\tFT\tTAT\tWT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        At[i],Bt[i],Pr[i],Ft[i],Tat[i],Wt[i]);

        avg_tat+=Tat[i];
        avg_wt+=Wt[i];
    }

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("Average WT = %.2f\n",avg_wt/n);

    return 0;
}

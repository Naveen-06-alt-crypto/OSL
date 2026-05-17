#include<stdio.h>

int main()
{
    int n,time=0,co=0;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int At[n],Bt[n],Rt[n],Ft[n],Tat[n],Wt[n];

    for(int i=0;i<n;i++)
    {
        printf("Enter AT and BT: ");
        scanf("%d %d",&At[i],&Bt[i]);
        Rt[i]=Bt[i];
    }

    while(co<n)
    {
        int sji=-1;
        int smrt=9999;

        for(int i=0;i<n;i++)
        {
            if(At[i]<=time && Rt[i]>0 && Rt[i]<smrt)
            {
                smrt=Rt[i];
                sji=i;
            }
        }

        if(sji==-1)
        {
            time++;
            continue;
        }

        Rt[sji]--;
        time++;

        if(Rt[sji]==0)
        {
            Ft[sji]=time;
            Tat[sji]=Ft[sji]-At[sji];
            Wt[sji]=Tat[sji]-Bt[sji];
            co++;
        }
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

    printf("\nAverage TAT = %.2f",avg_tat/n);
    printf("Average WT = %.2f\n",avg_wt/n);

    return 0;
}

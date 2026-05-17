#include<stdio.h>

int main()
{
    int n,time=0,co=0;
    printf("Enter n: ");
    scanf("%d",&n);

    int At[n],Bt[n],Ft[n],Tat[n],Wt[n],Pst[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&At[i],&Bt[i]);
        Pst[i]=0;
    }

    while(co<n)
    {
        int sji=-1,smbt=999;

        for(int i=0;i<n;i++)
        {
            if(Pst[i]==0 && At[i]<=time && Bt[i]<smbt)
            {
                smbt=Bt[i];
                sji=i;
            }
        }

        if(sji==-1){ time++; continue; }

        Ft[sji]=time+Bt[sji];
        Tat[sji]=Ft[sji]-At[sji];
        Wt[sji]=Tat[sji]-Bt[sji];

        time=Ft[sji];
        Pst[sji]=1;
        co++;
    }

    float avg_tat=0, avg_wt=0;

    printf("\nAT\tBT\tFT\tTAT\tWT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\n",At[i],Bt[i],Ft[i],Tat[i],Wt[i]);
        avg_tat+=Tat[i];
        avg_wt+=Wt[i];
    }

    printf("\nAverage TAT=%.2f",avg_tat/n);
    printf("\nAverage WT=%.2f",avg_wt/n);
}

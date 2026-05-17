#include<stdio.h>

int main()
{
    int n,time=0,co=0;
    printf("Enter n: ");
    scanf("%d",&n);

    int At[n],Bt[n],Pr[n],Ft[n],Tat[n],Wt[n],comp[n];

    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&At[i],&Bt[i],&Pr[i]);
        comp[i]=0;
    }

    while(co<n)
    {
        int bp=-1,mp=999;

        for(int i=0;i<n;i++)
        {
            if(comp[i]==0 && At[i]<=time && Pr[i]<mp)
            {
                mp=Pr[i];
                bp=i;
            }
        }

        if(bp==-1){ time++; continue; }

        Ft[bp]=time+Bt[bp];
        Tat[bp]=Ft[bp]-At[bp];
        Wt[bp]=Tat[bp]-Bt[bp];

        time=Ft[bp];
        comp[bp]=1;
        co++;
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

    printf("\nAverage TAT=%.2f",avg_tat/n);
    printf("\nAverage WT=%.2f",avg_wt/n);
}

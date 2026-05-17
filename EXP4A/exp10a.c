#include<stdio.h>

int main()
{
    int LA;
    int process_size, page_size;

    printf("Enter process size and page size: ");
    scanf("%d%d",&process_size,&page_size);

    int noofpage = (process_size + page_size - 1) / page_size;

    printf("No of pages: %d\n",noofpage);

    printf("Enter Logical Address: ");
    scanf("%d",&LA);

    int pno = LA / page_size;
    int offset = LA % page_size;

    if(pno >= noofpage)
    {
        printf("Invalid Logical Address\n");
        return 0;
    }

    int pagetable[100];

    for(int i=0;i<noofpage;i++)
    {
        printf("Enter frame number for page %d: ",i);
        scanf("%d",&pagetable[i]);
    }

    int PA = (pagetable[pno] * page_size) + offset;

    printf("Page Number = %d\n",pno);
    printf("Offset = %d\n",offset);
    printf("Physical Address = %d\n",PA);

    return 0;
}

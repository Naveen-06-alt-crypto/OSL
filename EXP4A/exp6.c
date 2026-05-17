#include<stdio.h>

int mutex=1, full=0, empty, choice, x=0, count=0, n;

int wait(int s)
{
    while(s <= 0);   // busy wait
    return --s;
}

int signal(int s)
{
    return ++s;
}

void Producer(int c)
{
    empty = wait(empty);
    mutex = wait(mutex);

    printf("Producer produces item-%d\n", c);

    mutex = signal(mutex);
    full = signal(full);
}

void Consumer(int c)
{
    full = wait(full);
    mutex = wait(mutex);

    printf("Consumer consumes item-%d\n", c);

    mutex = signal(mutex);
    empty = signal(empty);
}

int main()
{
    printf("Enter size of buffer: ");
    scanf("%d",&n);

    empty = n;

    while(x==0)
    {
        printf("\n1. Producer");
        printf("\n2. Consumer");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(count < n)
                {
                    count++;
                    Producer(count);
                }
                else
                {
                    printf("Buffer is full\n");
                }
                break;

            case 2:
                if(count > 0)
                {
                    Consumer(count);
                    count--;
                }
                else
                {
                    printf("Buffer is empty\n");
                }
                break;

            case 3:
                x = 1;
                break;
        }
    }
    return 0;
}

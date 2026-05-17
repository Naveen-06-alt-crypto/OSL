#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid;
    char buff[2][20] = {"hi", "hello"};
    char buff1[20];
    int p[2];

    pipe(p);

    pid = fork();

    if(pid > 0)   // parent
    {
        close(p[0]); // close read end
        write(p[1], buff[0], 20);
    }
    else          // child
    {
        close(p[1]); // close write end
        read(p[0], buff1, 20);
        printf("%s\n", buff1);
    }

    return 0;
}

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int fd1 = 0, fd2 = 0, fd3 = 0;

    fd1 = open("PPA.txt",O_RDONLY);
    printf("fd1 : %d\n",fd1);       // 3

    fd2 = open("LB.txt",O_RDONLY);
    printf("fd2 : %d\n",fd2);       // 4

    fd3 = open("Demo.txt",O_RDONLY);
    printf("fd3 : %d\n",fd3);       // 5

    return 0;
}
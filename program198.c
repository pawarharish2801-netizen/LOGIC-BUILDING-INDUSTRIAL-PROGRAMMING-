#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>

int main()
{
    unlink("PPA.txt");

    return 0;
}
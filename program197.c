#include<stdio.h>
#include<fcntl.h>

int main()
{
    int fd = 0;

    fd = creat("PPA.txt",0777);

    if(fd == -1)
    {
        printf("Unable to create file\n");
    }
    else
    {
        printf("File succesfully created with fd : %d\n",fd);
    }

    return 0;
}
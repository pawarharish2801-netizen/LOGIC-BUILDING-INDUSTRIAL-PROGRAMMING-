#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    int iRet = 0;

    fd = open("January.txt",O_RDWR | O_CREAT, 0777);

    if(fd == -1)
    {
        printf("Unable to open file\n");
    }
    else
    {
        printf("File gets succesfully opened with fd : %d\n",fd);
        
        iRet = write(fd,"Jay Ganesh",3);
        
        printf("%d bytes gets succesfully written into the file\n",iRet);

        close(fd);
    }

    return 0;
}
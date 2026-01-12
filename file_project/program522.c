#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd = 0, iRet = 0;
    char Fname[100] = {'\0'};
    char Buffer[100] = {'\0'};

    printf("Enter the name of file : \n");
    scanf("%s",Fname);

    fd = open(Fname,O_RDWR);

    if(fd != -1)
    {
        printf("File succesfully opned\n");

        printf("Data form file is : \n");
        
        while((iRet = read(fd,Buffer,sizeof(Buffer))) != 0)
        {
            // write(1,Buffer,iRet);   
            printf("iRet is : %d\n",iRet);   
        }
        
        printf("\n");

        close(fd);
    }
    else
    {
        printf("There is no such file\n");
    }

    return 0;
}
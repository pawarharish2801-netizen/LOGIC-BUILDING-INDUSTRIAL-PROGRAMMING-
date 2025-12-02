#include<stdio.h>

void CountSpace(char str[])
{
    int iCount = 0;

    while(*str != '\0')
    {
        if(*str == ' ')
        {
            iCount++;
        }
        str++;
    }

    printf("Number of spaces : %d\n",iCount);
}

int main()
{
    char Arr[50] = {'\0'};

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);
    
    CountSpace(Arr);
    
    return 0;
}
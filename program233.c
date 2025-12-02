#include<stdio.h>

void CountDigits(char str[])
{
    int iCount = 0;

    while(*str != '\0')
    {
        if((*str >= '0') && (*str <= '9'))
        {
            iCount++;
        }
        str++;
    }

    printf("Number of digits : %d\n",iCount);
}

int main()
{
    char Arr[50] = {'\0'};

    printf("Enter string : \n");
    scanf("%[^'\n']s",Arr);
    
    CountDigits(Arr);
    
    return 0;
}
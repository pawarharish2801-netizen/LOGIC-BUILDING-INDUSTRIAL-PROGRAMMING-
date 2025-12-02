#include<stdio.h>

void strcatX(char *src, char *dest)
{
    while(*dest != '\0')
    {
        dest++;
    }

    while(*src != '\0')
    {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';   // *dest = *src;
}

int main()
{
    char Arr[50] = {'\0'};
    char Brr[50] = {'\0'};

    printf("Enter source string : \n");
    scanf("%[^'\n']s",Arr);

    printf("Enter destination string : \n");
    scanf(" %[^'\n']s",Brr);

    strcatX(Arr,Brr);

    printf("Updated string is : %s\n",Brr);

    return 0;
}
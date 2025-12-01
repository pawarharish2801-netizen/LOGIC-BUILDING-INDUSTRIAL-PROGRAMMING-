#include<stdio.h>

int main()
{
    int iNo = 7236;
    int iDigit = 0;

    iDigit = iNo % 10;
    printf("iDigit is : %d\n",iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n",iNo);

    iDigit = iNo % 10;
    printf("iDigit is : %d\n",iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n",iNo);

    iDigit = iNo % 10;
    printf("iDigit is : %d\n",iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n",iNo);

    iDigit = iNo % 10;
    printf("iDigit is : %d\n",iDigit);
    iNo = iNo / 10;
    printf("iNo is : %d\n",iNo);

    return 0;
}
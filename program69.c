// iteration

#include<stdio.h>

int CountDigits(int iNo)
{
    int iCount = 0;

    while(iNo != 0) // 721
    {
        iNo = iNo / 10;
        iCount++;
    }    

    return iCount;
}

int main()
{
    int iValue = 0, iRet = 0;

    printf("Enter number : \n");
    scanf("%d",&iValue);
    
    iRet = CountDigits(iValue);
    
    printf("Number of digits are : %d\n",iRet);
    
    return 0;
}
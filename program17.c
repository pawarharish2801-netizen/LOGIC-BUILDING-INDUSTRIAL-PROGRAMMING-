#include <stdio.h>
#include <stdbool.h>

bool CheckEvenOdd(int iNo)
{
    return  (iNo % 2 == 0 );   
}

int main()
{
    int iValue =0;
    bool bRet = false;

    printf(" Enter number : \n");
    scanf("%d",&iValue);
    
    bRet = CheckEvenOdd(iValue);
    if(bRet == true)
    {
        printf("%d is even no",iValue);
    }
    else
    {
        printf("%d is odd no",iValue);
    }
    return 0;
}
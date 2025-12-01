// Input : 12   2       Ouput : true
// Input : 12   3       Ouput : true
// Input : 12   5       Ouput : false
// Input : 12   12      Ouput : true
// Input : 12   7       Ouput : flase

#include<stdio.h>

int main()
{
    int iValue1 = 0, iValue2 = 0;

    printf("Enter first number : \n");
    scanf("%d",&iValue1);

    printf("Enter second number : \n");
    scanf("%d",&iValue2);

    if((iValue1 % iValue2) == 0)
    {
        printf("It is completely devisible\n");
    }    
    else
    {
        printf("It is not divisible\n");
    }

    return 0;
}
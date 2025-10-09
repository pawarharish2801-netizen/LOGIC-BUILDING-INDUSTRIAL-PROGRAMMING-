    #include <stdio.h>

    int AdditionTwoNumbers(int iNo1, int iNo2)
    {
        int iSum = 0;
        iSum = iNo1 + iNo2 ; //BUSINESS LOGIC
        return iSum;
    }

    int main()
    {
        int iValue1=0, iValue2=0, iRet = 0;
        printf("Enter first no : \n");
        scanf("%d",&iValue1);

        printf("Enter second no : \n");
        scanf("%d",&iValue2);

        iRet = AdditionTwoNumbers(iValue1,iValue2) ; //The variable that catches return value = iRet
    
        printf("Addition is : %d\n",iRet);
    
        return 0;
    }

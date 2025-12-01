#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int * IPTR; 

// O(n)
bool LinearSearch(int Arr[] , int iSize , int iNo)
{
    int iCnt = 0 , iCount = 0 ;
   

    for(iCnt = 0 ; iCnt <iSize ; iCnt++)
    {
        if(Arr[iCnt] == iNo )
        {
            iCount++;
        }
    }
    if(iCount> 0)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

int main()
{
    int iCnt = 0 , iLength = 0 , iValue = 0;
    bool bRet = false;
    IPTR iPtr = NULL ;

    printf("Enter the number of Elements : ");
    scanf("%d",&iLength);

    //Step 1 : Allocate the memory
    iPtr = (IPTR)malloc(iLength * sizeof(int));

    if(NULL == iPtr)
    {
        printf("Unable to allocate Memory");
        return -1;
    }
    
    printf("Enter the Values : \n");  //time complexity = O(n)
    for(iCnt = 0 ; iCnt<iLength ; iCnt++)
    {
        scanf("%d",&iPtr[iCnt]);
    }

    printf("Enter the No to Check : ");
    scanf("%d",&iValue);


    // Step 2 : Use the Memory 
    bRet = LinearSearch(iPtr ,iLength , iValue) ;
    if (true == bRet )
    {
        printf("The Number %d is in the Array",iValue);
    }
    else
    {
        printf("The Number %d is not in the Array",iValue);
    }


    //Step 3 : Free the Memory
    free(iPtr);
    
    return 0;
}
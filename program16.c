/////////////////////////////////////////////////////////////////////////
//                                                                     
//  Required Header Files
//
/////////////////////////////////////////////////////////////////////////

#include <stdio.h>                               //FOR INPUT OUTPUT
#include <stdbool.h>                             //FOR BOOL DATATYPE

/////////////////////////////////////////////////////////////////////////
//                                                                     
//  Function Name   :   CheckEvenOdd                             
//  Description     :   It is used to check even or odd                
//  Input           :   Integer                                    
//  Output          :   Boolean
//  Author          :   Harish Mahendra Pawar
//  Date            :   10/10/2025
//  
/////////////////////////////////////////////////////////////////////////
bool CheckEvenOdd(int iNo)
{
    int iRem= 0 ;                                
    iRem = iNo % 2 ;
    if (iRem == 0 )
    {   return true;    }
    else
    {   return false;   } 
}   //End of Function;

/////////////////////////////////////////////////////////////////////////
//                                                                     
//  Entry Point Function of the Application
//
/////////////////////////////////////////////////////////////////////////

int main()
{
    int iValue =0;
    bool bRet = false;

    printf(" Enter number : \n");
    scanf("%d",&iValue);
    
    bRet = CheckEvenOdd(iValue);
    if(bRet == true)
    {   printf("%d is even no",iValue); }
    else
    {   printf("%d is odd no",iValue);  }
    return 0;
}
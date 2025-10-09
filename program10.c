 /*
 STEP 1 : UNDERSTAND THE PROBLEM STATEMENT
 STEP 2 : WRITE THE ALGORITHM
 STEP 3 : DECIDE THE PROGRAMMING LANGUAGE
 STEP 4 : WRITE THE PROGRAM
 STEP 5 : TEST THE PROGRAM
 */

 /*
    ALGORITHM
    START 
        Accept first no as no1
        Accept second no as no2
        if input is negative then convert it into positive
        Perform Addition of no1 and no2
        Display the Addition on console  
    STOP
 */

/////////////////////////////////////////////////////////////////////////
//
//    Required Header Files
//
/////////////////////////////////////////////////////////////////////////
 #include <stdio.h>

/////////////////////////////////////////////////////////////////////////
//                                                                     
//  Function Name   :   AdditionTwoNumbers                             
//  Description     :   It is used to perform addition                 
//  Input           :   float,float                                    
//  Output          :   float
//  Author          :   Harish Mahendra Pawar
//  Date            :   09/10/2025
//  
/////////////////////////////////////////////////////////////////////////

float AdditionTwoNumbers(float fNo1, float fNo2)
{
    float fSum = 0.0f;
    //UPDATER
    if (fNo1 <0.0f) 
    {
        fNo1 =-fNo1 ;
    }

     //UPDATER
    if (fNo2 <0.0f)
    {
        fNo2 =-fNo2 ;
    }

    fSum = fNo1 + fNo2 ; //BUSINESS LOGIC
    return fSum;
}
/////////////////////////////////////////////////////////////////////////
//                                                                     
//  Entry Point Function For The Application
//  
/////////////////////////////////////////////////////////////////////////

int main()
{

    float fValue1=0.0f, fValue2=0.0f, fRet = 0.0f;
    printf("Enter first no : \n");
    scanf("%f",&fValue1);

    printf("Enter second no : \n");
    scanf("%f",&fValue2);

    fRet = AdditionTwoNumbers(fValue1,fValue2) ; //The variable that catches return value = iRet
   
    printf("Addition is : %f\n",fRet);
   
    return 0;
}
/////////////////////////////////////////////////////////////////////////
//  Test Cases Successfully handled by the Application                                                                   
//  Input 1 : 10.5  Input 2: 3.2    Output: 13.7
//  Input 1 : -10.5 Input 2: 3.2    Output: 13.7
//  Input 1 : 10.5  Input 2: -3.2   Output: 13.7
//  Input 1 : -10.5 Input 2: -3.2   Output: 13.7
//  Input 1 : 10.5  Input 2: 0.0    Output: 13.7
// 
/////////////////////////////////////////////////////////////////////////
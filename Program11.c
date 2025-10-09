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

float AdditionTwoNumbers(   
                            float fNo1,                     //FIRST INPUT
                            float fNo2                      // SECOND INPUT
                        )
{
    float fSum = 0.0f;                                      //TO STORE THE RESULT
 
    if (fNo1 <0.0f)                                         //UPDATER 
    {
        fNo1 =-fNo1 ;
    }

    
    if (fNo2 <0.0f)                                         //UPDATER
    {
        fNo2 =-fNo2 ;
    }

    fSum = fNo1 + fNo2 ;                                    //BUSINESS LOGIC
    return fSum;
}   //End of AdditionTwoNumbers
/////////////////////////////////////////////////////////////////////////
//                                                                     
//  Entry Point Function For The Application
//  
/////////////////////////////////////////////////////////////////////////

int main()
{

    float fValue1=0.0f, fValue2=0.0f;                       //To Accept User Input
    float fRet = 0.0f;                                      //To Store The Result
    printf("Enter first no : \n");
    scanf("%f",&fValue1);

    printf("Enter second no : \n");
    scanf("%f",&fValue2);

    fRet = AdditionTwoNumbers(fValue1,fValue2) ;            //(Method Call) The variable that catches return value = iRet
   
    printf("Addition is : %f\n",fRet);
   
    return 0;
} //End of Main
/////////////////////////////////////////////////////////////////////////
//  Test Cases Successfully handled by the Application                                                                   
//  Input 1 : 10.5  Input 2: 3.2    Output: 13.7
//  Input 1 : -10.5 Input 2: 3.2    Output: 13.7
//  Input 1 : 10.5  Input 2: -3.2   Output: 13.7
//  Input 1 : -10.5 Input 2: -3.2   Output: 13.7
//  Input 1 : 10.5  Input 2: 0.0    Output: 13.7
// 
/////////////////////////////////////////////////////////////////////////
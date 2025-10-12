#include <stdio.h>
//dynamic function 
void Display(int iFrequency)
{   
    int iCnt =0;

    for(iCnt=1 ; iCnt<=iFrequency ; iCnt++)
    {
        printf("Jay Ganesh...\n");   
    } 
}   

int main() 
{
    int iCount = 0;
    printf("Enter the frequency : \n");
    scanf("%d",&iCount);

    
    Display(iCount);  

    return 0; 
}
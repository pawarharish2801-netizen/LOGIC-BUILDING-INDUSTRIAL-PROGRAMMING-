#include <stdio.h>
#pragma pack(1)
#include <stdlib.h>


struct node
{                                                      
    int data ;
    struct node *next ;
};

typedef struct node NODE ;
typedef struct node * PNODE ;
typedef struct node ** PPNODE ;

void InsertFirst(PPNODE first , int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));
    newn->data = no ;
    newn->next = NULL;

    if((*first) == NULL)  //LL IS EMPTY
    {
        (*first) = newn ;
    }
    else //LL CONTAINS ATLEAST ONE
    {
        newn->next = (*first) ; 
        (*first) = newn ;
    }

}
int Display(PNODE first )
{
    while(first != NULL)
    {
        printf("| %d | -> ",first->data) ;
        first = first->next;
    }
    printf("NULL\n");
}
int SecondMax(PNODE first)
{
    int Max = 0 , SecMax = 0 ;

    if(first == NULL || first->next == NULL)
    {
        return -1;   // Not possible
    }

    Max = SecMax = first->data;
    while(first != NULL)
    {
        if(first->data > Max)
        {
            SecMax = Max;
            Max = first->data;
        }
        else if(first->data > SecMax && first->data != Max)
        {
            SecMax = first->data;
        }
        first = first->next;
    }

    return SecMax;
}

int main()
{   
    PNODE head = NULL;
    int iValue = 0 ;
    int iRet = 0 ;
   
  
    
    InsertFirst(&head,41);
    InsertFirst(&head,32);
    InsertFirst(&head,20);
    InsertFirst(&head,11);

    Display(head) ;
   
   
    iRet = SecondMax(head);

    printf("%d is the second max ",iRet);

        
    return 0;
}

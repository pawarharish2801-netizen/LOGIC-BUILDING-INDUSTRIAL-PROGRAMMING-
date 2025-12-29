#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data ;
    struct node *next ;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void InsertFirst(PPNODE first , PPNODE last , int no)
{
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if( (*first) == NULL && (*last) == NULL)
    {
        *first = newn  ;
        *last = newn ;
        
    }
    else
    {

    }
    (*last)->next = *first ;

}

void InsertLast(PPNODE first , PPNODE last , int no)
{
    
    PNODE newn = NULL;
    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if( (*first) == NULL && (*last) == NULL)
    {
        *first = newn  ;
        *last = newn ;
        
    }
    else
    {
        newn->next =*first ;
        *first = newn ;

    }
    (*last)->next = *first ;          //@
    
}

void InsertAtPos(PPNODE first , PPNODE last , int no , int Pos)
{}

void DeleteFirst(PPNODE first , PPNODE last )
{}

void DeleteLast(PPNODE first , PPNODE last )
{}

void DeleteAtPos(PPNODE first , PPNODE last , int pos )
{}

void Display(PNODE first , PNODE last)
{}

int Count(PNODE first , PNODE last)
{}

int  main()
{
    PNODE head = NULL ;
    PNODE tail = NULL ;     //@

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);


    return 0 ;
}
#include<stdio.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

int main()
{
    NODE obj;
    PNODE ptr1 = NULL;
    PPNODE ptr2 = NULL;

    ptr1 = &obj;
    ptr2 = &ptr1;
    
    return 0;
}
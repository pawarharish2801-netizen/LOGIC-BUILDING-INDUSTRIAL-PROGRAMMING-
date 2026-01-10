#include <iostream>
using namespace std;

#pragma pack(1)
class Stacknode
{
    public :
    int data ;
    Stacknode *next ;

    Stacknode(int no)
    {
        this->data = no ;
        this->next = NULL;
    }
};

class Stack
{
    private :
        Stacknode *first ;
        int iCount ;

    public :
        Stack();

        void push(int);        //InsertFirst
        int pop();         //DeleteFirst
        int peep();
        void display();     
        int count();
};

Stack ::  Stack()
{
    
}

void  Stack ::  push(int no)
{

}

int Stack ::  pop()
{
    return 0 ;
}

int Stack ::  peep()
{
    return 0 ;
}

void Stack ::  display()
{

}

int Stack ::  count()
{
    return this->iCount ;
}

int main()
{
    Stack *sobj = new Stack();



    delete(sobj);

    return 0 ;
}
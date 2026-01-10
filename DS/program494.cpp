//////////////////////////////////////////////////////////////////////
//FINAL CODE OF STACK USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

#pragma pack(1)
template <class T>
class Stacknode
{
    public :
    T data ;
    Stacknode <T> *next ;

    Stacknode(int no)
    {
        this->data = no ;
        this->next = NULL;
    }
};

template <class T>
class Stack
{
    private :
        Stacknode <T> *first ;
        int iCount ;

    public :
        Stack();

        void push(T);        
        T pop();         
        T peep();
        void display();     
        int count();
};

template <class T>
Stack <T> ::  Stack()
{
    cout<<"Stack gets created Successfully\n";
    this->first = NULL ;
    this->iCount = 0 ;   
}

template <class T>
void  Stack <T> ::  push(T no)
{
    Stacknode <T> *newn = NULL ;
    newn = new Stacknode <T>(no);
    
    newn->next = this->first ;
    this->first = newn ;
    iCount++ ;
}

template <class T>
T Stack <T> ::  pop()
{
    T Value = 0 ;
    Stacknode  <T> *temp = NULL ;

    if ( this->first == NULL)
    {
        cout<<"Stack is empty";
        return -1 ;
    }

    Value = this->first->data ;

    temp = this->first;

    this->first = this->first->next ;
    delete temp ;

    this->iCount-- ;
    return Value;
}

template <class T>
T Stack <T> ::  peep()
{
    T Value = 0 ;

    if ( this->first == NULL)
    {
        cout<<"Stack is empty";
        return -1 ;
    }

    Value = this->first->data ;

    return Value;
}

template <class T>
void Stack <T> ::  display()
{
    Stacknode <T> *temp = this->first ;

    if(this->first == NULL)
    {
        cout<<"Stack is empty";
        return ;
    }
    
    while (temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp->next;
    }
}

template <class T>
int Stack <T> ::  count()
{
    return this->iCount ;
}

int main()
{
    Stack <char> *sobj = new Stack <char>();

    sobj->push('a');
    sobj->push('b');
    sobj->push('c');
    sobj->push('d');
    
    sobj->display();

    cout<<"Number of elements in the stack are : "<<sobj->count()<<"\n";

    cout<<"Return value of peep is : "<<sobj->peep()<<"\n";

    sobj->display();

    cout<<"Number of elements in the stack are : "<<sobj->count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";

    sobj->display();

    cout<<"Number of elements in the stack are : "<<sobj->count()<<"\n";

    cout<<"Poped element is :"<<sobj->pop()<<"\n";

    sobj->display();
    
    cout<<"Number of elements in the stack are : "<<sobj->count()<<"\n";

    sobj->push('e');

    sobj->display();
    
    cout<<"Number of elements in the stack are : "<<sobj->count()<<"\n";


    delete(sobj);

    return 0 ;
}
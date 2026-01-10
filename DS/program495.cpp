////////////////////////////////////////////////
//   Generalised Data Structure Library 
///////////////////////////////////////////////


/*
------------------------------------------------------------------------------------------------  
|    Type           |    Name of class for Node    |       Name of Class for Functionality     |
------------------------------------------------------------------------------------------------
|   SinglyLinear    |    SinglyLLLnode             |       SinglyLLL            Done           |
|   SinglyLinear    |    SinglyCLLnode             |       SinglyCLL            Done           |
|   DoublyLinear    |    DoublyLLLnode             |       DoublyLLL                           |
|   DoublyCircular  |    DoublyCLLnode             |       DoublyCLL                           |
|   Stack           |    StackNode                 |       Stack                Done           |  
|   Queue           |    QueueNode                 |       Queue                Done           | 
------------------------------------------------------------------------------------------------ 
*/

#include <iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////
//         SINGLY LINEAR LINKED LIST USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////

#pragma pack (1)
template <class T>
class SinglyLLLNode
{
    public: 
        T data;
        SinglyLLLNode <T> *next;

    SinglyLLLNode(T no)
    {
        this->data = no ;
        this->next = NULL;
    }
};

template <class T>
class SinglyLLL
{
    private:        
        SinglyLLLNode <T> *  first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T)  ;  
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T,int);
        void DeleteAtPos(int);
        
};

template <class T>
SinglyLLL <T> :: SinglyLLL ()
{
    cout<<"Object of SinglyLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Input         : Data of node   
//  Output        : Nothing     
//  Description   : Used to Insert Node at first position
//  Author        : Harish Mahendra Pawar
//  Date          : 06/01/2026
//
/////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL <T> ::   InsertFirst  (T no)    
{
    SinglyLLLNode <T>* newn = NULL;

    newn = new SinglyLLLNode <T> (no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

template <class T>
void SinglyLLL <T> :: InsertLast(T no)
{
    SinglyLLLNode<T>* newn = NULL;
    SinglyLLLNode<T>* temp = NULL;

    newn = new SinglyLLLNode <T>(no);

    if(this->iCount == 0)     
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }
    this->iCount++;
}

template <class T>
void SinglyLLL <T> :: DeleteFirst()
{
    SinglyLLLNode <T>* temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    // else if(this->iCount == 1)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;
}

template <class T>
void SinglyLLL <T> :: DeleteLast()
{
    SinglyLLLNode <T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)    
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp -> next;
        }

        delete temp->next;
        temp->next = NULL;

    }
    this->iCount--;
}

template <class T>
void SinglyLLL <T> :: Display()
{
    SinglyLLLNode <T> * temp = NULL;
    int iCnt = 0;

    temp = this->first;

    for(iCnt = 1; iCnt <= this->iCount; iCnt++)   
    {
        cout<<"| "<<temp->data<<" |-> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

template <class T>
int SinglyLLL <T> :: Count()
{
    return this->iCount;
}

template <class T>
void SinglyLLL <T> :: InsertAtPos(T no, int pos)
{
    SinglyLLLNode <T>* temp = NULL;
    SinglyLLLNode <T>* newn = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLNode <T> (no);
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

template <class T>
void SinglyLLL <T> :: DeleteAtPos(int pos)
{
    SinglyLLLNode <T>* temp = NULL;
    SinglyLLLNode <T>* target = NULL;

    int iCnt = 0;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;

        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}


//////////////////////////////////////////////////////////////////////
//          SINGLY CIRCULAR LINKED LIST USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////

template <class T>
    class SinglyCLLnode
    {
        public:
        T data;
        SinglyCLLnode <T> *next ;

        SinglyCLLnode(T no)
        {
            this->data = no ;
            this->next = NULL;
        }
    };

    template <class T>
    class SinglyCLL
    {
        private :
        SinglyCLLnode <T> *first ;
        SinglyCLLnode <T> *last ;
        int iCount ;

        public :
        SinglyCLL() ;
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T , int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count() ;
    };

    template <class T>
    SinglyCLL <T> :: SinglyCLL() 
    {
        cout << "\n SinglyCLL gets created \n";
        this->first = NULL;
        this->last = NULL;
        this->iCount = 0;
    }

    template <class T>
    void SinglyCLL <T> :: InsertFirst (T no)
    {
        SinglyCLLnode <T> *newn = NULL;
        newn = new SinglyCLLnode <T> (no);

        if (this->first == NULL)
        {
            this->first = newn ;
            this->last = newn ;
        }
        else
        {
            newn->next = this->first ;
            this->first = newn ;
        }
        this->last->next = this->first ;
        iCount++ ;
    }

    template <class T>
    void SinglyCLL  <T>::InsertLast(T no)
    {
        SinglyCLLnode <T> *newn = NULL;
        newn = new SinglyCLLnode <T> (no);

        if (this->first == NULL)
        {
            this->first = newn ;
            this->last = newn ;
        }
        else
        {
            this->last->next = newn ;
            this->last = newn ;
        }
        this->last->next = this->first ;
        iCount++ ;
        
    }

    template <class T>
    void SinglyCLL <T> ::InsertAtPos(T no , int pos)
    {
        SinglyCLLnode <T> *temp = NULL; 
        SinglyCLLnode <T> *newn = NULL;    
        int iCnt = 0 ;

        if (pos < 1 || pos >iCount+1)
        {
            printf("Invalid Position \n");
            return ;
        }

        if ( pos == 1)
        {
            InsertFirst(no);
        }
        else if ( pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            newn = new SinglyCLLnode <T> (no);

            temp = this->first ;
            for ( iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
            {
                temp = temp->next;
            }
            newn->next = temp->next ;
            temp->next = newn ;
            iCount ++ ;
        }

    }

    template <class T>
    void SinglyCLL <T> :: DeleteFirst()
    {
        if(this->first == NULL && this->last == NULL)
        {
            return ;
        }
        else if ( this->first == this->last)
        {
            delete this->first ;
            this->first = NULL;
            this->last = NULL;
        }
        else
        {
            this->first = this->first->next ;
            delete this->last->next ;
            this->last->next = this->first;
        }
       
        iCount-- ;
    }

    template <class T>
    void SinglyCLL <T> :: DeleteLast()
    {
        SinglyCLLnode <T> *temp = NULL;

        if(this->first == NULL && this->last == NULL)
        {
            return ;
        }
        else if ( this->first == this->last)
        {
            delete this->first ;
            this->first = NULL;
            this->last = NULL;
        }
        else
        {
            temp = this->first;
            do
            {
                temp = temp->next;
            } while (temp->next->next != first);
            delete temp->next ;
            last = temp ;
            this->last->next = this->first;
        }
        iCount-- ;
    }

    template <class T>
    void SinglyCLL <T> :: DeleteAtPos(int pos)
    {
        SinglyCLLnode <T> *temp = NULL;
        SinglyCLLnode <T> *target = NULL;  
        int iCnt = 0 ;

        if (pos < 1 || pos >iCount)
        {
            printf("Invalid Position \n");
            return ;
        }

        if ( pos == 1)
        {
            DeleteFirst();
        }
        else if ( pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            temp = this->first ;
            for ( iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
            {
                temp = temp->next;
            }
            target = temp->next ;
            temp->next = temp->next->next ;
            delete target ;
            iCount -- ;
        }  
    }

    template <class T>
    void SinglyCLL <T> ::Display()
    {
        if ( first == NULL)
        {
            cout<<"Empty list\n";
            return ;
        }
        SinglyCLLnode <T> *temp =NULL ;
        temp = this->first ;

        cout << " <= ";
        do
        {
            cout<< " | "<<temp->data<<" | =>";
            temp = temp->next ;
        }while ( temp != first);
        cout<<"\n";
    }

    template <class T>
    int SinglyCLL <T> :: Count() 
    {
        return this->iCount;
    }

//////////////////////////////////////////////////////////////////////
//          DOUBLY LINEAR LINKED LIST USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class DoublyLLLnode 
{
    public : 
        T data ;
        DoublyLLLnode* next ;
        DoublyLLLnode * prev ;
    
    DoublyLLLnode(T no)
    {
        this->data = no ;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyLLL
{
    private:
    DoublyLLLnode <T> * first ;
    int iCount ;

    public :
    DoublyLLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int );

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    void Display();
    int Count();    
};

template <class T>
DoublyLLL <T> :: DoublyLLL()
{
    cout << "\n Linked List gets created\n";

    this->first = NULL;
    this->iCount = 0 ;
}

template <class T>
void DoublyLLL <T> ::  InsertFirst(T no)
{
    DoublyLLLnode <T> *newn = NULL ;

    newn = new DoublyLLLnode <T> (no);

    if (this->first == NULL)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first ;
        this->first->prev = newn ;
        this->first = newn ;
    }
    this->iCount++ ;
}

template <class T>
void DoublyLLL <T> ::  InsertLast( T no)
{
    DoublyLLLnode <T>*newn = NULL ;
    DoublyLLLnode <T> *temp = NULL;

    newn = new DoublyLLLnode <T> (no);

    if ( first == NULL)
    {
        first = newn ;
    }
    else 
    {
        temp = this->first ;
        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next = newn ;
        newn->prev = temp;
    }
    iCount++ ;
}

template <class T>
void DoublyLLL <T> ::  InsertAtPos(T no , int pos )
{
    DoublyLLLnode <T>*temp  = NULL;
    DoublyLLLnode <T> *newn = NULL ;
    int iCnt = 0 ;

    if ( pos < 1 || pos > this->iCount+1)
    {
        cout<<"Invalid Position";
        return ;
    }

    if ( pos == 1)
    {
        this->InsertFirst(no);
    }
    else if ( pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new DoublyLLLnode <T>(no);
        for ( iCnt = 1 ; iCnt <pos - 1 ; iCnt++)
        {
            temp= temp->next;
        }
        newn->next = temp->next ;
        newn->next->prev = newn ;
        temp->next = newn ;
        newn->prev = temp ;

        this->iCount++;
    }

}

template <class T>
void  DoublyLLL <T> :: DeleteFirst()
{
    if (this->first == NULL)            
    {
        return ;
    }
    else if ( this->first->next == NULL) 
    {
        delete this->first ;
        this->first = NULL;
    }
    else                                
    {   
        this->first = this->first->next;
        delete this->first->prev ;
        this->first->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLLL <T> ::  DeleteLast()
{
    DoublyLLLnode <T> *temp = NULL;
    if (this->first == NULL)            
    {
        return ;
    }
    else if ( this->first->next == NULL) 
    {
        delete this->first ;
        this->first = NULL;
    }
    else                                
    {   
        temp = this->first ;
       
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next ;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void  DoublyLLL <T> :: DeleteAtPos(int pos)
{
    DoublyLLLnode <T> *temp  = NULL;
    int iCnt = 0 ;
    if ( pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid Position";
        return ;
    }

    if ( pos == 1)
    {
        this->DeleteFirst();
    }
    else if ( pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        for ( iCnt = 1 ; iCnt <pos - 1 ; iCnt++)
        {
            temp= temp->next;
        }
        temp->next = temp->next->next ;
        delete temp->next->prev ;
        temp->next->prev = temp ;
        this->iCount--;
    }
}

template <class T>
void DoublyLLL <T> ::  Display()
{
    DoublyLLLnode <T> *temp = NULL;

    temp = this->first ;

    cout<<"\nNULL <=>";
    while ( temp != NULL)
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp ->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLLL <T> ::  Count() 
{
    return this->iCount ;   
}


//////////////////////////////////////////////////////////////////////
//          DOUBLY LINEAR LINKED LIST USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////

template <class T>

class DoublyCLLnode
{
    public :
    T data ;
    DoublyCLLnode <T> *next ;
    DoublyCLLnode <T> *prev ;

    DoublyCLLnode  ( T no)
    {
        this->data = no ;
        this->next = NULL;
        this->prev = NULL;
    }
};

template <class T>
class DoublyCLL 
{
    private :
    DoublyCLLnode <T> *first ;
    DoublyCLLnode <T> *last ;
    int iCount ;
    
    public :
    DoublyCLL() ;
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count() ;
};

template <class T>
DoublyCLL <T>:: DoublyCLL() 
{
    cout << "\n Object of Doubly CLL gets created \n";
    this->iCount = 0 ;
    this->last = NULL ;
    this->first = NULL ;
}

template <class T>
void DoublyCLL <T>:: InsertFirst(T no)
{
    DoublyCLLnode <T> *newn = NULL;
    newn = new DoublyCLLnode <T>(no);

    if ( this->first == NULL)
    {
        this->first = newn ;
        this->last = newn ;
    }
    else
    {
        newn->next = this->first ;
        this->first->prev = newn ;
        this->first = newn ;
    }
    this->last->next = this->first ;
    this->first->prev = this->last ;
    this->iCount++ ;
}

template <class T>
void DoublyCLL <T>:: InsertLast(T no)
{
    DoublyCLLnode <T> *newn = NULL;
    newn = new DoublyCLLnode <T>(no);

    if ( this->first == NULL)
    {
        this->first = newn ;
        this->last = newn ;
    }
    else
    {
        this->last->next = newn ;
        newn->prev = this->last ;
        this->last = newn ;
    }
    this->last->next = this->first ;
    this->first->prev = this->last ;
    this->iCount++ ;
}

template <class T>
void DoublyCLL <T>::InsertAtPos(T no, int pos)
{
    DoublyCLLnode <T> *temp = NULL;
    DoublyCLLnode <T> *newn = NULL; 
    int iCnt = 0 ;
    if ( pos < 1 || pos > this->iCount + 1)
    {
        cout<<" Invalid Position" ;
        return ;
    }

    if ( pos ==1)
    {
        this->InsertFirst(no);
    }
    else if ( pos == this->iCount+1)
    {
        this->InsertLast(no);
    }
    else
    {
        temp = this->first;
        newn = new DoublyCLLnode <T> (no);
        
        for ( iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp->next ;
        }

        newn->next = temp->next ;
        newn->next->prev = newn ;
        temp->next = newn ;
        newn->prev = temp ;

        this->iCount++;
    }
}

template <class T>
void DoublyCLL <T>::DeleteFirst()
{
    if (this->first == NULL && this->last == NULL )
    {
        return ;
    }
    else if ( this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first->next ;
        delete this->last->next ;

        this->last->next = this->first ;
        this->first->prev = this->last ;
    }
    this->iCount--;
}

template <class T>
void DoublyCLL <T>:: DeleteLast()
{
    if (this->first == NULL && this->last == NULL )
    {
        return ;
    }
    else if ( this->first == this->last)
    {
        delete this->first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->last = this->last->prev ;
        delete this->last->next ;

        this->last->next = this->first ;
        this->first->prev = this->last;
    }
    this->iCount--;
}

template <class T>
void DoublyCLL <T>::DeleteAtPos(int pos)
{
    DoublyCLLnode <T> *temp = NULL;
    int iCnt = 0 ;
    if ( pos < 1 || pos > this->iCount)
    {
        cout<<" Invalid Position" ;
        return ;
    }

    if ( pos ==1)
    {
        this->DeleteFirst();
    }
    else if ( pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;
        
        for ( iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
        {
            temp = temp->next ;
        }  
        temp->next = temp->next->next ;
        delete temp->next->prev ; 
        temp->next->prev = temp ;
        this->iCount--;  
    }
}

template <class T>
void DoublyCLL <T>::Display()
{
    if ( this->first == NULL)
    {
        cout<< "Linked List is empty\n";
        return ;
    }

    DoublyCLLnode <T> *temp = NULL ;
    temp = this->first ;

    cout<<" <=>";
    do
    {
        cout<<" | "<<temp->data<<" | <=>";
        temp = temp ->next ;
    } while (temp != this->first);
    cout<<"\n";
}

template <class T>
int  DoublyCLL <T>::Count() 
{
    return this->iCount;
}


//////////////////////////////////////////////////////////////////////
//              STACK USING GENERIC APPROACH 
//////////////////////////////////////////////////////////////////////

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



////////////////////////////////// End of Library ////////////////////////////////////////////////////

int main()
{
    SinglyLLL <int> *obj = new SinglyLLL <int> ();
    int iRet = 0;

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);
    
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    obj->DeleteFirst();
    obj->Display();

    iRet = obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    obj->InsertAtPos(105,4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";
    
    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout<<"Number of Nodes are : "<<iRet<<"\n";

    delete (obj);

    ///////////////////////////////////////////////////////////////////////////////
    DoublyLLL <char> *dobj = new DoublyLLL <char> ();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('C');

    dobj->Display();
    cout<<"No of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"No of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    cout<<"No of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    cout<<"No of elements are : "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$',4);
    dobj->Display();
    cout<<"No of elements are : "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);
    dobj->Display();
    cout<<"No of elements are : "<<dobj->Count()<<"\n";
   
    delete (dobj);

    //////////////////////////////////////////////////////////////////////////////////////////////////
    SinglyCLL <int> *CLobj = new SinglyCLL <int> ();

        CLobj->InsertFirst(51);
        CLobj->InsertFirst(21);
        CLobj->InsertFirst(11);

        CLobj->Display();
        cout<<"Number of elements are : "<<CLobj->Count()<<"\n";

        CLobj->InsertLast(101);
        CLobj->InsertLast(111);
        CLobj->InsertLast(121);

        CLobj->Display();
        cout<<"Number of elements are : "<<CLobj->Count()<<"\n"; 

        CLobj->DeleteFirst();
        CLobj->Display();
        cout<<"Number of elements are : "<<CLobj->Count()<<"\n"; 

        CLobj->DeleteLast();
        CLobj->Display();
        cout<<"Number of elements are : "<<CLobj->Count()<<"\n"; 

        CLobj->InsertAtPos(105,4);
        CLobj->Display();
        cout<<"Number of elements are : "<<CLobj->Count()<<"\n"; 

        CLobj->DeleteAtPos(4);
        CLobj->Display();
        cout<<"Number of elements are : "<<CLobj->Count()<<"\n"; 

        delete (CLobj);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    DoublyCLL <int> *DCLobj = new DoublyCLL <int> ();

    DCLobj->InsertFirst(51);
    DCLobj->InsertFirst(21);
    DCLobj->InsertFirst(11);

    DCLobj->Display();
    cout<< "Number of elements are : "<<DCLobj->Count()<<" \n";

    DCLobj->InsertLast(101);
    DCLobj->InsertLast(111);
    DCLobj->InsertLast(121);

    DCLobj->Display();
    cout<< "Number of elements are : "<<DCLobj->Count()<<" \n";

    DCLobj->DeleteFirst();

    DCLobj->Display();
    cout<< "Number of elements are : "<<DCLobj->Count()<<" \n";

    DCLobj->DeleteLast();

    DCLobj->Display();
    cout<< "Number of elements are : "<<DCLobj->Count()<<" \n";

    DCLobj->InsertAtPos(105,4);

    DCLobj->Display();
    cout<< "Number of elements are : "<<DCLobj->Count()<<" \n";

    DCLobj->DeleteAtPos(4);

    DCLobj->Display();
    cout<< "Number of elements are : "<<DCLobj->Count()<<" \n";

    delete(DCLobj);

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////

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
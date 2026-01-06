////////////////////////////////////////////////
//   Generalised Data Structure Library 
///////////////////////////////////////////////


/*
--------------------------------------------------------------------------------------------   
|    Type           |    Name of class for Node    |       Name of Class for Functionality |
--------------------------------------------------------------------------------------------
|   SinglyLinear    |    SinglyLLLnode             |      SinglyLLL                        |
|   SinglyLinear    |    SinglyCLLnode             |       SinglyCLL                       |
|   DoublyLinear    |    DoublyLLLnode             |       DoublyLLL                       |
|   DoublyCircular  |    DoublyCLLnode             |       DoublyCLL                       |
-------------------------------------------------------------------------------------------- 
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
    cout << "Linked List gets created\n";

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

////////////////////////////////// End of Library ////////////////////////////////////////////////////

int main()
{


    return 0 ;
}
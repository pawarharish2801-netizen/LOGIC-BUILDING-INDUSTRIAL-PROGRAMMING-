// Singly Circular

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;

class SinglyCL
{
    private:
        PNODE first;
        PNODE last;
        int iCount;

    public:
        SinglyCL()
        {
            cout<<"Object of SinglyCL gets created.\n";
            this->first = NULL;
            this->last = NULL;
            this->iCount = 0;
        }

        void InsertFirst(int no)
        {
            PNODE newn = NULL ;
            newn = new node;

            newn->next = NULL ;
            newn->data = no ;

            if (first == NULL)
            {
                first = newn ;
                last = newn ;
            }

            else
            {
                newn->next = first ;
                first = newn ;
            }
            last->next = first ;
            iCount++;
        }

        void InsertLast(int no)
        {
            PNODE newn = NULL ;
            PNODE temp = NULL ;
            newn = new node;

            newn->next = NULL ;
            newn->data = no ;

            if (first == NULL)
            {
                first = newn ;
                last = newn ;
            }

            else
            {
                last->next = newn ; 
                last = newn ;
            }
            this->last->next = first ;
            iCount++;
        }

        void InsertAtPos(int no, int pos)
        {
            PNODE newn = NULL ;
            PNODE temp = NULL ;
            int iCnt = 0 ;
            if (pos < 1 || pos > this->iCount + 1)
            {
                cout << "Invalid Postion \n";
                return ;
            }

            if ( pos ==1)
            {
                this->InsertFirst(no);
            }
            else if (pos == iCount+1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new node ;

                newn->data = no ;
                newn->next =  NULL ;

                temp = this->first ;

                for(iCnt = 1 ; iCnt < pos - 1  ; iCnt++)
                {
                    temp = temp->next;
                }
                newn->next = temp->next;
                temp->next = newn ;

                this->iCount++ ;
            }

        }

        void DeleteFirst()
        {
            if(this->first == NULL && this->last == NULL)
            {
                return ;
            }
            else if (this->first == this->last)
            {
                delete (this->first);

                this->first = NULL ;
                this->last = NULL ;
            }
            else
            {
                first = first ->next ;
                delete (last->next) ;
                last->next = first ;
            }
            this->iCount -- ;
            
        }

        void DeleteLast()
        {
            PNODE temp = NULL ;
            if(this->first == NULL && this->last == NULL)
            {
                return ;
            }
            else if (this->first == this->last)
            {
                delete (this->first);

                this->first = NULL ;
                this->last = NULL ;
            }
            else
            {
                temp = this->first ;

                do
                {
                    temp = temp->next ;
                } while (temp->next->next != first);

                delete this->last ;
                last = temp ;
                temp->next = first ;
            }
            this->iCount -- ;
        }

        void DeleteAtPos(int pos)
        {
            PNODE temp = NULL ;
            PNODE target = NULL ;
            int iCnt = 0 ;
            if (pos < 1 || pos > this->iCount)
            {
                cout << "Invalid Postion \n";
                return ;
            }

            if ( pos ==1)
            {
                this->DeleteFirst();
            }
            else if (pos == iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first ;
                for(iCnt = 1 ; iCnt < pos - 1  ; iCnt++)
                {
                    temp = temp->next;
                }
                target = temp->next ;
                temp->next = target->next ;
                delete (target);

                this->iCount-- ;
            }


        }

        void Display()
        {
            PNODE temp = NULL ;

            temp = this->first ;

            cout<<" <- " ;

            do 
            {
                cout<<" | "<<temp->data<<" | ->";
                temp = temp->next;
            } while (temp != first);
            cout<<"\n";
        }


        int Count()
        {
            return iCount;
        }
};

int main()
{
    SinglyCL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);
    
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteFirst();
    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();
    cout<<"Number of nodes are : "<<iRet<<"\n";
    
    return 0;
}
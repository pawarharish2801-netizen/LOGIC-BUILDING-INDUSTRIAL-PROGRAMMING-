// Singly Circular

class node
{
    public int data;
    public node next;

    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

class SinglyCL
{
    private node first;
    private node last;
    
    private int iCount;

    public SinglyCL()
    {
        System.out.println("Object of SinglyCL gets created.");
        
        this.first = null;
        this.last = null;
        
        this.iCount = 0;
    }

    public void InsertFirst(int no)
    {
        node newn = null  ;

        newn = new node(no);

        if(first == null && last == null)
        {
            this.first = newn ;
            last = newn ;   
        }
        else
        {
            newn.next = this.first ;
            first = newn ;
        }
        last.next = first;
        iCount++;
        
    }

    public void InsertLast(int no)
    {
        node newn = null;
    
        newn = new node(no);

        if(first == null && last == null)
        {
            this.first = newn ;
            this.last = newn ;   
        }
        else
        {
            last.next = newn ;
            last = newn ;
        }
        last.next = first;

        iCount++;

    }

    public void InsertAtPos(int no, int pos)
    {
        node newn = null ;
        node temp = null ;
        int iCnt = 0 ;
        if (pos < 1 || pos>this.iCount+1)
        {
            System.out.println("Invalid Position");
            return ;
        }
        
        if( pos == 1)
        {
            this.InsertFirst(no);
        }
        else if ( pos == this.iCount + 1)
        {
            this.InsertLast(no);
        }
        else
        {
            newn = new node(no);

            temp = this.first ;

            for(iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
            {
                temp = temp.next ;
            }
            newn.next = temp.next;
            temp.next = newn ;

            this.iCount++ ;
        }
    }

    public void DeleteFirst()
    {
        if( first == null && last == null)
        {
            return ;
        }
        else if ( first == last)
        {
            this.first  = null ;
            this.last = null ;
        }
        else
        {
            this.first = this.first.next ;

            this.last.next = this.first;
        }
        System.gc();
        this.iCount --;
    }
    
    public void DeleteLast()
    {
        node temp = null ; 
        if( first == null && last == null)
        {
            return ;
        }
        else if ( first == last)
        {
            this.first  = null ;
            this.last = null ;
        }
        else
        {
            temp = this.first   ;

            do
            {
                temp = temp.next ;
            }while (temp.next.next != first);
            temp.next = temp.next.next ;

            last = temp ;

        }
        System.gc();
        iCount--;
    }
    
    public void DeleteAtPos(int pos)
    {
        node temp = null;
        int iCnt = 0 ;
        if (pos < 1 || pos>this.iCount)
        {
            System.out.println("Invalid Position");
            return ;
        }
        
        if( pos == 1)
        {
            this.DeleteFirst();
        }
        else if ( pos == this.iCount)
        {
            this.DeleteLast();
        }
        else
        {
            temp = this.first ;

            for(iCnt = 1 ; iCnt < pos - 1 ; iCnt++)
            {
                temp = temp.next ;
            }
            temp.next = temp.next.next ;

            this.iCount-- ;
            System.gc();
        }
        
    }
    
    public void Display()
    {
        node temp = null ;

        if(first == null)
        {
            return ;
        }
          
        temp = this.first;
        System.out.print("<- ");
        

        do
        {
            System.out.print("| "+temp.data+" | -> ");
            temp = temp.next;
        } while (temp != first );
        System.out.println();

    }

    public int Count()
    {
        return this.iCount;
    }
}

class program447
{
    public static void main(String A[])
    {
        SinglyCL obj = null;
        int iRet = 0;

        obj = new SinglyCL();

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
       
        obj.DeleteAtPos(4);
        
        obj.Display();

        iRet = obj.Count();

        System.out.println("Number of nodes are : "+iRet);
    
        // Important for memory deallocation 
        obj = null;
        System.gc();
    }
}
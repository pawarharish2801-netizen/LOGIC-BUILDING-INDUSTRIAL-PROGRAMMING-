import java.util.*;

class Number
{
    public void DisplayFactors(int iNo)
    {
        int i = 0;

        for(i = 1; i <= (iNo / 2); i++)
        {
            if((iNo % i) == 0)
            {
                System.out.println(i);
            }
        }
    }
} // End of Number

class program78
{
    public static void main(String A[])
    {
        int iValue = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        iValue = sobj.nextInt();
        
        Number nobj = new Number();
        nobj.DisplayFactors(iValue); 

        // Important
        
        sobj = null;
        nobj = null;

        System.gc();
    }
}

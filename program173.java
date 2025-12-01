/*
    input : 5
    output : a  b   c   d   e
    index :  1  2   3   4   5
    ASCII :  97 98  99  100 101          
*/

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
        int i = 97;

        for(iCnt = 1; iCnt <= iNo; iCnt++, i++)
        {
            System.out.printf("%d\t",i);
        }
        System.out.println();
    }
}

class program173
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;

        System.out.println("Enter the frequency : ");
        iValue = sobj.nextInt();

        Pattern pobj = new Pattern();
        pobj.Display(iValue);
    }
}
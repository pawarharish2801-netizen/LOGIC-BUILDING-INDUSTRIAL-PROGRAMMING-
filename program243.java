// Hello
//  H     e       l       l       o

import java.util.*;

class program243
{
    public static void main(String A[])
    {
        int iCnt = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String str = sobj.nextLine();

        for(iCnt = 0; iCnt < str.length(); iCnt++)
        {
            System.out.println(str.charAt(iCnt));
        }
        
    }
}
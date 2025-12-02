import java.util.*;

class program245
{
    public static void main(String A[])
    {
        Scanner scanobj = new Scanner(System.in);

        System.out.println("Enter string : ");
        String sobj = scanobj.nextLine();
        
        char Arr[] = sobj.toCharArray();

        System.out.println(sobj.length());

        System.out.println(Arr.length);
        
    }
}
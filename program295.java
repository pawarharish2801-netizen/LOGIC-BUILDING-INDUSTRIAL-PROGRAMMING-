import java.util.*;

class program295
{
    public static void main(String A[])
    {
        Vector <Integer> vobj = new Vector <Integer> ();

        vobj.add(11);
        vobj.add(21);
        vobj.add(51);
        vobj.add(101);
        vobj.add(111);

        System.out.println(vobj);
        
        vobj.add(2,10);

        System.out.println(vobj);

        System.out.println(vobj.capacity());

        System.out.println(vobj.contains(101));
        System.out.println(vobj.contains(102));

    }
}
import java.util.*;

class program299
{
    public static void main(String A[])
    {
        LinkedList <Double> vobj = new LinkedList <Double> ();

        vobj.add(10.5);
        vobj.add(30.7);
        vobj.add(12.6);
        vobj.add(78.9);
        vobj.add(90.7);

        System.out.println(vobj);

        vobj.addFirst(10.0);
        vobj.addLast(100.0);
        
        vobj.remove(2);

        System.out.println(vobj);

        Iterator iobj = vobj.iterator();

        while(iobj.hasNext())
        {
            System.out.println(iobj.next());
        }

        vobj.clear();
    }
}
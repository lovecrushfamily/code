using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    internal class Generic
    {
        public Generic()
        {
            int a = 9;
            int b = 10;
            Swap(ref a,ref  b);

        }

        //using generic to swap two variable without think about its data type
        public static void Swap<T>(ref T a, ref T b )
        {
            T temp = b; a = temp; b = temp;
        }

        //using generic to random an element of a list all datatype acceptable
        public static T getRandomElement<T>(List<T> list)
        {
            Random rnd = new Random();
            int index = rnd.Next(list.Count - 1);
            return list[index];
        }


    }
    public static class RandomElement
    {
        // And now turn it into an extension method of class List<T>
        public static T randomElement<T>(this List<T> list)
        {
            Random rnd = new Random();
            int index = rnd.Next(list.Count - 1);
            return list[index];

        }
    }
}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    internal class LINQ
    {
        private List<int> ints = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        public LINQ()
        {
            //That's how to create your own LinQ extension method
            var result = ints.MyWhere(num => (num > 6));
            //ints.All(num => (num > 7));
            //ints.Any(num => (num > 8));
            //ints.ForEach(Console.WriteLine);

            foreach (var i in result)
            {
                Console.WriteLine(i);
            }

        }

    }

    static class MyLinQ
    {
        internal static IEnumerable<TSource> MyWhere<TSource>(this IEnumerable<TSource> sources, Func<TSource, bool> predicate)
        {
            foreach (var source in sources)
            {
                if (predicate(source)) yield return source;
            }
        }
    }
}

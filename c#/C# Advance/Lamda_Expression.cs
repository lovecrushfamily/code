using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    internal class Lamda_Expression
    {
        delegate int MyLamda(int x);
        public Lamda_Expression()
        {

            //Anonymous function, 
            MyLamda lamb = delegate(int x) { return x; };
            Console.WriteLine(lamb(4));

            //Using func, define delegate using lamdaExpression
            Func<int, int> myFunc = x => x * 2;
                                // {Para} + {expresstion}
            Console.WriteLine(myFunc(4));


        }


    }
}

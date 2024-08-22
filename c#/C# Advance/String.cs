using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    internal class String
    {
        public String()
        {
            // How to duplicate a char 
            var str = new string('_', 10);
            Console.WriteLine(str);

            // How to join string 
            var obj = new object[] { 1, 2, 3, 4 };
            string result = string.Join(",", obj);
            Console.WriteLine(result);


            
        }
    }
}

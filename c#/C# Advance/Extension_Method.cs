using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    class Sample_Class
    {
        Sample_Class()
        {
            Console.WriteLine("Inititialize Sample Class");
        }

        void test()
        {
            Sample_Class sample_Class = new Sample_Class();
            sample_Class.Show();
        }
        
    }

    static class Extension_Method
    {
        internal static void Show(this Sample_Class extension_Method)
        {
            Console.WriteLine("That's extension method !");
        }
    }

}

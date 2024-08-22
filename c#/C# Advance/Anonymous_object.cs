using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Advance_C_
{
    internal class Anonymous_Object
    {
        Anonymous_Object() 
        {
            
            var myObj = new
            {
                name = "LoveCrush",
                age = 19,
                university = "utehy",
                major = "IT",
                student = "sophomore"

            };

            Console.WriteLine("So that's how to create a anonymous object\n");
            Console.WriteLine(myObj);

        }
    }

    class Object_Inititialize
    {
        public Object_Inititialize()
        {
            //Initialize basic object
            object obj_name = new object()
            {
                //name = "Lovecrush",
                //age = 19
            };


            // Inititilize collection object
            List<object> list = new List<object>()
            {
                new object()
                {
                    //name =  "Lovcrush",
                    //school =  "utehy"
                },
                new object()
                {
                    //name = "Crush",
                    //school = "hust"
                }
            };

        }
    }
}

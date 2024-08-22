using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Advance_C_
{
    [Serializable]
    internal class Serialize
    {

        internal Serialize()
        {
            Student student = new Student()
            {
                Id = 1,
                Name = "Lovecrush",
                Age = "19"
            };

            Student student1 = new Student()
            {
                Id = 1,
                Name = "Lovecrush",
                Age = "19"

            };


            //Create an instance of the XmlSerialize for the specific type of object
            XmlSerializer serializer = new XmlSerializer(typeof(Student));

            // Create SringWriter to store the serialized Xml Data
            StringWriter stringWriter = new StringWriter();
            StringWriter stringWriter1 = new StringWriter();

            // use the Serialize Method of the XmlSerialize to serialize the object to the StringWriter
            serializer.Serialize(stringWriter, student);
            string serializeString = stringWriter.ToString();

            serializer.Serialize(stringWriter1, student1);
            string serializeString1 = stringWriter1.ToString();

            Console.WriteLine(serializeString == serializeString1);
         


                                                        




        }
    }
}

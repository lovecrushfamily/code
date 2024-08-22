using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Diagnostics;
using System.Reflection;
using System.Globalization;
using System.Runtime;

namespace Xml
{
    class xml
    {


        internal static void ReadXmlFilePath(string path)
        {
            XmlDocument xmlDocument = new XmlDocument();
            //string xmlPath = Directory.GetCurrentDirectory() + @"\data.xml";
            //string xmlPath = @"D:\Documents\code\new.xml";
            string xmlPath = path;
            xmlDocument.Load(xmlPath);          



            XmlNodeList family = xmlDocument.GetElementsByTagName("brother");

            foreach(XmlNode node in family)
            {
                Console.WriteLine(node.Name + " : " + node.InnerText );  
            }

            DataTable tables = new DataTable();
           
            

        }

        static void WriteXmlPath(string path)
        {

        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            xml.ReadXmlFilePath(@"D:\Documents\code\new.xml");
        }
    }
}

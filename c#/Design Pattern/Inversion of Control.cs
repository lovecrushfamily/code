using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Inversion_of_Control
    {
        public static void Visualization()
        {
            //Client 
            IDatabase sqlserver = new SqlServer();
            sqlserver.Save("My data");

            sqlserver = new MysqlServer();
            sqlserver.Save("My Data");


        }
    }

    interface IDatabase
    {
        void Save(string data);
    }

    class SqlServer : IDatabase
    {
        public SqlServer() { }

        public void Save(string data)
        {
            Console.WriteLine(data + " has been saved by SqlServer");
        }
    }

    class MysqlServer : IDatabase
    {
        public MysqlServer() { }

        public void Save(string data)
        {
            Console.WriteLine(data + " has been saved by Mysql");
        }
    }


}

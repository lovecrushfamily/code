using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Dependency_Injection
    {
        public Dependency_Injection() { }

        public static void Visualization()
        {
            Inject inject = new Inject(new MysqlServer());
            inject.Push();
            

        }
    }

    class Inject
    {
        IDatabase database;
        //inject
        public Inject(IDatabase database)
        {
            this.database = database;
        }

        public void Push()
        {
            database.Save("Injection");
        }
    }


}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Singleton
    {
        //Step 1
        //Create Singleton instance inside the class
        private static Singleton instance = new Singleton();


        //Step 2
        //make the constructure's being privated
        private Singleton() { } 


        //Step 3
        // Get its instance via Class Method or Property Method
        public static Singleton GetInstance() { return instance; }
        public static Singleton Instance
        {
            get { return instance; }
        }

        /// <summary>
        /// Singleton visualization
        /// </summary>
        public static void Visualization()
        {
            //Create two instance using class method and Instance method
            Singleton singleton = Singleton.Instance;
            Singleton singleton1 = Singleton.GetInstance();

            //Show the hash code, both of them are the same => used only one instance
            Console.WriteLine("Hash code instance 1 => " + singleton.GetHashCode());
            Console.WriteLine("Hash code instance 2 => " + singleton1.GetHashCode());
        }                                         


    }
    
}

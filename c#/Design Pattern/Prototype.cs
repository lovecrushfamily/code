using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Prototype
    {
        // - Use the Prototype pattern when your code shouldn’t depend
        //on the concrete classes of objects that you need to copy.
        // - Use the pattern when you want to reduce the number of subclasses
        //that only differ in the way they initialize their respective objects.
        public static void Visualization()
        {

            //Create a sample base class
            MyClass myClass = new MyClass();

            //Copy its instance using Clone() method, And Now the copy class has everything its original class has
            MyClass myClassCopy = myClass.Clone() as MyClass;

            MySonClass my = new MySonClass();
            MySonClass mySonCopy = my.Clone() as MySonClass;


        }
    }

    //Base prototype
    class MyClass : ICloneable
    {

        private string Name;
        private string Address;
        private int Age;
        public MyClass() { }

        public object Clone()
        {
            //Creating a new instance from this existed object
            return new MyClass() { Name = Name, Address = Address, Age = Age };
        }

    }

    //Derived prototype
    class MySonClass :MyClass, ICloneable
    {
        private string NewProperties;

        public new object Clone()
        {
            //Clone all property from the base class,
            //In case that you dont want to asign the value one by one,
            //And wihout care about how many properties the base class has
            MySonClass mySonClass = base.Clone() as MySonClass;

            // Asign the NewProperty of the derived class, manually
            mySonClass.NewProperties = NewProperties;
            return mySonClass;

        }

    }

}

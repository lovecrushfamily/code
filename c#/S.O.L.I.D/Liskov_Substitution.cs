using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SOLID
{
    internal class Liskov_Substitution
    {
    }

    
    class Bird
    {
        public Bird() { }
    }

    interface IFyable
    {
         void Fly();
    }

    // The class Eagle's able to replace the class Bird, I mean its instance
    class Eagle : Bird, IFyable
    {
        public Eagle() { }
        public void Fly()
        {

        }


    }
    class Falcon : Bird, IFyable
    {
        public Falcon() { }

        public void Fly()
        {

        }
    }

    // This class can replace the class Bird, But it's not able to replace the Eagle class or Falcon Class
    class Penguin : Bird
    {
        public Penguin() { }

    }
        
}

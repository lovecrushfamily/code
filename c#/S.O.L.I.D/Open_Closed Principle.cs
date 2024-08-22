using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SOLID
{
    internal class Open_Closed_Principle
    {

    }

    //Not modify the source code of this class
    class Gun
    {

        public Gun() { }
        void Shoot() { }
        void Hit() { }
        void Fire() { }

    }


    // Extended class
    class Silencer
    {
        public Silencer() { }                             
    }

    class Scope
    {
        public Scope() { }
    }

    class Butt
    {
        public Butt() { }
    }

    class Magazine
    {
        public Magazine() { }
    }


    //IExternal components
    interface IExternal
    {
        bool Connect(Gun gun);
    }
}

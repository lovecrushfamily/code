using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SOLID
{
    internal class Interface_Segregation
    {
    }

    interface IAnimal
    {

        void Eat();
        void Sleep();
        void Drink();
    }

    interface IBird
    {
        void Fly();

    }

    interface IFish
    {
        void Swim();
    }

    class Dog : IAnimal
    {
        public Dog() { }
        public void Eat() { }
        public void Drink() { }
        public void Sleep() { }

    }

    class Dove : IAnimal, IBird
    {
        internal Dove() { }
        public void Eat() { }
        public void Drink() { }
        public void Sleep() { }
        public void Fly() { }
    }

    class Shark : IAnimal, IFish
    {
        internal Shark() { }
        public void Eat() { }
        public void Drink() { }
        public void Sleep() { }
        public void Swim() { }

    }
    class Duck :IAnimal, IFish, IBird
    {
        internal Duck() { }
        public void Eat() { }
        public void Drink() { }
        public void Sleep() { }
        public void Swim() { }
        public void Fly() { }


    }
}


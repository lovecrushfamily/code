using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Design_Pattern
{
    internal class Factory_Method
    {
        public Factory_Method()
        {
            //Solution
            //The Factory Method pattern suggests that you replace direct object
            //construction calls(using the new operator) with calls to a special factory method.
            //Don’t worry: the objects are still created via the new operator,
            //but it’s being called from within the factory method. Objects returned by a
            //factory method are often referred to as products.
        } 

        internal static void Visualization()
        {
            //create new factory instance 
            // The animal that has been created by factory depends on the instance of that factory, like DuckFactory, CatFactory
            IAnimalFactory factory = new DuckFactory();
            //This factory create a Duck because it using instance of its Subclass,
            //in this context the AnimalFactory is DuckFactory,
            //so that the Animal it created absolutely is a Duck
            factory.CreateAnimal("Duck duck");



            //How to use it
            //Step 1: Create a factory
            IAnimalFactory animalFactory;

            //Step 2:
            //Select the factory with specific business logic
            animalFactory = new DuckFactory();
            animalFactory = new CatFactory();

            //Step 3:
            //Create Animal with specific factory
            animalFactory.CreateAnimal("Configure the parameters for more complexity");
                  
           
        }
    }

    interface IAnimal { }
    class Dog : IAnimal { public Dog() { } }
    class Cat : IAnimal { public Cat() { } }
    class Duck : IAnimal { public Duck() { } }
    class Chicken : IAnimal { public Chicken() { } }

    //Create factory interface
    interface IAnimalFactory
    {
        IAnimal CreateAnimal(string parameter);
    }

    //Implement interface, Factory
    class DuckFactory : IAnimalFactory
    {
        
        public DuckFactory() { }

        public IAnimal CreateAnimal(string parameter)
        {
            //Business logic here
            return new Duck();
        }
    }

    class CatFactory : IAnimalFactory
    {
        public CatFactory() { }

        public IAnimal CreateAnimal(string parameterName)
        {
            //Business logic here
            return new Cat();
        }
    }
}

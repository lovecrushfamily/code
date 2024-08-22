using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Abstract_Factory
    {
        // The abstract factory interface declares a set of methods that
        // return different abstract products. These products are called
        // a family and are related by a high-level theme or concept.
        // Products of one family are usually able to collaborate among
        // themselves. A family of products may have several variants,
        // but the products of one variant are incompatible with the
        // products of another variant.
        internal void Visualizaion()
        {
            // Declare a IAbstractFactory object
            IAbstractFactory abstractFactory;

            // Get factory instance with specific business logic
            abstractFactory = new ConcreteFactory1();
            abstractFactory = new ConcreteFactory2();

            // Create product A or B base on requirements
            abstractFactory.CreateProductB();
            abstractFactory.CreateProductA();
        }
    }

    // Step 1 :
    // Declaring Abstract class or interface for distinct but related products Which make up a product family
    abstract class ProductA { }
    abstract class ProductB { }

    // Step 2 :
    // Declaring Concrete class  
    class ConcreteProductA : ProductA { }
    class ConcreteProductB : ProductB { }


    // Step 3
    // The Factory interface declares a set of methods for creating each of the abstract class products
    interface IAbstractFactory
    {
        void CreateProductA();
        void CreateProductB();
    }

    // Step 4 :
    // Concrete Factory implement creation methods of the abstract factory
    class ConcreteFactory1 : IAbstractFactory
    {
        public void CreateProductA() { }
        public void CreateProductB() { }

    }
    class ConcreteFactory2 : IAbstractFactory
    {
        public void CreateProductA() { }
        public void CreateProductB() { }

    }
   

}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Composite
    {
        //Use the Composite pattern when you have to implement a tree-like object structure.
        //Use the pattern when you want the client code to treat both simple and complex elements uniformly.

        public static void Visualization()
        {
            // The Client works with all elelment though the conponent interface. As a result, 
            // the client  can work in the same way  with both simple or complex elements of the tree.


            // Simple elements
            IShape rect = new Rectangle();
            IShape round = new Round();
            IShape tri = new Triangle();
           
            rect.AreaCalculate();
            round.AreaCalculate();
            tri.AreaCalculate();

            // Complex element
            IShape polygon = new Polygon();
            polygon.AreaCalculate();
            
        }
    }


    // The component Interface describes operations that are common to both simple and complex elements of the tree.
    interface IShape
    {
        void AreaCalculate();
    }

    // This kind of basic class is also call the Leaf element in the tree structure, that mean it's not have any sub-element
    class Round : IShape
    {
        public Round() { }
        public void AreaCalculate() 
        { 
            //Business logic here
        }

    }

    class Triangle : IShape
    {
        public Triangle() { }
        public void AreaCalculate() { }

    }

    class Rectangle : IShape
    {
        public void AreaCalculate() { }
    }


    /// <summary>
    /// But this's called Container or Composite element, a class has sub-elements, leaf, 
    /// </summary>
    class Polygon : IShape
    {
        // Container 
        IShape[] Shapes;

        public void AddShape( IShape shape) { }
        public void RemoveShape( IShape shape ) { }
        public void Clear() { }

        public void AreaCalculate()
        {
            //Delegate all work to child component
            // Demo besiness logic here.
            //int result = 0;
            foreach ( IShape shape in Shapes )
            {
                //result += shape.AreaCalculate();
            }
            //return result;
        }
    }
}

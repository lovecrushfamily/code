using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Mediator
    {
        public Mediator() { }

        //re implement
        public static void Visualization()
        {

            Component componentA = new ComponentA(); 
            Component componentB = new ComponentB(); 
            Component componentC = new ComponentC(); 
            Component componentD = new ComponentD();
            ConreteMediator mediator = new ConreteMediator(componentA,componentB,componentC,componentD);


            //ComponentA communicate with mediator not the componentB
            componentA.mediator.Notify(componentB);
            //mediator reacts on componentB as well.
            //mediator.ReactOnComponentB();



        }
    }

    //The mediator interface declares methods of communication with component
    //Which usually include just a single notification method.
    interface IMediator
    {
        void Notify(Component Sender);
    }

    //Concrete Mediator encapsulate relations between various components
    //Concrete Mediator often keep references to all components they manange and sometimes even manage their lifecycle
    class ConreteMediator : IMediator
    {
        Component ComponentA;
        Component ComponentB;
        Component ComponentC;
        Component ComponentD;

        public ConreteMediator(Component componentA, Component componentB, Component componentC, Component componentD)
        {
            ComponentA = componentA;
            ComponentB = componentB;
            ComponentC = componentC;
            ComponentD = componentD;
        }

        public  void Notify(Component Sender)
        {
            if (Sender == ComponentA)
            {
                ReactOnComponentA();
            }
        }
        public void ReactOnComponentA() { }
        public void ReactOnComponentB() { ComponentB.Operation(); }
        public void ReactOnComponentC() { }
        public void ReactOnComponentD() { }

    }         
    

    //Component are various classes that contain some business logic 
    //Each Component has a reference to their Mediator, declare with the type of the mediator interface 
    abstract class Component { public IMediator mediator ; public virtual void Operation() { } }
    class ComponentA : Component { public ComponentA() { } public override void Operation() { } }    
    class ComponentB : Component { public ComponentB() { } public override void Operation() { Console.WriteLine("ComponentB activated !"); } }    
    class ComponentC : Component { public ComponentC() { } public override void Operation() { } }    
    class ComponentD : Component { public ComponentD() { }  public override void Operation() { } }
                                                                
}                                                                                                  

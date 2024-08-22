using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class State
    {
        public State() { }
        public static void Visualizsation()
        {
            //Declaring states and context
            IState ready = new ReadyState();
            IState demon = new DemonState();

            //Ready state
            Context context = new Context(ready);
            context.GetState();
            context.DoThis();
            context.DoThat();
            context.Activate();
            context.KillerState();


            //Changes to the DemonState
            Console.WriteLine();
            context.changeState(demon);
            context.GetState();
            context.DoThis();
            context.DoThat();
            context.Activate();
            context.KillerState();

        }
    }

    //COncrete class Stores a references to one of the Concrete State Objects and delegates to it all state-specific work.
    //The Context communicates with the state object via the state interface
    //The context exposes a setter for passing it a new state object.
    class Context
    {
        IState state;

        //initial state at beginning
        public Context(IState state)
        {
            this.state = state;
            state.SetContext(this);
        }



        public void changeState(IState state)
        {
            this.state = state;
        } 

        public void DoThis()
        {
            state.DoThis();

        }

        public void DoThat()
        {
            state.DoThat();
        }

        public void GetState()
        {
            state.GetState();
        }

        public void Activate()
        {
            state.Activate();
        }

        public void KillerState()
        {
            state.KillerMode();

            //if (state is DemonState)
            //{
            //    state.KillerMode();
            //}
            //else
            //{
                
            //    ReadyState ready = state as ReadyState; 
            //    ready.SwitchToDemonState();
            //}
            
        }
    }

    //The State interface declares the state-specific methods. these methods should make sense for all concrete States 
    //Because you dont want some of your states to have useless methods that will never be calles
    interface IState
    {
        void SetContext(Context context);
        void DoThis();
        void DoThat();
        void GetState();
        void Activate();
        void KillerMode();
        

    }

    //Concrete States provide their own implementations for the state-specific methods, to avoid duplication
    //or simmilar code accross multiple states,
    //You may provide intermediate abstract class that encapsulate some common behavior, but in my case
    //I'm gonna provide a inteface instead of abstract class, Both of them are the same, but the way you design make it different.
    class ReadyState : IState
    {

        Context context;
        public ReadyState() { }

        public void SetContext(Context context)
        {
            this.context = context;
        }

        public void DoThat()
        {
          
            Console.WriteLine("I'm doing something in the readyState");
        }
        public void DoThis() { }

        public void GetState()
        {
            Console.WriteLine($"You're in Ready State");
        }

        public void Activate()
        {
            Console.WriteLine("Ready state activated");
        }

        public void KillerMode()
        {
            Console.WriteLine("This state do not support this feature, try again!");
        }

        //public void 
        public void SwitchToDemonState()
        {
            context.changeState(new DemonState());
        }

       

    }

    class DemonState : IState
    {
        Context context;
        public DemonState() { }

        public void SetContext(Context context)
        {
            this.context = context;
        }

        public void DoThat()
        {
            Console.WriteLine("I'm doing something in the DemonState");
        }
        public void DoThis() { }

        public void GetState()
        {
            Console.WriteLine($"You're in Demon State");
        }

        public void Activate()
        {
            Console.WriteLine("Demon state activated");
        }
        public void KillerMode()
        {

            Console.WriteLine("Killer Mode activated");
        }

    }
}

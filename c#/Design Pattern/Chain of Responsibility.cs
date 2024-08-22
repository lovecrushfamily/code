using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Security.Claims;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Chain_of_Responsibility
    {
        // - Use the Chain of Responsibility pattern when your program is expected
        //to process different kinds of requests in various ways,
        //but the exact types of requests and their sequences are unknown beforehand.
        // - Use the pattern when it’s essential to execute several handlers in a particular order.
        public void Visualization()
        {
            //Declaring the handler 
            Handler handler1 = new ConcreteHandler();
            Handler handler2 = new ConcreteHandleA();
            Handler handler4 = new ConcreteHandleC();
            Handler handler5 = new ConcreteHandleD();
            Handler handler3 = new ConcreteHandleB();

            // Client compose the Handler Dynamically
            // Creating the chain of responsibility 
            handler1.SetNext(handler2);
            handler2.SetNext(handler3);
            handler3.SetNext(handler4);
            handler4.SetNext(handler5);
            handler5.SetNext(handler3);

            // Client passes the request to handler1
            // if it's not able to handle that request then pass it though the chain
            // the order for passing the request has been created below
            handler1.handle("Pass your request here !");     
        }

    }


    //The Handler interface declares common interface for all concrete handlers
    //Usually contains just a single method for handling requests and can set the next handler on the chain
    interface Handler
    {
        void SetNext(Handler next);
        void handle(string request);
    }

    //BaseHandler class is an optional class
    //Where you can put a code that's common to all handler classes
    abstract class HandlerBase : Handler
    {
        protected Handler NextHandler;
        public HandlerBase() { }

        public void SetNext(Handler handler)
        {
            NextHandler = handler;
        }
        public virtual void handle(string request)
        {
            //business logic here
            //implementation  handler            

        }

    }


    // Concete handlers  contain actual code for processing the requests.
    class ConcreteHandler : HandlerBase
    {
        public ConcreteHandler() { }

        public void SetNext(ConcreteHandler handler)
        {
            NextHandler = handler;
        }

        public override void handle(string request )
        {

        }
    }

    //Extend the Concrete handlers for more funtionalitiies.
    class ConcreteHandleA : HandlerBase { }
    class ConcreteHandleB : HandlerBase { }
    class ConcreteHandleC : HandlerBase { }
    class ConcreteHandleD : HandlerBase { }



}

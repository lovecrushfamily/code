using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Command
    {
        public Command() { }

        public static void Visualization()
        {
            //The Client creates and configures concrete command objects, The client must pass all of the request parameters,
            // Including the reciever instance, into the Command's constructor,
            //After that, the resulting command maybe associated with one or multiple senders


            //Intergrating Reciever, Command and Invoker( which triggers the Command)
            Reciever reciever = new Reciever();
            ICommand Copy = new CopyCommand(reciever);
            ICommand Paste = new PasteCommand(reciever);
            Invoker invoker = new Invoker(Copy, Paste);

            //Triggering the command
            invoker.CopyButtonOnClick();
            invoker.PasteButtonOnClick();


        }
    }

    //The command interface usually declares just a single method for executing the Command
    interface ICommand
    {
        void Execute();
        void Undo();
    }

    //Concrete commands implement various kinds of requests.
    abstract class ConcreteCommand : ICommand
    {
        protected readonly Reciever reciever;
        public ConcreteCommand(Reciever reciever ) { this.reciever = reciever; }
        public virtual void Execute() { reciever.Execute(); }
        public virtual void Undo() { /*The Undo operation of Execute*/ }
    }

    //Extend for mmore functionality
    class CopyCommand : ConcreteCommand
    {
        public CopyCommand(Reciever reciever) : base(reciever) { }
        public  override void Execute() { reciever.Copy(); }
        public override void Undo() { /*Undo Copy*/ }
    }

    class PasteCommand : ConcreteCommand
    {
        public PasteCommand(Reciever reciever) : base(reciever) { }
        public override void Execute() { reciever.Paste(); }
        public override void Undo() { /*Undo Paste*/ }
    }                        

    //The Sender class( aka Invoker ) is responsible for initiatin requests.
    //This class must have a file for storing a reference to a Command object,
    //The Sender triggers that command instead of sending the request directly
    //to the reciever.
    //The Sender isn't responsible for creating the command object, Usually, it gets a pre-created
    //Command from the Client via Constructor.
    class Invoker
    {
        private readonly ICommand CopyCommand;
        private readonly ICommand PasteCommand;

        public Invoker(ICommand copyCommand, ICommand pasteCommand)
        {
            CopyCommand = copyCommand;
            PasteCommand = pasteCommand;
        }


        public void CopyButtonOnClick()
        {
            CopyCommand.Execute();
        }

        public void  PasteButtonOnClick()
        {
            PasteCommand.Execute();
        }

    }

    class Reciever  //Tv, radio,.. any device.
    {
        public Reciever() { }

        public void PowerOn() { Console.WriteLine("Power on"); }
        public void Execute() { Console.WriteLine("Excute"); }
        public void Copy() { Console.WriteLine("Copy"); }
        public void Paste() { Console.WriteLine("Paste"); }
        public void Undo() { Console.WriteLine("Undo"); }
    }

}

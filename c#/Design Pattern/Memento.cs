using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Memento
    {
        //In this Implementation, The Memento_ class is nested inside the originator. this lets originator have full access to all of its fields and methods.
        //Even though they declare private, On the other hand, the caretaker has very limited access to the memento's fields and methods
        public Memento() { }

        public static void MyVisualization()
        {
            Originator originator = new Originator();
            Caretaker caretaker = new Caretaker(originator);
            //Creating Originator State and Caretaker keeps tracking Originator's state
            caretaker.history.Push(originator.Save("This string represent the private state of originator !"));
            caretaker.history.Push(originator.Save("This string represent the internal state of originator !"));
            caretaker.history.Push(originator.Save("This string represent the readonly state of originator !"));
            caretaker.history.Push(originator.Save("This string represent the public state of originator !"));

            //Restore the last state of Originator
            Console.WriteLine();
            caretaker.Undo();
            caretaker.Undo();
            caretaker.Undo();



        }

        public static void Visualization()
        {
            //Creating a Player and using GoForward and GoBack to represent the object state and Undo ability.
            var Player = new Player();
            Player.GoForward();
            Player.GoForward();
            Player.GoForward();
            Player.GoForward();
            Player.GoForward();
            Player.GoForward();
            Player.GoBack();
            Player.GoBack();
            Player.GoBack();



        }
    }

    //The Orginator class can produce snapshot of its own state, as well as restore its state from snapshot when needed
    //
    class Originator
    {
        string state; //using string to represnt the state, for demonstrated
        public Originator() { }


        public Memento_ Save(string state)
        {
            this.state = state;
            GetState();
            return new Memento_(state);
        }

        public void Restore(Memento_ memento)
        {
            //Logic restore
            state = memento.state;
            GetState();


        }

        public void GetState()
        {
            Console.WriteLine(state);
        }


        //The Memento is a value object that acts as a snapshot of the originator's state. It's a common practice to make the Memento immutable
        // and pass it data only via once, via constructor.
        internal class Memento_
        {
            internal string state;
            public Memento_(string state) { this.state = state; }

            string GetState()
            {
                return state;
            }

        }
    }

    //The Caretaker knows not only "When" and "Why" to capture the Originator's state, but also when the state should be restore.
    //The CareTaker can keep track of originator's hostory by storing a stack of Mementos_.
    class Caretaker
    {
        Originator originator;
        internal Stack<Originator.Memento_> history;

        public Caretaker(Originator originator)
        {
            this.originator = originator;
            history = new Stack<Originator.Memento_>();
        }

        public void DoSomething()
        {


        }

        //Logic undo
        public void Undo()
        {
            Originator.Memento_ memento = history.Pop();
            originator.Restore(memento);


        }
    }




    // Another demonstrated from Youtube
    class Player
    {
        Stack<Position> PositionMemory = new Stack<Position>();
        Position.Piece piece = new Position.Piece();


        public Player() { }

        public void GoForward()
        {
            // Roll dice 
            var position = piece.GetPosition();
            PositionMemory.Push(position);

            Random random = new Random();
            int RandomMove = random.Next(1,6);
            piece.Move(RandomMove);
        }

        public void GoBack()
        {
            var position = PositionMemory.Pop();
            piece.SetPosition(position);
        }



    }
    class Position
    {
        int Cell;

        internal class Piece
        {

            Position _position = new Position()
            {

                Cell = 0
            };

            internal void Move(int NumberOfSteps)
            {
                _position.Cell += NumberOfSteps;
                Console.WriteLine("Moving to: "  + _position.Cell);
            }

            internal Position GetPosition()
            {

                return new Position { Cell = _position.Cell };
            }

            internal void SetPosition(Position position)
            {
                Console.WriteLine("Going back to: " + position.Cell);
                _position.Cell = position.Cell;
            }

        }
    }


}
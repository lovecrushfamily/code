using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Visitor
    {
        //use the Visitor when you need to perform an operation on all elements of a complex object structure(for example, an object tree) 
        public Visitor() { }

        public static void Visualization()
        {
            //the Client usually represents a collection or some other complex object,for instance The list<Iclient>
            InsuranceVisitor visitor = new InsuranceVisitor();

            List<ICLient> clients = new List<ICLient>()
            {
                new Company(),
                new Bank(),
                new Restaurant()
            };
            visitor.VisitAllClients(clients);

        }
    }

    //The IVisitor interface  declares a set of visiting methods that can take concrete elements of an object structure as arguments
    //These methods may have the same names if the program is written in a language supported overloading, but the type of their parameter must be different.
    interface IVisitor
    {
        void VisitBank(Bank bank);
        void VisitCompany(Company bank);
        void VisitRestaurant(Restaurant bank);
    }

    //The Concrete Visitor( in this case is InsuranceVisitor) implements several versions of the same behaviors
    class InsuranceVisitor : IVisitor
    {
        public InsuranceVisitor() { }

        public void VisitBank(Bank bank)
        {
            Console.WriteLine("Get into the bank");
        }
        public void VisitCompany(Company company)
        {
            Console.WriteLine("Get into the company");
        }
        public void VisitRestaurant(Restaurant bank)
        {
            Console.WriteLine("Get into the Restaurant");
        }
        public void VisitAllClients(List<ICLient> cLients )
        {
            foreach(ICLient client in cLients)
            {
                client.Accept(this);
            }
        }

    }

    //The IClient (Element) interface declares a method for accepting visitors. This method should have one 
    // parameters declared with the type of the Visitor interface.
    interface ICLient
    {
        void Accept(IVisitor visitor);
    }

    //Each Concrete Client should implement the acceptance method. The purpose of this method is to redirect the call
    //of the proper visitor's method corresponding to the current element class.
    //be aware that even if a base class implemnt this method, all subclass must still override this method in their own classes.
    //and call the appropriate method on the visitor object.
    class Bank : ICLient
    {
        public Bank() { }

        public void Accept(IVisitor visitor)
        {
            visitor.VisitBank(this);
        }
    }

    class Restaurant : ICLient
    {
        public Restaurant() { }

        public void Accept(IVisitor visitor)
        {
            visitor.VisitRestaurant(this);

        }

    }

    class Company : ICLient
    {
        public Company() { }

        public void Accept(IVisitor visitor)
        {
            visitor.VisitCompany(this);
        }
    }

}

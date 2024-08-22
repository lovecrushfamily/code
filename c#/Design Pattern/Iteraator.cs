using System;
using System.Collections.Generic;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    //Not complete yet

    internal class Iteraator
    {
        //The Client works with  both collections and iterators via its interfaces.
        //this Way the client isn't coupled to concrete classes, allowing you to use various collections and iterators with the same client code.
        public static void Visualization()
        {
            //Typically the client don't create iterators on their own, but instead get them from collection.
            IterableCollection collection  = new ConcreteCollection();
            Iterator iterator =  collection.CreateIterator();
            iterator.GetNext();
            iterator.GetNext();

        }

    }

    //The Iterator interface declares thhe operations required for traversing a collection: fetching the next element, retrieving
    //the current position , restarting iteration, etc...
    interface Iterator
    {
        void GetNext();
        bool hasMore();

    }

    // ConcreteIterator implements specific algorithms for traversing a collection
    // The Iterator object should track the traversal progress on it own 
    // This allows several interators to traverse the same collection independently of each other
    class ConcreteIterator : Iterator
    {
        ConcreteCollection collection;
        bool IterationState;
        public ConcreteIterator(ConcreteCollection concreteCollection)
        {
            collection = concreteCollection;
        }

        public void GetNext()
        {
            //Business logic to get the next element of the collection                                                                                  
        }

        public bool hasMore()
        {
            return true;

        }

    }

    //The Collection interface declares one of multiple methods for getting iterators compatible with the collection
    interface IterableCollection
    {
        Iterator CreateIterator();

    }

    //The Concrete Collections return new instances of a particular concrete iterator class each time the client requests one.
    class ConcreteCollection : IterableCollection
    {
        public ConcreteCollection() { }

        public Iterator CreateIterator()
        {
            //Decide a particular Iterator to return
            return new ConcreteCollection() as Iterator;
        }
    }



}

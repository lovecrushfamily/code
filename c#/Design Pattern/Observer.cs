using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Observer
    {
        public static void Visualization()
        {

            Publisher publisher = new Publisher();

            ISubscriber subscriber = new ConcreteSubscriber();
            ISubscriber subscriberA = new ConcreteSubscriber();
            ISubscriber subscriberB = new ConcreteSubscriber();

            publisher.Subscribe(subscriber);
            publisher.Subscribe(subscriberA);
            publisher.Subscribe(subscriberB);

            //Notify news to all Subscribers
            publisher.notifySubscribers("Everything for sale.");


        }
    }

    //The publisher issues events of interest to other object, Subscribers
    class Publisher
    {
        List<ISubscriber> subscribers;

        public Publisher() { subscribers = new List<ISubscriber>(); }

        public void Subscribe(ISubscriber subscriber)
        {
            subscribers.Add(subscriber);
        }

        public void UnSubscribe(ISubscriber subscriber)
        {
            subscribers.Remove(subscriber);
        }
                                   
        //When the new events happens, the publisher gose over the subscription list and calls the
        //notification list and call the notification method declared in the subscriber interface on each subscriber object
        public void notifySubscribers(string content)
        {
            //Go though the ISUbscriber List and update them
            foreach(ISubscriber subscriber in subscribers)
            {
                subscriber.Update(content);
            }
        }

    }

    interface ISubscriber
    {
        void Update(string content);
    }

    class ConcreteSubscriber : ISubscriber
    {
        public ConcreteSubscriber() { }

        public void Update(string content)
        {
            //Business logic here to notify the content to all subscribers
            Console.WriteLine("WHat's new ! in this version, " + content);
        }

        public void ExtendedFeature()
        {

        }

    }
}

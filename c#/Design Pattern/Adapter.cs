using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Adapter
    {
        public Adapter() { }

        public static void Visualization()
        {
            // I assume that Client class is the existing code of your peogram and the service is the 3rd-party service
            // And both  of them are not compatable
            // We can't use the Service directly, we can only use it via MyAdapter
            // Incompatable interface => Adapter => intergated
            Client client = new Client();
            IClientInterface adapter = new MyAdapter();
            Service service = new Service();

     
            client.UsingService(adapter);   // => commaptable
            client.UsingService(service);   // => Incompatable

        }
    }

    //The Client is a class that contain the existing business logic of the program
    class Client
    {
        internal void UsingService(IClientInterface adapter)
        {
            adapter.MethodUsingService("Using Service via MyAdapter");

        }
        internal void UsingService(Service service)
        {
            // Can not use service directly
            
        }
    }


    //The ClientInterface describes a protocol that other classes must follow to be able to collaborate with the client code
    interface IClientInterface
    {
        void MethodUsingService(string data);    
    }

    // The Service class is some useful class (usually the 3rd-party or legacy), The client can't use this class directly
    // bcause it has the imcompatible interface
    class Service
    {
        public void ServiceMethod(string data)
        {
            Console.WriteLine("Service activated !\n" + "Data : " +
                "" +  data);
        }
    }


    //Class MyAdapter is the class that's able to work with both the client class and the service,
    //It implement the IClientInterface, while wrapping the service object (in this case, I'm using inheritencs to wrap the service object),
    //The apdapter receive calls from the client via the client interface and translates
    //them into calls to the wrapped service object in a format it can understand. that was the good one.
    class MyAdapter : Service, IClientInterface
    {
        public MyAdapter() { }

        public void MethodUsingService(string data)
        {
            //besiness logic here
            //inherit from the service
            ServiceMethod(data);
        }
                                        



    }




}

using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Resources;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace Design_Pattern
{
    internal class Proxy : Visualization
    {
        // - Lazy initialization(virtual proxy).
        //This is when you have a heavyweight service object that wastes system resources
        //by being always up, even though you only need it from time to time.
        // - Access control(protection proxy).
        // This is when you want only specific clients to be able to use the service object;
        // for instance, when your objects are crucial parts of an operating system and
        // clients are various launched applications(including malicious ones).
        public Proxy() { }
        public void Visualization()
        {
            //using Server Proxy instead of the real Server
            IServer server = new ServerProxy();
            //The ServerProxy acts like the real Server 
            server.Authenticate();
            server.Configuration();
            server.Login();

        }
    }

    //The IServer interface declares the interface of the Service( in this case the service is Class Server)
    //The proxy must follow this interface to be able to disguise itself as the service object
    interface IServer
    {
        void Authenticate();
        void Login();
        void Logout();
        void ClearHistory();
        void ChangePassword();
        void Configuration();
    }

    //The class Server is a class provide some useful business logic.
    // It could be the 3rd-party library or any service...
    class Server : IServer
    {
        public void Authenticate() { }
        public void ChangePassword() { }
        public void ClearHistory() { }
        public void Configuration() { }
        public void Login() { }
        public void Logout() { }
    }

    //The proxy class has a references field that points to a service object 
    //After the ServerProxy finished its processing( custom logic ). It passes the request to the service object
    class ServerProxy : IServer
    {
        //Referenced object
        Server Server { get; set; }
        public void Authenticate() { }
        public void ChangePassword() { }
        public void ClearHistory() { }
        public void Configuration() { }
        public void Login() { }
        public void Logout() { }


        //Extra processing
        public void AccessChecking() { }
        public void AccessDeny() { }
        public void Caching() { }
        public void SomeLazyOperation() { }
        public void AccessControl() { }


    }
}
using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Bridge
    {
        Bridge() { }

        internal static void Visualization()
        {
            //Create new Client
            MyClient client = new MyClient();   

            //Create Device and Remote, intergating both of them.
            IDevice device = new Television();
            RemoteControl remoteControl = new RemoteControl(device);

            // Client interact with Remote to get the control of the device.
            client.ToggleDevice(remoteControl);
                   
        }
                                         
    }

    // Client or your request
    class MyClient
    {
        internal void ToggleDevice(RemoteControl remoteControl)
        {
            // remote control the device depend on Client request.
            remoteControl.TogglePower();

        }
    }              

    //The Abstraction provides high-level control logic.
    //It relies on the implementation object to do the actual low-level work.
    class RemoteControl
    {
        protected IDevice device;
        public RemoteControl( IDevice device) { this.device = device; }

        internal void TogglePower()
        {
            // Click on the power button
            if (device.IsConnected()) 
            {
                device.Disconnect();
            } else 
            {
                device.Connect();
            }
        }

        // others features.

    }

    //Extend the base class for more features
    class AdvanceRemoteCOntrol : RemoteControl
    {
        public AdvanceRemoteCOntrol(IDevice device): base(device) { }
        public void AdvanceFeature() {}
    }

    /// <summary>
    /// The Implementation declares the interface that’s common for all concrete implementations.
    /// An abstraction can only communicate with an implementation object via methods that are declared here.
    /// 
    /// The abstraction may list the same methods as the implementation,
    /// but usually the abstraction declares some complex behaviors that rely
    /// on a wide variety of primitive operations declared by the implementation.
    /// </summary>
    interface IDevice
    {
        bool IsConnected();
        void Connect();
        void Disconnect();
        void Start();

    }

    /// <summary>
    /// Concrete Implementations contain platform-specific code.
    /// </summary>
    class Television : IDevice
    {
        public Television() { }

        public void Connect()
        {
            //Connect to the Tv
        }
        public void Disconnect()
        {
            //Disconnectto the tv
        }
        public void Start()
        {
            //Start the Tv
        }
        public bool IsConnected()
        {
            //Check if the Tv connected or no
            return true;
        }
    }

    class Radio : IDevice
    {
        public Radio() { }

        public void Connect()
        {
            //Connect to the Radio
        }
        public void Disconnect()
        {
            //Disconnectto the Radio
        }
        public void Start()
        {
            //Start the Radio
        }
        public bool IsConnected()
        {
            //Check if the Radio connected or no
            return true;
        }
    }



}

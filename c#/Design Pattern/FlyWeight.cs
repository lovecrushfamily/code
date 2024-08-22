using System;
using System.Collections.Generic;

namespace Design_Pattern
{
    internal class FlyWeight : Visualization
    {
        public FlyWeight() { }

        public static void Visualize()
        {
            // Let send some message
            Messenger messenger = new Messenger();
            messenger.SendMesage("LoveCrush", "Hi there");
            messenger.SendMesage("Crish", "Uhm, Did we meet before ?");
            messenger.SendMesage("LoveCrush", "Yeah, I've been met you for a while in my wedding!");
            messenger.SendMesage("Crish", "Oh, really I couldn't remember anything of you!");
            messenger.SendMesage("LoveCrush", "Don't worry I have something for you, this way ma'am.");

        }

        public void Visualization()
        {
            Visualize();
        }
    }

    // this object consuming high anount of data, cuz it'll duplicate so many times.
    //The flyweight class contains the portion of the original object's state  that can be  shared between multiple objects.
    internal class Sender
    {
        public Sender() { }
        public string Name;
        public string Avatar;
    }

    //Extra functionality
    internal class ChatMessage
    {
        public string Content; //=> The fields that contain  contexual  data unique to each object 
        public Sender sender;  //=> the intrinsic state : The field that contain unchanging data duplicated accross many objects

        public ChatMessage(string Content, Sender sender)
        {
            this.Content = Content;
            this.sender = sender;

        }
        public void ShowMessage()
        {
            Console.WriteLine($"From : {sender.Name}\n" +
                                $"Avatar : {sender.Avatar}" +
                                $"\nContent: {Content}\n");

        }

    }

    //Create a factory class to manage the pool of FlyWeights, it should check for an existing 
    //flyweight before creating a new one, Once the factory is in place, client must only request
    // flyweights though it, They should decribe the desired  flyweight by passing its intricsic state to the factory
    internal class SenderFactory
    {
        //Using Dictionary to store and extract the Sender data, cuz each Sender has a unique name and Avatar
        // => SenderData = CacheSender(SenderName)
        public Dictionary<string, Sender> CacheSender;

        // Declaring a SenderFactory to store andd extract Sender Data using SenderName.
        private SenderFactory senderFactory = new SenderFactory()
        {

            CacheSender = new Dictionary<string, Sender>()
            {
                {
                    "LoveCrush", new Sender()
                                                {
                                                    Name = "Lovecrush",
                                                    Avatar = "This string represent the Avater of Lovecrush"
                                                }
                },
                {
                    "Crish" ,  new Sender()
                                                 {
                                                     Name = "Crish",
                                                     Avatar = "Crish's Avatar !"
                                                 }
                }
            }
        };

        // using SenderName to Get the Sender data
        public Sender GetSender(string SenderName)
        {
            return senderFactory.CacheSender[SenderName];
        }

    }


    internal class Messenger
    {
        public Messenger() { }
                                      
        public void SendMesage(string SenderName, string content)
        {
            SenderFactory senderFactory = new SenderFactory();
            ChatMessage chatMessage = new ChatMessage(content, senderFactory.GetSender(SenderName));
            chatMessage.ShowMessage();
            
        }
    }

}

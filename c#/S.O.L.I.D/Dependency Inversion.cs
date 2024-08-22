using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SOLID
{
    internal class Dependency_Inversion
    {
    }

    //Interface 
    interface IDataAccess
    {
        void SaveData(string data);
    }
    interface IEmailSender
    {
        void SendEmail(string email);
    }


    //Using class implement interface
    class Database : IDataAccess
    {
        public Database() { }
        public void SaveData(string data) { }  

    }

    class EmailSender : IEmailSender
    {
        public EmailSender() { }
        public void SendEmail(string email)
        {

        }
    }

    // How the high-level interact with interface
    class BusinessLogicLayer
    {
        public BusinessLogicLayer() { }

        public void SendEmail(string email)
        {
            IEmailSender emailSender = new EmailSender();
            emailSender.SendEmail(email);

        }

        public void SaveData()
        {
            IDataAccess dataAccess = new Database();
            dataAccess.SaveData("My data");
        }
    }


}

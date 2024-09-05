using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    internal class Delegate
    {
        Delegate()
        {
            MyFunc("Here's how to use delegate to reach callback function", CallBackFunc);
        }

        //Just declare a funtion poiter so that we can pass it as a parameters into a function
        delegate void CallBack(string Call);
        //delegate  + return_type + delegate_name + (parameters)

        
        void CallBackFunc(string Call)
        {
            Console.WriteLine(Call);
        }

        void MyFunc(string greet, CallBack callBack)
        {
            Console.WriteLine(greet);
            callBack("Hi, I'm delegate or might also known as Callback function");
        }

    }

    internal class Action_
    {
        public Action_()
        {
            MyFunc(CallBackFunc, "Action is a way to implement delegate with void return_type");
        }

        void CallBackFunc(string param)
        {
            Console.Write(param);
        }

        void MyFunc(Action<string> callbackfunc, string param)
        {
            callbackfunc("How to use action ");
            Console.WriteLine(param);
        }


    }

    internal class Predicate_
    {
        public Predicate_()
        {
            MyFunc(CallbackFunc, "Using predicate");
        }

        bool CallbackFunc(string param)
        {
            Console.WriteLine("How to use predicate " + param);
            return true;
        }

        void MyFunc(Predicate<string> callbackfunc, string param)
        {
            Console.WriteLine("predicate used to implement delegate with the bool return_type");
            Console.WriteLine(callbackfunc("Predicate"));
        }

    }

    internal class Func_
    {
        public Func_()
        {
            MyFunc(CallBackFunc, "Did you see that");
        }

        int CallBackFunc(int num)
        {
            return num;
        }

        void MyFunc(Func<int,int> func, string pra)
        {

            Console.WriteLine("Func commonly using to implement delegate with the custom return type");
            Console.WriteLine("Did you see that !");
            Console.WriteLine(func(404));
        }

    }
}

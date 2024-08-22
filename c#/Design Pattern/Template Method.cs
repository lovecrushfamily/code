using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Template_Method
    {
        public Template_Method() { }

        public static void Visualization()
        {
            MyMethod myMethod = new LoveMethod();
            myMethod.ExecuteAllSteps();
            myMethod = new CrushMethod();
            myMethod.ExecuteAllSteps();

        }
    }

    //The abstract class declares methods that act as steps of an algorithm, as well as the actual template method which calls these methods
    //the steps may either be declare abstract or have some defaut implement.
    abstract class MyMethod
    {
        public MyMethod() { }

        public void TemplateMethod() { }

        public abstract void Step1();
        public abstract void Step2() ;
        public abstract void Step3() ;
        public virtual void Step4() { Console.WriteLine("Default implementation of Step 4"); }
        public abstract void Step5() ;
        public abstract void Step6() ;

        public virtual void ExecuteAllSteps()
        {
            //The original order of steps should be run, but it can be overrided
            Step1();
            Step2();
            Step3();
            Step4();
            Step5();
            Step6();
        }

    }

    //COncrete class can override all of the steps, but not the template itself.
    class LoveMethod : MyMethod
    {
        public LoveMethod() { }

        public override void Step1()
        {
            Console.WriteLine("Step 1 overrided by Love Method");
        }

        public override void Step2()
        {
            Console.WriteLine("Step 2 overrided by Love Method");
        }

        public override void Step3()
        {
            Console.WriteLine("Step 3 overrided by Love Method");
        }


        public override void Step5()
        {
            Console.WriteLine("Step 5 overrided by Love Method");
        }

        public override void Step6()
        {
            Console.WriteLine("Step 6 overrided by Love Method");
        }
    }

    class CrushMethod : MyMethod
    {
        public CrushMethod() { }

        public override void Step1()
        {
            Console.WriteLine("Step 1 overrided by Crush Method");
        }

        public override void Step2()
        {
            Console.WriteLine("Step 2 overrided by Crush Method");
        }

        public override void Step3()
        {
            Console.WriteLine("Step 3 overrided by Crush Method");
        }

        public override void Step4()
        {
            Console.WriteLine("Step 4 overrided by Crush Method");
        }

        public override void Step5()
        {
            Console.WriteLine("Step 5 overrided by Crush Method");
        }

        public override void Step6()
        {
            Console.WriteLine("Step 6 overrided by Crush Method");
        }
        public override void ExecuteAllSteps()
        {

            Step3();
            Step6();
            Step2();
            Step4();
            Step1();
            Step5();
        }
    }
}

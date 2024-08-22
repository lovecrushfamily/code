using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Decorator
    {
        public Decorator() { }

        public static void Visualization()
        {
            //Creating a Dynamic mixure of those decorator
            var BubbleWhiteSugarMilktea = new Bubble(
                                            new WhileSugar(
                                                new MilkTea()));
            Console.WriteLine("BubbleWhiteSugarMilkTea cost : " + BubbleWhiteSugarMilktea.Cost() + '$');

            // You can create more decorator and more connfigure to get more dynamic MilkTeas
        }
    }

    //Declare a common interface for the wrappers and the wrapped objects.
    interface IMilkTea
    {
        int Cost();
    }

    //Create the MilkTea class, Which's being wrapped, It defines the basic behavior, 
    // Which can be alterded by Decorators (MilkTeaDecorator)
    class MilkTea : IMilkTea
    {
        int OriginalCostMilkTea = 10;
        public int Cost()
        {
            return OriginalCostMilkTea;
        }
    }

    //The basic Decorator has a field for referencing  a wrapped object.
    //The field' type should be declared  as  the component interface so it can contain both concrete component(MilkTea)
    //and Decorator(MilkTeaDecorator) 
    // The base decorators delegates all operations to the wrapped object.
    abstract class MilkTeaDecorator : IMilkTea
    {
        IMilkTea MilkTea;

        // 
        protected MilkTeaDecorator(IMilkTea inner) 
        { 
            MilkTea = inner; 
        } 

        public virtual int Cost()
        {
            return MilkTea.Cost();
        }
    }

    //COncrete decorators define extra behavior that  can be added to components dynamically.
    //(Bubble, BlackSugar,... extend for more)
    //Concrete decorators override methods of the base decorator and excute  their behavior either  before  
    //or after calling the parent method (ex_ : the Cost() method)
    // Translate : ý là các decorators về sau khi muốn triển khai thì phải ghi đè cái hàm Cost() này
    // hàm Cost() là ví dụ trong bài này, hàm Cost này chỉ là 1 hành vi cơ bản được định nghĩa trong Interface thôi
    // tại sao lại dùng hamg này, Mục đích là để demo cái việc bọc xem nó sẽ khác nhau như nào
    // Khi thêm topping đồng nghĩa với thêm giá tiền, bọc cái gì thì sẽ tính tiền cái đấy.
    // Các bài khác sẽ có các yêu cầu, vấn đề mở rộng khác nhau, bản chất vẫn là đạt được khả năng compose được dynamic object 
    // using decorator design pattern.
    class Bubble : MilkTeaDecorator
    {
        int BubbleCost = 1;
        public Bubble(IMilkTea inner) : base(inner) { }

        public override int Cost()
        {
            return base.Cost() + BubbleCost;
        }
    }

    class BlackSugar : MilkTeaDecorator
    {
        int BlackSugarCost = 5;

        public BlackSugar(IMilkTea inner) : base(inner) { } 

        public override int Cost()
        {
            return BlackSugarCost + base.Cost();
        }
    }

    class WhileSugar : MilkTeaDecorator
    {
        int WhileSugarCost = 15;

        public WhileSugar(IMilkTea inner) : base (inner) { }

        public override int Cost()
        {
            return base.Cost() + WhileSugarCost;
        }
    }

    class Pudding : MilkTeaDecorator
    {
        int PuddingCost = 20;

        public Pudding(IMilkTea inner) : base(inner) { }

        public override int Cost()
        {
            return base.Cost() + PuddingCost;
        }
    }




}

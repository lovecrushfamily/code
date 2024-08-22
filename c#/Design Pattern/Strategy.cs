using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Strategy
    {

        public static void Visualization()
        {
            // The Client creates a specific strategy object and pastes it to the navigator.
            // The Navigator exposes a setter which lets clients replace the strategy associated with the Navigator at runtime. 

            IRouteStrategy walk = new WalkingStrategy();
            IRouteStrategy road = new RoadStrategy();

            Naviagator naviagator = new Naviagator(walk);
            naviagator.BuildRoute("My house", "City centre");
            naviagator.SetStrategy(road);
            naviagator.BuildRoute("My house", "City centre");

        }
    }

    //The navigator maintain a reference to one of the concrete strategies and conmunicate with this object via the strategy interface
    class Naviagator
    {
        IRouteStrategy routeStrategy;

        public Naviagator(IRouteStrategy routeStrategy)
        {
            this.routeStrategy = routeStrategy;
        }

        public void SetStrategy(IRouteStrategy routeStrategy)
        {
            this.routeStrategy = routeStrategy;
        }

        public void BuildRoute(string begin, string end)
        {
            routeStrategy.BuildRoute(begin, end);
        }

    }

    //The strategy interface is common to all concrete strategies. it declares a method the Navigator uses to execute a stratergy.
    interface IRouteStrategy
    {
        void BuildRoute(string begin, string end);
    }

    //Concrete Strategies implement different variations of an algorithm the context uses
    class RoadStrategy : IRouteStrategy
    {
        public void BuildRoute(string begin, string end)
        {
            Console.WriteLine("This route was built by Road Strategy");
            Console.WriteLine($"From {begin} to {end}");
        }

    }

    class WalkingStrategy : IRouteStrategy
    {
        public void BuildRoute(string begin, string end)
        {
            Console.WriteLine("This route was built by Walking Strategy");
            Console.WriteLine($"From {begin} to {end}");

        } 
    }

    class PublicTransport : IRouteStrategy
    {
        public void BuildRoute(string begin, string end)
        {
            Console.WriteLine("This route was built by Public Transport Strategy");
            Console.WriteLine($"From {begin} to {end}");
        }
    }
}

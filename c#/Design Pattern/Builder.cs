using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Builder
    {
        //Builder is a creational design pattern that lets you construct complex
        //objects step by step.The pattern allows you to produce different types
        //and representations of an object using the same construction code.
        public Builder() { }
        internal void Visualization()
        {
            // Normal constructor
            Car myCar = new Car(4,
                                new SeatBelt(),
                                "Black",
                                new WindScreen(),
                                new Engine());

            // Constructor using Builder design pattern
            // Did you see that, the readability, 
            Car CarBuilder = new CarBuilder()
                                .AddWheels(4)
                                .AddSeatBelt(new SeatBelt())
                                .AddColor("Black")
                                .AddWindScreen(new WindScreen())
                                .AddEngine(new Engine())
                                .Build();



        }

    }

    // Car components
    class SeatBelt { }
    class WindScreen { }
    class Engine { }

    class Car
    {
        public int NumberOfWheels { get; set; }
        public SeatBelt seatBelt { get; set; }
        public string Color { get; set; }
        public WindScreen WindScreen { get; set; }
        public Engine Engine { get; set; }

        public Car(int numberOfWheels,
                    SeatBelt seatBelt,
                    string color,
                    WindScreen WindScreen,
                    Engine Engine)
        {

        }
    }


    interface ICarBuilder
    {
        CarBuilder AddWheels(int numberOfWheels);
        CarBuilder AddSeatBelt(SeatBelt seatBelt);
        CarBuilder AddColor(string color);
        CarBuilder AddWindScreen(WindScreen windScreen);
        CarBuilder AddEngine(Engine engine);
        Car Build();


    }

    // Implement Builder design pattern
    class CarBuilder : ICarBuilder
    {
        public int NumberOfWheels { get; set; }
        public SeatBelt SeatBelt { get; set; }
        public string Color { get; set; }
        public WindScreen WindScreen { get; set; }
        public Engine Engine { get; set; }

        public CarBuilder AddColor(string color)
        {
            Color = color;  
            return this;
        }

        public CarBuilder AddEngine(Engine engine)
        {
            Engine = engine;
            return this;
            
        }

        public CarBuilder AddSeatBelt(SeatBelt seatBelt)
        {
            SeatBelt = seatBelt;
            return this;

        }

        public CarBuilder AddWheels(int numberOfWheels)
        {
            NumberOfWheels = numberOfWheels;
            return this;
            
        }

        public CarBuilder AddWindScreen(WindScreen windScreen)
        {
            WindScreen = windScreen;
            return this;
            
        }

        public Car Build()
        {
            return new Car(NumberOfWheels,SeatBelt,Color,WindScreen,Engine);
        }
    }
}

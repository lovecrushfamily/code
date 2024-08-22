using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Design_Pattern
{
    internal class Facade
    {
        //Facade is a structural design pattern that provides a simplified interface to a library,
        //a framework, or any other complex set of classes.
        public static void Visualization()
        {
            //using Facade interface instead of using these SUbsystem directly
            FacadeInterdace  facadeInterdace = new FacadeInterdace();
            facadeInterdace.SubsystemMethod("Custom parameter for more complexity");

        }
    }


    // Some kind of subsystem you want to facade
    class Subsystem { }
    class ComplexClass { }
    class FrameWork { }
    class LegacyCode { }
    class ThirdPartyCode { }


    //Simple interface to work with all of these subsystem above
    class FacadeInterdace
    {
        internal FacadeInterdace() { }

        internal void SubsystemMethod(string para)
        {
            //using para or something else to work with these subsystems
            Subsystem subsystem = new Subsystem();
            FrameWork frameWork = new FrameWork();
            LegacyCode code = new LegacyCode();
            ThirdPartyCode thirdPartyCode = new ThirdPartyCode();
                                                                                     
        }

    }


}



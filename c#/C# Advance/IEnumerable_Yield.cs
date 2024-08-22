using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Advance_C_
{
    internal class IEnumerable_Yield
    {
        public IEnumerable_Yield()
        {
            //int[] nums = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 10 };

            //foreach (int i in nums)
            //{
            //    Console.WriteLine(i);
            //}
            
            foreach( var item in GetNumber())
            {
                Console.WriteLine(item);
            }
            //Console.WriteLine(GetNumber().Count());    
            
        }

        IEnumerable<int> GetNumber()
        {
           
            for(int i = 0;i < 20; i++)
            {
                if(i % 2 == 0)
                {
                    
                    yield return i;
                }

                if(i == 10)
                {
                    yield break;
                }
            }

            
        }
    }
}

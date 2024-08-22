using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Advance_C_
{
    public class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public string Age { get; set; }

        public override bool Equals(object obj)
        {
            Student Student = obj as Student;
            return Id.Equals(Student.Id) &&
                Name.Equals(Student.Name) &&
                Age.Equals(Student.Age);
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }

    static class DeepCompare
    {
        //using DeepEquals to compare two student instance 
        public static bool DeepEquals( this Student obj, Student another )
        {
            if (ReferenceEquals(another, null)) { return true; }

            if ((obj == null) || (another == null)) return false; 

            if (obj.GetType() != another.GetType()) return false;

            var result = true;

            foreach ( var property in obj.GetType().GetProperties() )
            {
                var objvalue = property.GetValue(obj);
                var anotherValue = property.GetValue(another);
                if(!objvalue.Equals(anotherValue)) result = false;
            }
            return result;
        }               

        // using DeepEquals to comapre two object, withour think about the class it's belonged
        public static bool DeepEquals(this object obj, object another)
        {
            if (ReferenceEquals(obj, another)) return true;
            if ((obj == null) || (another == null)) return false;
            if (obj.GetType() != another.GetType()) return false;

            if (!obj.GetType().IsClass) return obj.Equals(another);

            var result = true;

            foreach (var property in obj.GetType().GetProperties())
            {
                var objvalue = property.GetValue(obj);
                var anotherValue = property.GetValue(another);

                //Recursion 
                if(!objvalue.DeepEquals(anotherValue)) result = false;

            }

            return result;
        }

        // Using DeepEqualList to compare two list(even element is a class object)
        public static bool DeepEqualList<T>(this IEnumerable<T> obj, IEnumerable<T> another)
        {
            if (ReferenceEquals(obj, another)) { return true; }
            if ((obj == null) || (another == null)) return false;

            bool result = true;
            // Traversal two list using IEnummerator technique
            using (IEnumerator<T> enummerator1 = obj.GetEnumerator())
            using (IEnumerator<T> enummerator2 = another.GetEnumerator())
            {
                while (true)
                {
                    bool hashNext1 = enummerator1.MoveNext();
                    bool hashNext2 = enummerator2.MoveNext();

                    // If one list end first, or catch two differences element => break the loop 
                    if (hashNext1 != hashNext2 || !enummerator1.Current.DeepEquals(enummerator2.Current))
                    {
                        return false;
                        //break;
                    }

                    // End loop when two list come to an end
                    if (!hashNext1) break;
                }
            }
            return result;
        }
    }

    
    internal class Deep_Compare
    {
        Student student1 = new Student()
        {
            Id = 1,
            Name = "Love",
            Age = "19"
        };

        Student student2 = new Student()
        {
            Id = 1,
            Name = "Love",
            Age = "19"
        };

        internal Deep_Compare()
        {
            // => False because the equals func compare two reference not its value, Two obj always have the different references
            // => True after override so now it compare the value, not the references,

            Console.WriteLine("Two object always have differences references or hashcode: \n" +
                "Hash code student 1" + student1.GetHashCode() + "\n" +
                "Hash code student 2" + student2.GetHashCode());
            Console.WriteLine("Using Equals built-in func to compare(overrided): " + student1.Equals(student2));
            Console.WriteLine("using DeepEqual Extension Method to compare: " + student1.DeepEquals(student2));


            List<Student> list1 = new List<Student> { student1, student2 };
            List<Student> list2 = new List<Student> { student1, student2 };

            Console.WriteLine("using DeepEquallist to compare two list( even it contain a user_define class): "+list1.DeepEqualList(list2));

          
        }
    }
}

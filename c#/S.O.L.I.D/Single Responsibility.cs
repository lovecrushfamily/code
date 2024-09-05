using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SOLID
{
    internal class Single_Responsibility
    {
    }

    //Student chỉ chứa thông tin
    class Student
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Age { get; set; }
        public Student() { }
    }


    //Class này chỉ lấy và hiển thị thông tin về học sinh
    class ShowStudentInfo
    {
        internal int GetStudentId(Student student)
        {
            return student.Id;
        }

            internal string GetStudentName(Student student)
            {
                return student.Name;
            }










        internal int GetStudentAge(Student student)
        {
            return student.Age;
        }

        internal IEnumerable<string> GetAllStudentInformation(Student student)
        {
            yield return student.Id.ToString();
            yield return student.Name;
            yield return student.Age.ToString();
        }
    }

    class StoreStudentInfo
    {
          //using this class only for store student information
    }

    


}

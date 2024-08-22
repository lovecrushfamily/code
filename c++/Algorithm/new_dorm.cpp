#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
    private:
        string name, age, class_code, room_code;

    public:
        Student(string name, string age, string class_code, string room_code)
        {
            this -> name = name;
            this -> age = age;
            this -> class_code = class_code;
            this -> room_code = room_code;
        }
};

class Manage
{
    private:
        string name, age, manage_code, room_manage_code;

    public:
        Manage(string name, string age, string manage_code, string room_manage_code)
        {
            this -> name = name;
            this -> age = age;
            this -> manage_code = manage_code;
            this -> room_manage_code = room_manage_code;
        }
};

class Room
{
    private:
        string room_code, max_sl, state, manage_code;
    public:
        Room(string room_code, string max_sl, string state, string manage_code)
        {
            this -> room_code = room_code;
            this -> max_sl = max_sl;
            this -> state = state;
            this -> manage_code = manage_code;

        }
};
int main()
{

    return 0;
}
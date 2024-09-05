#include<iostream>
#include<vector>
#include<cmath>
#include <chrono>
#include <thread>


using namespace std;


int main(){

	srand((unsigned) time(NULL));

    string str = "hello world, lovecrush";
    string result = "";
    char ran_char = 'h';
    for (char ch : str) {

        while (ran_char != ch && ch != ' ' && ch != ',') 
        {
            ran_char = char(97 + rand() % 26);
            cout << result + ran_char << '\n';

            this_thread::sleep_for(chrono::milliseconds(40));
        }
        result = result + ch;
        cout << result << '\n';

    }


    cout <<'\n';
    return 0;


    


}

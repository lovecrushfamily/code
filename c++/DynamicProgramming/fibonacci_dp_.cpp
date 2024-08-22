#include<iostream>
#include<unordered_map>

using namespace std;

unordered_map<int, int> memorize;

/**
 * The above function calculates the Fibonacci sequence using a top-down approach with memoization.
 * 
 * @param input The input parameter represents the position of the Fibonacci number that we want to
 * calculate. For example, if input is 5, the function will calculate the 5th Fibonacci number.
 * 
 * @return the nth Fibonacci number.
 */
int fibonacci_top_down(int input){
    if (input < 3){
        return input - 1;
    }

    if(memorize.find(input) != memorize.end()){
        return memorize[input];
    }

    memorize[input] = fibonacci_top_down(input - 1) + fibonacci_top_down(input - 2 );
    return memorize[input];

}

int main(){

    int input; cin >> input;

    memorize[0] = 0;
    memorize[1] = 1;
    cout << "The " << input <<"th Fibonacci number is: "<<  fibonacci_top_down(input);
    return 0;
}
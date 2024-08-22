#include<iostream>

using namespace std;

/**
 * The above function calculates the Fibonacci sequence for a given number.
 * 
 * @param number The parameter "number" represents the position of the Fibonacci number in the sequence
 * that we want to find.
 * 
 * @return the nth number in the Fibonacci sequence.
 */
int fibonacci(int number){
    if (number < 2){
        return number;
    }return fibonacci(number - 1) + fibonacci(number - 2);
    
}

int main(){
    //demo ten fibonacci number 
    //1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    int input; cin >> input;
    cout <<"The fibonacci number at " << input << "th is: "  << fibonacci(input);

}
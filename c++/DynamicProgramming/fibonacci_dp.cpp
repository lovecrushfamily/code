#include<iostream>
#include<vector>

using namespace std;

/**
 * The function calculates and prints the nth Fibonacci number using an iterative approach.
 * 
 * @param input The input parameter is an integer that represents the position of the Fibonacci number
 * to be calculated.
 */
void fibonacci_bottom_up(int input){

    vector<int> arr(input);
    arr[0] = 0;
    arr[1] = 1;

    for (int i = 2; i < input; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    }

    cout << "The " << input <<"th Fibonacci number is: "<< arr.back();
}

int main(){

    int input; cin >> input;
    fibonacci_bottom_up(input);

    return 0;
}
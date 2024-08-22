#include<iostream>
#include<cmath>

using namespace std;

int sumOfSquareNumbers(int number){
    if (number > 0){
        cout << pow(number,2) << " + ";
        return sumOfSquareNumbers(number - 1) + pow(number, 2);
    }
    cout << "\b\b= ";
    return 0;
}

int main(){

    int input; cin >> input;
    cout<< "Sum of: " << sumOfSquareNumbers(input);

}
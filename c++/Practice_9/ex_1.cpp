#include<iostream>

using namespace std;

int sumOfNumbers(int number){
    if (number > 0){
        cout << number << " + ";
        return sumOfNumbers(number - 1) + number;
    }
    cout << "\b\b= ";
    return 0;
}

int main(){

    int input; cin >> input;
    cout<< "Sum of: " << sumOfNumbers(input);

}
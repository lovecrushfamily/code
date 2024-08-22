#include<iostream>

using namespace std;

unsigned int pow(int number, int power){
    if (power > 1){
        return pow(number, power - 1) * number;
    }
    return number;
}

int main(){

    int number, power;
    cout << "Number: ";
    cin >> number;
    cout << "Power: ";
    cin >> power;
    cout << number << " to the power of "<< power <<": " <<  pow(number, power);

}
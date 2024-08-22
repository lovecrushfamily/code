#include<iostream>

using namespace std;

float greatestOddDivisor(int number){
    if (number % 2 == 0){
        return greatestOddDivisor(number/ 2);
    }return number;
}

int main(){

    int input;cout<< "Number: "; cin >> input;
    cout << "Greatest Odd Divisor of "<< input << " is" <<  greatestOddDivisor(input);

}
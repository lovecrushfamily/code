#include<iostream>

using namespace std;

int countDigitsOfNumber(int number){
    if (number%10){
        return countDigitsOfNumber(number/10) + 1;
    }return 0;
}

int main(){

    int number;cout<< "Number: "; cin >> number;
    cout <<"The number above has "<< countDigitsOfNumber(number) << " digits";
    
    

}
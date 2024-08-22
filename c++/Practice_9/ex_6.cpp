#include<iostream>

using namespace std;

int GreatestCommonDivisor(int firstNumber, int secondNumber){
    if (firstNumber > secondNumber){
        return GreatestCommonDivisor(firstNumber - secondNumber, secondNumber);
    }else if (firstNumber < secondNumber){
        return GreatestCommonDivisor(firstNumber, secondNumber - firstNumber );
    }
    return firstNumber;
}

int LeastCommonMutiple(int firstNumber, int secondNumber){
    return firstNumber * secondNumber / GreatestCommonDivisor(firstNumber, secondNumber);
}

int GCDIterativeApproach(int firstNumber, int secondNumber){
    int temp;
    //In case: firstNumber greater than secondNumber; just theory
    while (firstNumber % secondNumber != 0)
    {
        /* code */
        temp = firstNumber % secondNumber;
        firstNumber = secondNumber;
        secondNumber = temp;
    }
    return secondNumber;
    
}

int main(){

    int firstNumber, secondNumber;
    cout << "First number: ";cin >> firstNumber;
    cout << "Second number: ";cin >> secondNumber;
    cout <<"The Greatest Common Divisor: " << GCDIterativeApproach(firstNumber, secondNumber);
    cout <<"\nThe Least Common Multiple: " << LeastCommonMutiple(firstNumber, secondNumber);
    

    
}
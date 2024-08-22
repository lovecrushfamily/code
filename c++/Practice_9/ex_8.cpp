#include<iostream>
#include<cmath>
using namespace std;

/**
 * The function computes the square root of the sum of a range of numbers.
 * 
 * @param numberStart The starting number of the expression.
 * @param numberEnd The ending number of the expression.
 * 
 * @return the square root of the expression.
 */
float computeTheExpression(int numberStart, int numberEnd){
    if ( numberStart == numberEnd ){
        return sqrt(numberStart);
    }else{
        return sqrt(numberStart + computeTheExpression(numberStart + 1, numberEnd));
    }
}

int main(){

    float input;cout<< "Positive Number: " ;cin >> input;
    cout<<"Result: "<< computeTheExpression(1, input);

}    
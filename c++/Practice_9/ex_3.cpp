#include<iostream>

using namespace std;

double sumOfOneNumbers_th(int number){
    if (number > 0){
        cout << "1/" << number << " + ";
        return sumOfOneNumbers_th(number - 1) + 1.0/number;
    }
    cout << "\b\b= ";
    return 0;
}

int main(){

    int input; cin >> input;
    cout << "Sum of: " << sumOfOneNumbers_th(input);

}
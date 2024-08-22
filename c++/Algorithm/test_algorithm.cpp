#include<iostream>

using namespace std;



int main(){
    int sum;cout << "Sum of them: "; cin >> sum;
    int difference;cout << "Difference between them: " ;cin >> difference;

    int smallNumber = sum / 2;
    int bigNumber =  sum / 2;
    while (bigNumber - smallNumber < difference )
    {
        bigNumber++;
        smallNumber--;
    }
    cout << "MyResults is : "<< bigNumber << " and " << smallNumber; 
    

    
    
    
    
}
#include <iostream>
#include <string>
#include <cmath>
// #include <stdio.h>

using namespace std;



int main(){
    int size; cin >> size;
    int *firstArray = new int[size];
    cout << "\nThe address of this fisrtAraay: " << firstArray << '\n';
    for ( int i = 0; i < size; i++){
        *(firstArray + i) = i;
    }

    for ( int i = 0; i < size; i++){
        cout << *( firstArray + i )<< ' ';
    }

    int position;cout << "position : ";cin >> position;
    int value; cout << "value : "; cin >> value;

    int *newArr = new int[size + 1];
    for (int i = 0; i < size ; i++){
        if ( i < position){
            newArr[i]  = firstArray[i];
        }else if ( i >= position){
            newArr[i + 1] = firstArray[i];
        }
    }
    newArr[position] = value;
    delete[] firstArray;
    firstArray = newArr;
    delete[] newArr;
    

    cout << "after appendn\n";
    for ( int i = 0; i < size + 1; i++){
        cout << *( newArr + i )<< ' ';
    }
    cout << "\nThe address of this fisrtAraay: " << firstArray;
    delete[] firstArray;


    
    
    
}
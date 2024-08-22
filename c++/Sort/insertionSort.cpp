#include <iostream>
#include <vector>
using namespace std;

/**
 * The insertionSort function implements the insertion sort algorithm to sort a vector of integers in
 * ascending order.
 * 
 * @param input The input parameter is a reference to a vector of integers.
 */
void insertionSort(vector<int> &input){
    int temp, j;
    for ( int i = 1; i < input.size(); i++){
        if (i == 3 ){
            break;
        }

        temp = input[i];
        j = i - 1;
        while( j >= 0 && temp > input[j]){
            input[j+ 1] = input[j];
            j--;
        }
        input[j+1] = temp;
    }
}
int main()
{
    vector<int> test = { 10,1,21,24,-9,8,7,5};
    insertionSort(test);
    for ( int i : test){
        cout << i << ' ';
    }
    
    


}   
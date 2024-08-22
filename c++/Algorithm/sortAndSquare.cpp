#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
// #include <algorithm>
using namespace std;

/**
 * The function takes a vector of integers, squares each element, and sorts the vector in
 * non-decreasing order.
 * 
 * @param input A reference to a vector of integers that needs to be sorted and squared.
 */
void sortAndSquare(vector<int>& input){
    int left = 0, right = input.size() - 1;
    while (right)
    {
        /* code */
        if ( pow(input[left], 2) >= pow(input[righEt], 2)  ){
            input[left] = pow(input[left], 2);
            swap(input[left], input[right]);
            
        }else{
            input[right] = pow(input[right], 2) ;
            
        }
        right--;
    }   
}
int main()
{
    vector<int> test = {-11, -1, 0, 3, 10};
    sortAndSquare(test);
    for ( auto e : test){
        cout << e << ' ';
    }
    // cout << pow(4,2);
    
    


}
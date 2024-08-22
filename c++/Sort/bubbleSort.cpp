#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

/**
 * The function "bubble" takes in a vector of integers and sorts it in ascending order using the bubble
 * sort algorithm.
 * 
 * @param test A vector of integers that needs to be sorted in ascending order using the bubble sort
 * algorithm.
 * 
 * @return a vector of integers.
 */
vector<int> bubble(vector<int> test) {
    bool ordered = true;
    while (ordered){
        ordered = false;
        for ( int i = 0; i < test.size() - 1; i++){
            if ( test[i] > test[ i + 1 ]){
                swap( test[i], test[ i + 1]);
                ordered = true;
            }
        }
    }
    return test;
}
int main()
{
    vector<int> test = { 4,5,6,7,1,7,2,9};
    vector<int> ordered = bubble(test);
    for ( int i : ordered){
        cout << i << ' ';
    }
    
    


}
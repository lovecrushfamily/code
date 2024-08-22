#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
// #include <algorithm>
using namespace std;


/**
 * The function reverseString takes a string as input and returns the reversed version of the string.
 * 
 * @param input The input parameter is a reference to a string.
 * 
 * @return the reversed string.
 */
string reverseString(string& input){
    int i = 0, j = input.size() - 1 ;
    while ( i < j){
        swap(input[i],input[j]);
        i++;
        j--;
    }
    return input;

}
int main()
{
    string test; cin >> test;
    cout << reverseString(test);
    
    
    


}
#include <iostream>
#include <string>

using namespace std;


/**
 * The function "swapCase" takes a string as input and swaps the case of each character in the string.
 * 
 * @param input The input parameter is a reference to a string( English string).
 */
void swapCase(string &input){
    for ( int i = 0; i < input.size(); i++){
        if (( input[i] > 'A') && (input[i] < 'Z')){
            input[i] += 32;}
        else if (( input[i] > 'a') && (input[i] < 'z')){
            input[i] -= 32;} 
    }
}
int main()
{   
    string input; getline( cin, input);
    cout << "before change case: " << input << '\n';
    swapCase(input);
    cout << "after change case:  " << input;
    return 0;
}
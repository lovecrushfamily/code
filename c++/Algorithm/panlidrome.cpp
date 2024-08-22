#include <iostream>
#include <string>

using namespace std;

/**
 * The function checks if a given string is a palindrome by comparing characters from both ends.
 * 
 * @param input The input parameter is a string that represents the word or phrase that we want to
 * check if it is a palindrome.
 * * Oh that's would be so confuse right now
 * ! I can do this line
 * @return a boolean value. It returns true if the input string is a palindrome (reads the same
 * forwards and backwards), and false otherwise.
 */

    

bool palindrome(string input){ 
    int right = input.length() - 1;
    int left = 0;
    while (right > left)
    {
        /* code */
        if ( input[left] != input[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
    
}
int main()
{
    string input; getline( cin, input);
    cout << palindrome(input);

}
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <list>
// #include <algorithm>
using namespace std;

/**
 * The function checks if a given string is a substring of another string.
 * 
 * @param str The main string in which we want to check for the presence of a substring.
 * @param sub The "sub" parameter is a string that represents the substring we want to check for in the
 * "str" parameter.
 * 
 * @return a boolean value. It returns true if the substring "sub" is found within the string "str",
 * and false otherwise.
 */
bool checkSubString(string str,string sub){
    int i = 0, j = 0;

    while (j < str.size() && i < sub.size())
    {
        if (str[j] == sub[i]){
            i++;
            j++;
        } else { j++;}
    }
    return i == sub.size();    
}
int main()
{
    string dadStr  = "sdsfsdfyorerwrur mine";
    string subStr  = "your";
    cout << checkSubString(dadStr, subStr);
    

    
    


}
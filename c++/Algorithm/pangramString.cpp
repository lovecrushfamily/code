#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<unordered_map>
#include<map>

using namespace std;

/**
 * The function "pangramString" checks if a given string is a pangram, meaning it contains all the
 * letters of the alphabet.
 * 
 * @param test The parameter "test" is a string that represents the input string that we want to check
 * if it is a pangram.
 * 
 * @return a boolean value. It returns true if the input string is a pangram (contains all the letters
 * of the alphabet), and false otherwise.
 */
bool pangramString(string test){

    set<char> temp;
    for (int i = 97; i <= 122; i++){
        temp.insert(i);
    }

    for ( char ele : test){
        if (temp.find(ele) != temp.end()){
            temp.erase(temp.find(ele));
        }
    }
    return (temp.size() == 0);
}

int main(){
    // set<int> test;
    string test = "thequickbrownfoxjumpsoverthelazydog";
    cout << pangramString(test);
    
    



    
}

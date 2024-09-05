#include<iostream>
#include<vector>
#include<cmath>
#include <chrono>
#include <thread>
#include<stack>


using namespace std;

bool isValid(string s) {

    stack<char> parenthesis;

    for (char parent : s){
        if (parent == '(' & parenthesis.top() == ')') {
            parenthesis.pop();
        }
        else if (parent == '[' & parenthesis.top() == ']') {
            parenthesis.pop();
        }
        else if (parent == '{' & parenthesis.top() == '}') {
            parenthesis.pop();
        }
        else {
            parenthesis.push(parent);
        }
    }

    if (parenthesis.empty()) {
        return true;
    } 
    return false;

    
}




int main(){

    string sample = "((({[{[[()]]}})))";
    cout << isValid(sample) << '\n';



    
    
    
    


}

#include <iostream>
#include <cmath>
// #include <list>
#include<stack>
using namespace std;

int charToInt(char c) {
    return c - '0';
}
int OperatorCombination(int first, int second, char sign)
    {
        if (sign == '+')
        {
            return first + second;
        }else if (sign == '-')
        {
            return second - first;
        }
        else if (sign == '/')
        {
            return second/first;
        }
        else
        {
            return second * first;
        }
    }
int postfix(string ans){
    int operand1;
    int operand2;
    // int tempResult;
    stack<int> stack;
    for (char ch : ans){
        if (ch == ' '){
            continue;
        }else if (ch != '+' && ch != '-' && ch != '*' && ch != '/'){
            stack.push(charToInt(ch));
        }else{
            operand1 = stack.top(); stack.pop();
            operand2 = stack.top(); stack.pop();
            stack.push(OperatorCombination(operand1, operand2, ch));
        }
        
    }
    return stack.top();
    // stack.pop();
    
}
string convertInfixToPostfix(string input){

    stack<char> stack;
    string ans = "";
    for (char ch : input){
        if (ch == 40){
            stack.push(ch);
        }else if(ch == 41){
            while (stack.top() != 40){
                /* code */
                ans.push_back(stack.top());
                stack.pop();
            }
            stack.pop();
        }else if(ch == 43 ||ch == 45 ){
            while(!stack.empty() && stack.top() != 43 && stack.top() != 45 && stack.top() != 40 && stack.top() != 41){
            // while (!stack.empty() && !std::strchr("+-()", stack.top())) 
                ans.push_back(stack.top());
                stack.pop();
            }
            stack.push(ch);
        }else if(ch == 42 || ch == 47){
            stack.push(ch);
        }else{
            ans.push_back(ch);
        }
    }
    while (!stack.empty())
    {
        ans.push_back(stack.top());
        stack.pop();
    }
    cout << ans << '\n';
    return ans;
}
int main()
{
    string infix; getline(cin, infix);
    
    // evaluation postfix notation
    cout <<postfix(convertInfixToPostfix(infix)) << '\n';
}
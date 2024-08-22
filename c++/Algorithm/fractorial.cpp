# include <iostream>
# include <string>

using namespace std;

long fractorial(int input)
{
    if (input < 2){
        return input;
    }else{
        return input * fractorial(input - 1);
    }
}

int main()
{
    int input; cin >> input;
    cout << fractorial(input);
}

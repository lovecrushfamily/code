# include <iostream>
# include <string>

using namespace std;

/**
 * The function calculates the result of raising an input number to a given power.
 * 
 * @param input The base number that will be multiplied repeatedly.
 * @param power The power parameter represents the exponent to which the input number will be raised.
 * 
 * @return the result of raising the input to the power specified.
 */
long mu(int input, int power){
    if ( power == 1){
        return input;
    }else{
        return input * mu(input, power - 1);
    }
}

int main()
{
    int input; cin >> input;
    int power; cin >> power;
    // cout << giai_thua(input);
    cout << mu(input, power);
}
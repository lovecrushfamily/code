#include <iostream>
using namespace std;

/* This is a function named `reverse` that takes an integer `num` as input and returns the reverse of
that number. */
int reverse(int num)
{
    int num2 = num;
    int reverse = 0;
    // loop until num equal 0 => break loop
    while (num != 0)
    {
        // Take one by one the last number and add to reverse var
        reverse = (reverse * 10) + num % 10;
        num /= 10;
    }

    return reverse;
}
int main()
{
    // Start

    int num;
    cout << "Enter your number: ";
    cin >> num;
    cout << num << " reverse => " << reverse(num);

    // End
    return 0;
}
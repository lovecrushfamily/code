# include <iostream>
# include <string>
# include <cmath>

using namespace std;

/**
 * The above function calculates  the Fibonacci number at a given position using recursion.
 * 
 * @param position The parameter "position" represents the position of the Fibonacci number that you
 * want to calculate. For example, if you pass 5 as the position, the function will return the 5th
 * Fibonacci number.
 * 
 * @return the Fibonacci number at the given position.
 */
int fibonaci(int position){
    if ( position < 2){
        return position;
    }else{
        return fibonaci( position - 1) + fibonaci(position - 2);
    }
}

void TotalNumber(string number){
    int total = 0;
    for( char i : number){
        total += (int)i;
    }
    cout << total;
}


int main()
{
    // int input; cin >> input;
    // cout << fibonaci(input);
    TotalNumber("120");
    
}
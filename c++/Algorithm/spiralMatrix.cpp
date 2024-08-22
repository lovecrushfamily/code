#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    int input;
    cin >> input;
    // int input = 5;
    int matrix[input][input];
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            matrix[i][j] = 0;
        }
        // cout << '\n';
    }

    int element = 0;
    int star = 0;

    while (element < pow(input, 2))
    {
        /* code */
        for (int i = star; i < input - star; i++)
        {
            matrix[star][i] = element;
            element++;
        }
        for (int j = 1 + star; j < input - star - 1; j++)
        {
            matrix[j][input - star - 1] = element;
            element++;
        }
        for (int k = input - 1 - star; k > 0 + star; k--)
        {
            matrix[input - 1 - star][k] = element;
            element++;
        }
        for (int l = input - 1 - star; l > 0 + star; l--)
        {
            matrix[l][0 + star] = element;
            element++;
        }
        star++;
    }
    // matrix[2][2] = 24;

    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            cout << matrix[i][j] << "  ";
        }
        cout << '\n';
    }
    // cout << '\n' <<star;
}
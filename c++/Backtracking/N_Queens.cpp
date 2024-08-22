#include<iostream>
#include<vector>

using namespace std;
// N_Queens problem
const int N = 8;
vector<int> Queens(N, -1);


bool isSafe(int row, int col){
    for (int i = 0; i < row; i++){
        if (Queens[i] == col || Queens[i] - col ==  i - row || Queens[i] - col == row - i){
            return false;
        }
    }
    return true;
}

int solveQueensUtil(int row = 0){
    if (row == N){
        return 1;
    }

    int count = 0;
    for (int col = 0; col < N; col++){
        if (isSafe(row, col)){
            Queens[row] = col;
            count += solveQueensUtil(row + 1);
            Queens[row] = -1;
        }
    }
    return count;
}

int main(){

    cout << solveQueensUtil();

    return 0;
}
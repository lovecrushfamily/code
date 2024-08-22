#include<iostream>
#include<vector>

using namespace std;
// N Rocks problem
const int N = 8;
vector<int> rooks(N, -1);



bool isSafe(int row, int col){
    for (int i = 0; i < row; i++){
        if (rooks[i] == col){
            return false;
        }
    }
    return true;
}

int solveRooksUtil(int row = 0){
    if (row == N){
        return 1;
    }

    int count = 0;
    for (int col = 0; col < N; col++){
        if (isSafe(row, col)){
            rooks[row] = col;
            count += solveRooksUtil(row + 1);
            rooks[row] = -1;
        }
    }
    return count;
}

int main(){

    cout << solveRooksUtil();

    return 0;
}
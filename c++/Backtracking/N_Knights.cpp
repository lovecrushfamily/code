#include<iostream>
#include<vector>

using namespace std;
// N_Knights problem
const int N = 4;
vector<int> Knights(N, -1);


bool isSafe(int row, int col){
    for (int i = 0; i < row; i++){
        if (Knights[i + 2] == col + 1 ) {
            return false;
        }
        if (Knights[i + 1] == col + 2 ) {
            return false;
        }   
        if (Knights[i - 1] == col + 2 ) {
            return false;
        }
        if (Knights[i - 2] == col + 1 ) {
            return false;
        }
        if (Knights[i - 2] == col - 1 ) {
            return false;
        }
        if (Knights[i - 1] == col - 2 ) {
            return false;
        }
        if (Knights[i + 1] == col - 2 ) {
            return false;
        }
        if (Knights[i + 2] == col - 1 ) {
            return false;
        }
    }
    return true;
}

int solveKnightsUtil(int row = 0){
    if (row == N){
        return 1;
    }

    int count = 0;
    for (int col = 0; col < N; col++){
        if (isSafe(row, col)){
            Knights[row] = col;
            count += solveKnightsUtil(row + 1);
            Knights[row] = -1;
        }
    }
    return count;
}

int main(){

    cout << solveKnightsUtil();

    return 0;
}
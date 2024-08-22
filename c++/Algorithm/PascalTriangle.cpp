#include<iostream>
#include<vector>

using namespace std;

void pascal(int number, vector<vector<int>>& arr){
    
    for (int row = 0; row < number; row++){
        for (int col = 0; col <= row; col++){
            
            if (col == 0 || col == row){
                arr[row][col] = 1;
            }else{
                arr[row][col] = arr[row - 1][col] + arr[row- 1][col - 1];
            }
        } 
    }
}
void printTriangle(vector<vector<int>>& pascalTriangle){
    
    for (int row = 0; row < pascalTriangle.size(); row++){
        for (int j = 0; j < pascalTriangle.size() - row; j++){
            cout << ' ';
        }
        for (int col = 0; col < pascalTriangle.size(); col++){
            if (pascalTriangle[row][col] != 0){
                cout << pascalTriangle[row][col] << ' ';
            }
        }
        cout << '\n';
    }
}

int main(){
    int row; cin >> row;
    vector<vector<int>> pascalTriangle(row, vector<int>(row));
    pascal(row, pascalTriangle);
    printTriangle(pascalTriangle);
    
    return 0;
}
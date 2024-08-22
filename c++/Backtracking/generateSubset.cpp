#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> subset;
vector<int> temp;

void generateSubset(vector<int>& arr, int start){
    if (start > arr.size()){
        return;
    }

    subset.push_back(temp);
    for (int i = start; i < arr.size(); i++){
        temp.push_back(arr[i]);
        generateSubset(arr, i + 1);
        temp.pop_back();
    }
}

int main(){

    vector<int> test = {1, 2, 3,4};
    generateSubset(test, 0);

    for (auto& sub : subset){
        for (int& num : sub){
            cout << num << ' ';
        }
        cout << '\n';
    }
}
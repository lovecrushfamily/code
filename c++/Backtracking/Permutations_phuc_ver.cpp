#include<iostream>
#include<vector>
// #include<queue>
// #include<set>
// #include<cmath>
// #include<unordered_map>
// #include<map>
// #include<algorithm>

using namespace std;

vector<vector<int>> permutations; 

void generatePermutation(vector<int>& arr, int start){
    if (start == arr.size() - 1){
        permutations.push_back(arr);
    }else{
        for (int i = start; i< arr.size(); i++){
            swap(arr[i], arr[start]);
            generatePermutation(arr, start + 1);
            swap(arr[i], arr[start]);
        }
    }
}
int main(){
    
    vector<int> arr = {1,2,3};
    generatePermutation(arr, 0);

    for (auto& elements : permutations){
        for (auto& sub_elements : elements){
            cout << sub_elements << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
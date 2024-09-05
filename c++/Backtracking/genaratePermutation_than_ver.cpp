#include<iostream>
#include<vector>
#include<string>
using namespace std;

/**
 * The function generates all possible binary strings of length n.
 * 
 * @param n The parameter "n" represents the number of digits in the binary number that we want to
 * generate.
 * @param current The current binary string being generated.
 */
void generateBinary(int n , string current){
    if (n == 0){
        cout << current << '\n';
    }else {
        generateBinary(n - 1, current + "0");
        generateBinary(n - 1, current + "1");
    }
}

void generatePermutation(vector<int>& nums, int start, vector<vector<int>>& permutations){
    if (start == nums.size() - 1){
        permutations.push_back(nums);
    }else{
        for (int i = start; i < nums.size(); i++){
            swap(nums[i], nums[start]);
            generatePermutation(nums, start + 1, permutations);
            swap(nums[i], nums[start]);
        }
    }
}

vector<vector<int>> getPermutations(vector<int>& nums){
    vector<vector<int>> permutations;
    generatePermutation(nums, 0, permutations);
    return permutations;
}

void printPermute(vector<vector<int>> arr){
    for (auto& elements : arr){
        for (auto& sub_elements : elements){
            cout << sub_elements << ' ';
        }
        cout << '\n';
    }
}

int main(){

    // Generate all permutation of numerical array
    vector<int> test =  {1, 2, 3, 4, 5, 6, 7 , 8 , 9};
    printPermute(getPermutations(test));

    // Generate Binary
    // generateBinary(4, "");



    return 0;
}
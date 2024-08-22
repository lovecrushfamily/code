#include<iostream>
#include<vector>

using namespace std;

// Problem : Generate all combination in range[1, range] 
// and it must all have number of combination digits as below;

vector<vector<int>> subset;
vector<int> temp;
int number_of_combination_digits;
int range;
// 
void generateSubset(int start){
    if (temp.size() == number_of_combination_digits){
        subset.push_back(temp);
    }

    for (int i = start; i <= range; i++){
        temp.push_back(i);
        generateSubset(i + 1);
        temp.pop_back();
    }
}

int main(){

    //this mean you have to generate all combination in range (1, 3) and all of them have 2 digits
    number_of_combination_digits = 2;
    range = 5;
    
    // main func
    generateSubset(1);

    for (auto& sub : subset){
        for (int& num : sub){
            cout << num << ' ';
        }
        cout << '\n';
    }
}
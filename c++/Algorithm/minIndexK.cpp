#include<iostream>
#include<vector>

using namespace std;

/**
 * The selectionSort function sorts a vector of integers in ascending order using the selection sort
 * algorithm.
 * 
 * @param input The input parameter is a reference to a vector of integers.
 */
int selectionSort(vector<int> &input, int n){
    int min;
    for (int i = 0; i < n; ++i){
        min = i;
        for(int j = i + 1; j < input.size() ; ++j){
            if ( input[j] < input[min]){
                min = j;
            }
        }
        swap(input[i], input[min]);
    }
    return input[n]; 
}

int main(){
    vector<int> input = {5,3,7,2,1,6,9,4};
    cout << selectionSort(input, 4) <<'\n' ;
    for (int i : input){
        cout << i << ' ';
    }
    return 0;
}

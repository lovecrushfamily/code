#include<iostream>
#include<vector>

using namespace std;

/**
 * The selectionSort function sorts a vector of integers in ascending order using the selection sort
 * algorithm.
 * 
 * @param input The input parameter is a reference to a vector of integers.
 */
void selectionSort(vector<int> &input){
    // int min;
    for (int i = 0; i < input.size(); ++i){
        int min = i;
        for(int j = i + 1; j < input.size() ; ++j){
            if ( input[j] < input[min]){
                min = j;
            }
        }
        swap(input[i], input[min]);
    }
}

int main(){
    vector<int> input = {5,3,7,2,1,6,9,4};
    selectionSort(input);
    for (int i : input){
        cout << i << ' ';
    }
    return 0;
}

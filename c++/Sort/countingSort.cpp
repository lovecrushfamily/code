#include <iostream>
#include <vector>

using namespace std;
int max(vector<int> arr){
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countingSort(vector<int> arr){
    int m =  max(arr);
    vector<int> newArr(m + 1,0);
    for (int ele : arr){
        newArr[ele]++;
    }
    for (int i = 0; i < newArr.size(); i++){
        while (newArr[i] > 0)
        {
            cout << i << ' ';
            newArr[i]--;
        }
    }
}
int main(){
    
    vector<int> test = {1,4,5,7,2,5,4,7,1,6,9,5,3,6};
    countingSort(test);
}
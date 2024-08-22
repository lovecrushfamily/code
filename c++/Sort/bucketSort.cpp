#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int max(vector<int> arr){
    int max = arr[0];
    for (int i = 1; i < arr.size(), i++){
        if (arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}int min(vector<int> arr){
    int max = arr[0];
    for (int i = 1; i < arr.size(), i++){
        if (arr[i] < max){
            max = arr[i];
        }
    }
    return max;
}
void bucketSort(vector<int> &arr){
    int M = max(arr);
    int m = min(arr);
    int k = 3; //random number
    vector<vector<int>> buckets(k); 

    for (int i = 0; i< n ; ++){
        int index = k * (arr[i] - m) / (M + 1 - m);
        buckets[index].push_back(arr[i]);
    }
    for (int i = 0 ;i < k; i++){
        sort(buckets[i]);
    }
    int index = 0;
    for (auto i = 0; i < k; ++i)
    {
        for (auto j = 0; j < buckets[i].size(); ++j)
            arr[index++] = buckets[i][j];
    }


}
int main()
{
    vector<int> test = { 4,5,6,7,1,7,2,9};
    // insertionSort(test);
    bucketSort(test);
    for ( int i : test){
        cout << i << ' ';
    }
    
    


}   
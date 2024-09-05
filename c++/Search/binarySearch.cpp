#include<iostream>
#include<vector>
#include<list>

using namespace std;

/**
 * The binarySearch function performs a binary search on a sorted vector and returns the index of the
 * value if found, or -1 if not found.
 * 
 * @param arr The arr parameter is a vector of integers that represents the sorted array in which we
 * want to perform the binary search.
 * @param value The value you are searching for in the array.
 * 
 * @return the index of the element in the vector `arr` that matches the `value` parameter. If the
 * element is not found, it returns -1.
 */
int binarySearch(vector<int> nums, int target){
    int low = 0;
    int high = nums.size() -  1;
    while (low <= high)
    {
        /* code */
        int mid = low + (high - low) / 2;
        if (nums[mid] == target){
            return mid;
        }
        if (nums[mid] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
        return low;
}
/**
 * The binarySearchRecursion function uses recursion to perform a binary search on a sorted vector and
 * returns the index of the value if found, otherwise -1.
 * 
 * @param arr The vector of integers in which the binary search is performed.
 * @param value The value we are searching for in the array.
 * @param low The index of the first element in the array being searched.
 * @param high The highest index of the array being searched.
 * 
 * @return the index of the element if it is found in the array, otherwise it returns -1.
 */
int binarySearchRecursion(vector<int> arr, int value, int low, int high ){
    if (high >= low){
        int mid = low + (high - low ) / 2;
        if( arr[mid] == value){
            return mid;
        }if (arr[mid] > value){
            return binarySearchRecursion(arr, value, low, mid - 1 );
        }
        return binarySearchRecursion(arr, value, mid + 1, high);
    }
    return -1;
}

int binarySearchMatrix(vector<vector<int>>& arr, int value){
    int matrixSize = arr.size();
    int subMatrixSize = arr[0].size();
    int low = 0;
    int high = subMatrixSize * matrixSize - 1;

    while (low <= high)
    {
        /* code */
        int mid = low + (high - low) / 2;
        int row = mid/ subMatrixSize;
        int col = mid % matrixSize;
        int num = arr[row][col];

        if (num == value){
            return true;
        }if (num < value){
            low = mid + 1;
        }else {
            high = mid - 1;
        }
    }
    return false;
    
}
/**
 * The interpolationSearch function performs interpolation search on a sorted vector of integers to
 * find the index of a given value, returning -1 if the value is not found.
 * 
 * @param arr A vector of integers that represents the array in which we want to search for the value.
 * @param value The value parameter represents the value that we are searching for in the array.
 * 
 * @return the index of the element in the vector `arr` that matches the given `value`. If the `value`
 * is not found in the vector, it returns -1.
 */
int interpolationSearch(vector<int> arr, int value){
    int low = 0, high = arr.size() -1 , mid;
    while (arr[low] != arr[high] && value >= arr[low] && arr[high] >= value)  
    {
        /* code */
        mid = low + ((value - arr[low]) * (high - low ) / (arr[high] - arr[low]));
        if (arr[mid] == value){
            return mid;
        }
        else if (value < arr[mid]) {
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    if (value == arr[low]){
        return low;
    }
    else{
        return -1;
    }
}
int main(){

    vector<int> test = {2,3,5,7,9,12,34,34,53,55,424,242,322 };
    // cout << "Value at the position: " <<binarySearch(test,36 );
    cout << binarySearchRecursion(test,55, 0, test.size() - 1 );
    // cout << interpolationSearch(test,55 );
    // list<int> lis = {3,54,54,5,4,5,45,43,5,34,5,34,5,34,5};
    // for (int it : lis){
    //     cout << it << ' ';
    // }

    // vector<vector<int>> test = {{1,2},{4,5},{6,91}};
    cout << binarySearch(test, 52) << '\n';

    
}

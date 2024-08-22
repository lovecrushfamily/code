#include <iostream>
using namespace std;

// Hàm trộn hai mảng con đã sắp xếp thành một mảng đã được sắp xếp
void merge(int arr[], int left[], int right[], int leftSize, int rightSize) {
    int i = 0; // Vị trí hiện tại trong mảng left
    int j = 0; // Vị trí hiện tại trong mảng right
    int k = 0; // Vị trí hiện tại trong mảng arr
    
    // So sánh từng phần tử của mảng left và right, đưa phần tử nhỏ hơn vào mảng arr
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    
    // Nếu một trong hai mảng con đã sử dụng hết các phần tử, chỉ cần chèn các phần tử còn lại từ mảng còn lại vào mảng arr
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }
    
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Hàm Merge Sort
/**
 * The mergeSort function implements the merge sort algorithm to sort an array of integers in ascending
 * order.
 * 
 * @param arr The input array that needs to be sorted.
 * @param size The size parameter represents the number of elements in the array that needs to be
 * sorted.
 * 
 * @return In this code, nothing is being returned. The return statement is used to exit the function
 * if the size of the array is less than or equal to 1.
 */
void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    
    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }
    
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, right, mid, size - mid);
}


int main() {
    int arr[] = {5, 2, 8, 3, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    mergeSort(arr, size);
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

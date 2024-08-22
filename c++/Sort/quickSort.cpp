#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low]; // Chọn phần tử cuối cùng làm pivot
    int i = (low); // Chỉ số của phần tử nhỏ hơn pivot

    for (int j = low + 1; j <= high; j++) {
        // Nếu phần tử hiện tại nhỏ hơn hoặc bằng pivot
        if (arr[j] <= pivot) {
            i++; // Tăng chỉ số phần tử nhỏ hơn pivot
            swap(arr[i], arr[j]); // Hoán đổi phần tử nhỏ hơn pivot với phần tử hiện tại
        }
    }
    swap(arr[i], arr[low]); // Đặt pivot vào vị trí đúng của nó
    return (i);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // Tìm pivot và đặt nó vào vị trí đúng
        int pivotIndex = partition(arr, low, high);

        // Đệ quy áp dụng Quick Sort cho hai phần của mảng đã chia
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {    
    vector<int> test = { 5, 4, 5, 7, 2, 5, 4, 7, 1, 6, 9, 5, 3, 6 };
    for (int ele : test) {
        cout << ele << " ";
    }
    int n = test.size();
    quickSort(test, 0, n - 1);
    cout << '\n';


    for (int ele : test) {
        cout << ele << " ";
    }

    return 0;
}
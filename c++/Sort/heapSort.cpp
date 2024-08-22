#include<iostream>
#include<vector>

using namespace std;

int parent(int index){ return (index - 1 ) / 2;}
int leftChild(int index){ return (index * 2) + 1 ;}
int rightChild(int index){ return (index * 2) + 2 ;}

void heapify(vector<int>& heap,int length, int index){
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < length && heap[left] > heap[largest]){
        largest = left;
    }if (right < length && heap[right] > heap[largest]){
        largest = right;
    }if (index != largest){
        swap(heap[index], heap[largest]);
        heapify(heap, length, largest);
    }

}   
void heapSort(vector<int>& arr){
    // build heap
    int length = arr.size();
    for (int index = arr.size() / 2 - 1; index >= 0; index--){
        heapify(arr,length, index);
    }

    // sort
    for (int index = arr.size() - 1; index > 0; index--){
        swap(arr[index], arr[0]);
        heapify(arr, index, 0);
    }
    
}

int main(){
    vector<int> test = {12,5,76,87,54,34,23};
    for (int i : test){
        cout << i << ' ';
    }
    heapSort(test);
    cout << '\n';
    for (int i : test){
        cout << i << ' ';
    }
    
}
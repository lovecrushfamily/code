#include<queue>
#include<iostream>
#include<vector>

using namespace std;

class MinHeap{
    private:
    vector<int> heap;

    int parent(int index){ return (index - 1 ) / 2;}
    int leftChild(int index){ return (index * 2) + 1 ;}
    int rightChild(int index){ return (index * 2) + 2 ;}

    void heapifyUp(int index){
        if (index != 0 && (heap[parent(index)] > heap[index])){
            swap(heap[parent(index)], heap[index]);
            heapifyUp(parent(index));
        }
        // this's  for maxHeap
        // if (index != 0 && (heap[parent(index)] < heap[index])){
        //     swap(heap[parent(index)], heap[index]);
        //     heapifyUp(parent(index));
        // }
    }

    void heapifyDown(int index){
        int smallest = index;    
        int left = leftChild(index);
        int right = rightChild(index);

        if(left < heap.size() && heap[left] < heap[smallest]){
            smallest = left;
        }if (right < heap.size() && heap[right] < heap[smallest]){
            smallest = right;
        }if (smallest != index){
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
        // this's for MaxHeap
        // if(left < heap.size() && heap[left] > heap[smallest]){
        //     smallest = left;
        // }if (right < heap.size() && heap[right] > heap[smallest]){
        //     smallest = right;
        // }if (smallest != index){
        //     swap(heap[index], heap[smallest]);
        //     heapifyDown(smallest);
        // }
    }
    public:
    void insert(int value){
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }
    int extractMin(){
        if (heap.empty()){
            cout << "Heap's empty !";
            return 0;
        }
        int min = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return min;
    }int top(){
        if (!empty()){
            return heap[0]; 
        }else{
            return 0;
        }
    }
    bool empty(){return (heap.size() == 0) ? false : true; };

    void heapSort(vector<int>& arr){
        while (!arr.empty())
        {
            insert(arr.back());
            arr.pop_back();
        }
        while (!heap.empty())
        {
            /* code */
            arr.push_back(extractMin());
        } 
    }
    
};
class Priority_queue{
    
    // C++ library
    // use heap to implement

};


int main(){
    // priority_queue<int> heap;

    MinHeap heap;
    vector<int> test = {5,54,5,4,5,4,34,35,355};
    heap.heapSort(test);

    for(int ele : test){
        cout << ele << ' ';
    }
    
    
    
    
    
    

    

    
    


}
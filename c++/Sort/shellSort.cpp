#include <iostream>
#include <vector>
using namespace std;

/**
 * The shellSort function implements the shell sort algorithm to sort a vector of integers in ascending
 * order.
 * 
 * @param arr A reference to a vector of integers that needs to be sorted using the shell sort
 * algorithm.
 */
void shellSort(vector<int> &arr){
    
    int gap = arr.size() / 2;
    while( gap > 0){
        for (int i = gap; i< arr.size(); i++){
            int temp = arr[i];
            int j = i; 
            while (j >= gap && arr[j - gap] > temp)
            {
                /* code */
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
            
        }
        gap /= 2;
    }
}
int main()
{
    vector<int> test = { 4,5,6,7,1,7,2,9};
    // insertionSort(test);
    shellSort(test);

    for ( int i : test){
        cout << i << ' ';
    }
    
    


}   
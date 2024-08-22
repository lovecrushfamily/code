#include <iostream>
#include<vector>
#include<queue>
#include<string>
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
int checkPos(int num, int pos){
    int  temp;
    string strNum = to_string(num);
    
    return (pos <= strNum.length()) ? strNum[strNum.length() - pos] - '0' : 0;
}
/**
 * The above function implements the radix sort algorithm to sort a vector of integers in ascending
 * order. And remember when you  work with queue or any mutable  data structure, it's better to use reference (&)
 * 
 * @param arr A reference to a vector of integers that will be sorted using radix sort algorithm.
 */
void radixSort(vector<int> &arr){
    vector<queue<int>> temp(10);
    int pos = 1;
    int loop = max(arr) *10;
    while(loop/=10){

        for (int ele : arr){
            temp[checkPos(ele,pos)].push(ele);
        }
        
        int k = 0;
        for (queue<int> &ele : temp){
            while (!ele.empty())
            {
                arr[k] = ele.front();
                ele.pop();
                k++;
            }
        }
        pos++;
    }
}

int main(){

    vector<int> test = {554,24,55,71,6544,745,94545,54545};
    radixSort(test);
    for (int ele: test){
        cout << ele << ' ';
    }


    
    

}
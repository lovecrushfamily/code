#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<cmath>
#include<unordered_map>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    //Example 5: Rescue Boat

    // Given an array people, where people[i] represents the weight of the i-th person. 
    // A boat can carry at most two people if the sum of their weights is 
    // less than or equal to a given limit. The task is to determine the 
    // minimum number of boats needed to rescue all the people. 
    // Note that no person weighs more than the limit.
    // To solve this problem, we can use a greedy approach. 
    // The basic idea is to sort the array in ascending order and then use two pointers, 
    // one pointing to the lightest person and the other pointing to the heaviest person. 
    // We try to pair them up in a boat as long as their total weight is within the limit. 
    // If it's not possible to pair them up, we put the heaviest person on a boat alone.
    //  We continue this process until all the people have been considered.
    
    vector<int> test = {3,4,6,9,2,1,7,7,4,6,8,2,5};

    //
    sort(test.begin(), test.end());
    int result = 0;
    int  left =  0;
    int right = test.size() - 1;
    int limit = 10;

    //
    while (left  <= right){
        if (test[left] + test[right] <= limit){
            left++;
        }
        right--;
        result++;

    }

    //
    for (int ele : test){
        cout << ele << ' ';
    }
    cout <<'\n'  << result;
    
    return 0;
}
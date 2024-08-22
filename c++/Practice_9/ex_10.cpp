#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> temp;
vector<vector<int>> result;

int sum(vector<int>& numbers){
    int sum = 0;
    for (int element : numbers){
        sum += element;
    }
    return sum;
}
bool checkDuplicate(vector<int> sample)
{
    sort(sample.begin(), sample.end());
    for (vector<int>& vec : result)
    {
        if (vec == sample)
        {
            return false;
        }
    }
    return true;
}
void calculateSum(vector<int> numbers, int target){
    int totals = sum(temp);
    if (totals == target && checkDuplicate(temp)){
        result.push_back(temp);
        return;
    }
    for (int index = 0; index < numbers.size(); index++){
        if (numbers[index] <= (target - totals)){
            temp.push_back(numbers[index]);
            calculateSum(numbers, target);
            temp.pop_back();
            totals = sum(temp);
        }
    }
}

int main(){
    vector<int> numbers = {2 ,3 , 4};
    int target = 10;

    calculateSum(numbers, target);

    cout << "All the partitions of the target adapt to the given numbers\n";
    for(auto& partitions: result){
        for(int number : partitions){
            cout << number << ' ';
        }
        cout << '\n';   
    }







    return 0;
}
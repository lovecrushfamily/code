#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> temp = {};
vector<vector<int>> partitions;
vector<int> copy;
int target;

int sum(vector<int> numbers)
{
    int sum = 0;
    for (int &number : numbers)
    {
        sum += number;
    }
    return sum;
}

bool checkDuplicate(vector<int> sample)
{
    sort(sample.begin(), sample.end());
    for (vector<int>& vec : partitions)
    {
        if (vec == sample)
        {
            return false;
        }
    }
    return true;
}

void countIntegerPartition(vector<int> temp, int start)
{
    if (sum(temp) == target)
    {
        if (checkDuplicate(temp))
        {
            partitions.push_back(temp);
        }
    }
    else if (sum(temp) < target)
    {
        for (int num = start; num <= target; num++)
        {
            temp.push_back(num);
            countIntegerPartition(temp, start);
            temp.pop_back();
        }
    }
}

int main()
{

    cin >> target;
    countIntegerPartition(temp, 1);
    for (auto &element : partitions)
    {
        for (int ele : element)
        {
            cout << ele << " + ";
        }
        cout << "\b\b= " << target << '\n';
    }
}
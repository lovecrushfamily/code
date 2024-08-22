#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<bitset>


using namespace std;

int main(){

    string test = "phuclovecrush";
    set<int> temp;
    for ( char ele : test){
        if (temp.find(ele) != temp.end()){
            cout << ele;
            break;
        }else{
            temp.insert(ele);
        }
    }
}
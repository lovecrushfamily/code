#include <iostream>

using namespace std;

int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
int day_of_week(int year, int month, int day){
    year -= month < 3;
    return (year + year/ 4 - year/100 + year/400 + t[month - 1] + day ) % 7 + 1;

}

int main(){
    int dayofweek = day_of_week(2022,9,6);
    cout  << dayofweek; //3



    return  0;
}
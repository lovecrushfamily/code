#include<iostream>


using namespace std;

int partition(int prizes ,int winner ){

    cout << "Prizes " << prizes << ' ' << '-' << " Winner " << ' ' << winner << '\n';
    
    // base case
    if (prizes == 0 || winner == 0){
        return 0;
    }if (winner == 1 || prizes == 1){
        return 1;
    }
    // recursion case
    if (prizes < winner){
        return partition(prizes, prizes);
    }else{
        
        return partition(prizes ,  winner - 1) + partition(prizes- winner, winner);
    }

}

int main(){

    // how many way to divide 5 gifts for 3 winner.
    cout << partition(5, 3);
    return 0;
}
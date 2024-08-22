# include <iostream>
# include <string>

using namespace std;

/**
 * The hanoi_tower function recursively solves the Tower of Hanoi problem by moving disks from one peg
 * to another.
 * 
 * @param n The number of disks in the tower.
 * @param a The source peg from which the disks are moved.
 * @param b The parameter "b" represents the auxiliary tower or peg that can be used to temporarily
 * hold disks during the movement.
 * @param c The parameter 'c' represents the destination peg or tower where the disks are to be moved
 * to.
 */
void hanoi_tower(int numberOfDisk, char sourcePeg, char auxiliaryPeg, char endPeg){
    if ( numberOfDisk == 1){
        cout << "Disk 1 moved from " << sourcePeg << " to " << endPeg << endl;
    }else{
        hanoi_tower( numberOfDisk - 1, sourcePeg, endPeg, auxiliaryPeg );
        cout << "Disk " << numberOfDisk << " moved from " << sourcePeg << " to " << endPeg << endl;
        hanoi_tower(numberOfDisk - 1, auxiliaryPeg, sourcePeg, endPeg);
    }
}

int main()
{
    int input; cin >> input;
    hanoi_tower(input, 'a' ,'b' ,'c');
    return 0;    
}

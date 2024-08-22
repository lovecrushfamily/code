#include<iostream>
#include<string>

using namespace std;

void generateBinary(int stringLength, string BinaryString){
    if (stringLength == 0){
        cout << BinaryString << '\n';
    }else{
        generateBinary(stringLength - 1, BinaryString + "0");
        generateBinary(stringLength - 1, BinaryString + "1");
    }
}


int main(){

    int binaryStringLength; cin >> binaryStringLength;
    generateBinary(binaryStringLength, "");

}
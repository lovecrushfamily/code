int GCDIterativeApproach(int firstNumber, int secondNumber){
    int temp;
    //In case: firstNumber greater than secondNumber; just theory
    while (firstNumber % secondNumber != 0)
    {
        /* code */
        temp = firstNumber % secondNumber;
        firstNumber = secondNumber;
        secondNumber = temp;
    }
    return secondNumber;
    
#ifndef DECODE_H
#define DECODE_H

#include <iostream>
#include <fstream>

using namespace std;

class Decode{
public:
    Decode();
    void decodeMsg();

private:
    ifstream inData;
    ofstream outData;

    char cipherIn;
    char cipherUpper;
    char cipherAdjust;
    char cipherOut;

    int counterArray[26][2] = {{0}};
    int x = 65;
    int maxChar;
    int maxCharValue;
    int rotationValue;






};//end class Decode
#endif

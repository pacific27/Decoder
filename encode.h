#ifndef ENCODE_H
#define ENCODE_H

using namespace std;

class Encode{

public:
    Encode();
    void encodeMsg();
    void setTranslationValue(int translationValue);

private:
    ifstream inData;
    ofstream outData;

    int rotationValue;

    char cipherAdjust;
    char cipherOut;

};//end class Encode

#endif
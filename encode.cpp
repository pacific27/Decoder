#include <iostream>
#include <fstream>
#include "encode.h"

using namespace std;

Encode::Encode(){rotationValue = 0;}

void Encode::setTranslationValue(int translationValue){
    this->rotationValue = translationValue;
}//end setTranslationValue

void Encode::encodeMsg(){

    inData.open("cipherTextInput.txt");
    outData.open("cipherTextEncoded.txt");

    if(!inData.is_open()){
        cout << "Error while opening File" << endl;
        exit(1);
    }//end if

    while(!inData.eof()) {
        inData.get(cipherAdjust);

        if(cipherAdjust >= 65 && cipherAdjust <= 90){
            if(rotationValue < 0){
                for(int i = abs(rotationValue); i >= 0; i--){
                    if(cipherAdjust == 65 && i > 0){
                        cipherAdjust = 90;
                    }//end if
                    else{
                        cipherAdjust--;
                    }//end else
                }//end for
            }//end if

            else if(rotationValue > 0){
                for(int i = 0; i < rotationValue; i++){
                    if(cipherAdjust == 90 && i < rotationValue){
                        cipherAdjust = 65;
                    }//end if
                    else{
                        cipherAdjust++;
                    }//end else
                }//end for
            }//end else

            else{
                cipherOut = cipherAdjust;
            }//end else
        }//end if

        else if(cipherAdjust >= 97 && cipherAdjust <= 122){
            if(rotationValue < 0){
                for(int i = abs(rotationValue); i >= 0; i--){
                    if(cipherAdjust == 97 && i > 0){
                        cipherAdjust = 122;
                    }//end if
                    else{
                        cipherAdjust--;
                    }//end else
                }//end for
            }//end if

            else if(rotationValue > 0){
                for(int i = 0; i < rotationValue; i++){
                    if(cipherAdjust == 122 && i < rotationValue){
                        cipherAdjust = 97;
                    }//end if
                    else{
                        cipherAdjust++;
                    }//end else
                }//end for
            }//end else

            else{
                cipherOut = cipherAdjust;
            }//end else
        }//end if

        else{
            cipherOut = cipherAdjust;
        }//end else

        cipherOut = cipherAdjust;
        outData << cipherOut;
    }//end while

    inData.close();
    outData.close();

}//end encode
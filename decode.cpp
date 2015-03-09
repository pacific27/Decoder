#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

#include "decode.h"

using namespace std;

Decode::Decode(){}

void Decode::decodeMsg(){

    inData.open("cipherTextInput.txt");
    outData.open("cipherTextDecoded.txt");

    if(!inData.is_open()){
        cout << "Error while opening File" << endl;
        exit(1);
    }//end if

    /*  Initialize counter array
     *  Col 0 initialized from 65-90 (Ascii values 'A' - 'Z')
     *  Col 1 Initialized to 0 to start
     */
     for(int row = 0; row < 26; row++){
         counterArray[row][0] = x;
         x++;
     }//end for array initialization

    /*  Process incoming data into counterArray
     *  until end of file marker reached increase
     *  corresponding char counter when matched
     */
    while(!inData.eof()){
        inData >> cipherIn;
        cipherUpper = toupper(cipherIn);

        for(int row = 0; row < 26; row++){
            if (cipherUpper == counterArray[row][0]){
                counterArray[row][1]++;
                break;
            }//end for
        }//end for
    }//end while

    maxChar = counterArray[0][1];

    for (int row = 1; row < 26; row++){
        if(maxChar < counterArray[row][1]){
            maxChar = counterArray[row][1];
        }//end if
    }//end for

    for (int row = 0; row < 26; row++){
        cout << setw(5) << static_cast<char>(counterArray[row][0]) << "  =";
        cout << setw(5) << counterArray[row][1];

        if(maxChar == counterArray[row][1]){
            cout << setw(12) << "  ******** E ********";
            maxCharValue = static_cast<char>(counterArray[row][0]);
        }//end if
        cout << endl;
    }//end for

    /* Calculate rotation from maxCharValue
     *
     */
    if(maxCharValue < 70){
        rotationValue = -1*(maxCharValue - 70);
        cout << rotationValue << endl;
    }
    else if(maxCharValue > 70){
        rotationValue = (70 - maxCharValue);
        cout << rotationValue << endl;
    }
    else{
        rotationValue = 0;
        cout << rotationValue << endl;
    }

    // Clear data stream
    while(inData.eof()){
        cout << "True";
        inData.clear();
        //inData.ignore(2000, '\n');
        inData.seekg(0, std::ios::beg);
        cout << endl;
    }//end while

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

}//end decodeMessage

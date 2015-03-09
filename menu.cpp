#include <iostream>
#include <iomanip>

#include "menu.h"
#include "decode.h"
#include "encode.h"

using namespace std;

Menu::Menu(){}

void Menu::displayMenu(){

    char userInput;
    char userInputUpper;

    do{
        cout << endl;
        cout << "**************************************" << endl;
        cout << setw(25) << "Message Encoder 1.0" << endl;
        cout << "**************************************" << endl;
        cout << endl;
        cout << "Press (E) to encode a message" << endl;
        cout << "Press (D) to decode a message" << endl;
        cout << "Press (Q) to exit Message Encoder 1.0" << endl;
        cout << endl;
        cout << "Please make your selection and press <Enter>: ";
        cin >> userInput;

        userInputUpper = toupper(userInput);
        userSelection(userInputUpper);
    }while(userInputUpper != 'Q');
}//end displayMenu

void Menu::userSelection(char userInputUpper){

    switch (userInputUpper)
    {
        case 'E': {
            cout << "Please Enter the translation amount (between 1-25) and press <Enter>: ";
            cin >> userDefinedTranslationAmt;
            Encode msg;
            msg.setTranslationValue(userDefinedTranslationAmt);
            msg.encodeMsg();
        }
            break;

        case 'D': {
            Decode msg;
            msg.decodeMsg();
        }
            break;

        case 'Q':
            break;

        default:
            cout << endl;
            cout << "That is not a valid input, please make another choice." << endl;
            cout << endl;
    }//end switch
}//end userSelection






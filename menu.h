#ifndef MENU_H
#define MENU_H

#include <iostream>

using namespace std;

class Menu {
public:

    Menu();
    void displayMenu();
    void userSelection(char userInput);

private:
    int userDefinedTranslationAmt;

};//end Menu

#endif

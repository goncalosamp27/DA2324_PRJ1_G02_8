#include <iostream>
#include "src/h/WManager.h"
#include "src/h/Menu.h"

/**
*@mainpage  An Analysis Tool for Water Supply Management
*
*
*
*/


    /**
       *@file         main.cpp
       *@brief        This is the main source code of the project. Menu Inicialization.
    */

int main() {
    Parser parser;
    Menu menu = Menu( parser);
    menu.Parsetype();
    return 0;
}

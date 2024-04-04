#ifndef DA2324_PRJ1_G02_8_MENU_H
#define DA2324_PRJ1_G02_8_MENU_H
#include <iostream>
#include "WManager.h"
using namespace std;

/**
 * @file Menu.h
 * @brief Declaration of the Menu class.
 */
class Menu {
public:
    Menu( Parser parser);
    void Parsetype();
    void startMenu();
    void MetricsMenu();
    void RealibilityMenu();
    WManager manager;
    Parser parser;
};
#endif //DA2324_PRJ1_G02_8_MENU_H

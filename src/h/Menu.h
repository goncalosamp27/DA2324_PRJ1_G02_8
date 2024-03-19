//
// Created by ubuntiago on 19-03-2024.
//

#ifndef DA2324_PRJ1_G02_8_MENU_H
#define DA2324_PRJ1_G02_8_MENU_H
#include <iostream>
#include "WManager.h"
using namespace std;

class Menu {
public:
    Menu(WManager manager, Parser parser);
    void startMenu();
    void MetricsMenu();
    void RealibilityMenu();
    WManager manager;
    Parser parser;
};
#endif //DA2324_PRJ1_G02_8_MENU_H

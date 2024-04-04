#include <iostream>
#include "src/h/WManager.h"
#include "src/h/Menu.h"
int main() {
    Parser parser;
    Menu menu = Menu( parser);
    menu.Parsetype();
    return 0;
}

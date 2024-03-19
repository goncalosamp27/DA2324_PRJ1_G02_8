#include <iostream>
#include "src/h/WManager.h"
#include "src/h/Menu.h"
#include "DataStructures/Graph.h"
int main() {
    WManager Manager;
    Parser parser;
    Menu menu = Menu(Manager, parser);
    menu.startMenu();
    return 0;
}

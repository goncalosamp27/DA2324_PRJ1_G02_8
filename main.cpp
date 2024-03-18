#include <iostream>
#include "src/h/WManager.h"
#include "DataStructures/Graph.h"
int main() {
    WManager Manager;
    cout << Manager.MaxFlow("C_15") << endl;
    return 0;
}

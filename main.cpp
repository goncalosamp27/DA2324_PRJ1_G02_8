#include <iostream>
#include "src/h/WManager.h"
#include "DataStructures/Graph.h"
int main() {
    WManager Manager;
    cout << Manager.MaxFlow("Lisboa") << endl;
    return 0;
}

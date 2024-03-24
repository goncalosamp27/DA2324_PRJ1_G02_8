#include <iostream>
#include "src/h/WManager.h"
#include "src/h/Menu.h"
#include "DataStructures/Graph.h"
int main() {
    WManager Manager;
    Graph<string> water_supply;
    for(auto& v : Manager.getWaterSupply().getVertexSet()){
        for(auto& e : v->getAdj()){
            Manager.calculate(e);
        }

    }
    return 0;
}

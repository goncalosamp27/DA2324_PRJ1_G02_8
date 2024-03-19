//
// Created by joao on 18-03-2024.
//

#ifndef DA2324_PRJ1_G02_8_WMANAGER_H
#define DA2324_PRJ1_G02_8_WMANAGER_H
#include <unordered_map>
#include "../../DataStructures/Graph.h"
#include "string"
#include "City.h"
#include "Reservoir.h"
#include "Stations.h"
#include "Parser.h"
using namespace std;
class WManager {
public:
    WManager();
    double MaxFlow(string city);
    void removePS();

private:
    unordered_map<string,City,City::HashCity> city_map;
    unordered_map<string,Reservoir ,Reservoir::ReservoirHash> reservoir_map;
    unordered_map<string ,Station,Station::StationHash> station_map;
    Graph<string> water_supply;
};


#endif //DA2324_PRJ1_G02_8_WMANAGER_H

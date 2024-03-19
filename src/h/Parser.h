//
// Created by joao on 18-03-2024.
//

#ifndef DA2324_PRJ1_G02_8_PARSER_H
#define DA2324_PRJ1_G02_8_PARSER_H
#include <unordered_map>
#include "../../DataStructures/Graph.h"
#include "string"
#include "City.h"
#include "Reservoir.h"
#include "Stations.h"
using namespace std;


class Parser {
public:
    Parser();
    void parse_Cities();
    void parse_Reservoirs();
    void parse_Stations();
    void parse_Pipes();
    Graph<string> getWater_Suply();
    unordered_map<string,Reservoir, Reservoir::ReservoirHash> getReservoirMap();
    unordered_map<string,City,City::HashCity> getCityMap();
    unordered_map<string ,Station,Station::StationHash> getStationMap();
private:
    Graph<string> water_suply;
    unordered_map<string,Reservoir, Reservoir::ReservoirHash> reservoir_map;
    unordered_map<string,City,City::HashCity> cities_map;
    unordered_map<string ,Station,Station::StationHash> stations_map;
};


#endif //DA2324_PRJ1_G02_8_PARSER_H

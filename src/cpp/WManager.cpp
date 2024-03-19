//
// Created by joao on 18-03-2024.
//

#include "../h/WManager.h"
#include "../h/Parser.h"
#include "../../DataStructures/Graph.h"
WManager::WManager() {
    Parser parser;
    city_map = parser.parse_Cities();
    reservoir_map = parser.parse_Reservoirs();
    station_map = parser.parse_Stations();
    parser.parse_Pipes();
    water_supply = parser.getWater_Suply();
}

double WManager::MaxFlow(string city) {
    Parser parser;
    double max_flow = 0;
    initializeFlow(&water_supply);
    for (auto& reservoir : reservoir_map){
        edmondsKarp(&water_supply,reservoir.first,city);
    }
    for(auto& pipe : water_supply.getVertexSet()){
        for(auto& edge : pipe->getAdj()){
            if(edge->getDest()->getInfo() == city){
                max_flow += edge->getFlow();
            }
        }
    }
    return max_flow;
}

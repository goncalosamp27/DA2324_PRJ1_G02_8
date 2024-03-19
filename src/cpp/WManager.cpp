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
    set_all_flow();
}
double WManager::MaxFlow(string city) {
    double max_flow = 0;
    initializeFlow(&water_supply);
    for (auto& reservoir : reservoir_map){
        edmondsKarp(&water_supply,reservoir.second,city);
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
unordered_map<pair<string ,City>,double,WManager::HashCityFlow> WManager::getCityFlow() {
    return city_flow;
}
void WManager::set_all_flow() {
    double max_flow;
    for(auto city : city_map){
        max_flow = MaxFlow(city.first);
        city_flow.insert({city,max_flow});
    }
}
void WManager::RemoveReservoir() {
    string reservoir;
    cout << "Code of the Reservoir: ";
    cin >> reservoir;
    auto it = water_supply.findVertex(reservoir);
    if(it == NULL){
        cout << "Invalid Input"<<'\n';
        return;
    }
    Graph<string> temp_Water_Suply = water_supply;
    unordered_map<string,Reservoir ,Reservoir::ReservoirHash> temp_reservoir_map = reservoir_map;
    auto itr = reservoir_map.find(reservoir);
    reservoir_map.erase(itr);
    water_supply.removeVertex(reservoir);
    double max_flow;
    for(auto city : city_map){
        max_flow = MaxFlow(city.first);
        auto itr = city_flow.find({city.first,city.second});
        if(itr->second != max_flow){
            cout << itr->first.second.getCityName() << " : "<< max_flow << " m3/s" << endl;
        }
    }
    water_supply = temp_Water_Suply;
    reservoir_map = temp_reservoir_map;
}

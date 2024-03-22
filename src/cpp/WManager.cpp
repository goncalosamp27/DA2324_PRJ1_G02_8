//
// Created by joao on 18-03-2024.
//

#include <list>
#include "../h/WManager.h"
#include "../h/Parser.h"
#include "../../DataStructures/Graph.h"
WManager::WManager() {
    parser.parse_Cities();
    parser.parse_Reservoirs();
    parser.parse_Stations();
    parser.parse_Pipes();
    city_map = parser.getCityMap();
    station_map = parser.getStationMap();
    reservoir_map = parser.getReservoirMap();
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
    getline(cin>>ws,reservoir);
    vector<pair<pair<string,string>,double>> edges;
    auto it = water_supply.findVertex(reservoir);
    if(it == NULL){
        cout << "Invalid Input"<<'\n';
        return;
    }
    for(auto e: it->getAdj()){
        pair<pair<string,string>,double> temp= {{e->getOrig()->getInfo(),e->getDest()->getInfo()},e->getWeight()};
        edges.push_back(temp);
    }
    auto itr = reservoir_map.find(reservoir);
    pair<string ,Reservoir> old = *itr;
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
    water_supply.addVertex(reservoir);
    for(auto e : edges){
        water_supply.addEdge(e.first.first,e.first.second,e.second);
    }
    reservoir_map.insert(old);
}
void WManager::removePS()
{
    vector<pair<string,string>> removedPS;
    vector <string> res;
    for(auto vertex: water_supply.getVertexSet())
    {
        if(vertex->getInfo()[0] == 'P')
        {
            for(auto city : city_map)
            {
                vector<pair<pair<string,string>,double>> edges;
                for(auto e: vertex->getAdj()){
                    pair<pair<string,string>,double> temp= {{e->getOrig()->getInfo(),e->getDest()->getInfo()},e->getWeight()};
                    edges.push_back(temp);
                }
                for(auto v : water_supply.getVertexSet()){
                    for(auto e: v->getAdj()){
                        if(e->getDest()->getInfo() == vertex->getInfo()){
                            pair<pair<string,string>,double> temp= {{e->getOrig()->getInfo(),e->getDest()->getInfo()},e->getWeight()};
                            edges.push_back(temp);
                        }
                    }
                }

                int expected_val = city_flow.find({city})->second;
                string ps = vertex->getInfo();
                water_supply.removeVertex(vertex->getInfo());
                int new_val = MaxFlow(city.first);
                if(expected_val != new_val) {
                    res.push_back(ps);
                }
                water_supply.addVertex(ps);
                for(auto e : edges){
                    water_supply.addEdge(e.first.first,e.first.second,e.second);
                }
            }
        }
    }
    for(auto station : station_map){
        auto itr = std::find(res.begin(), res.end(),station.first);
            if(itr == res.end()){
                cout << "The Station " << station.first << " Will not affect the flow in any city if removed!\n";
            }
    }
}
void WManager::removePipesCities() {
    return;
}
void WManager::removePipe() {
    for(auto vertex : water_supply.getVertexSet()){
        vector<pair<pair<string,string>,double>> edges;
        for (auto edge : vertex->getAdj()){
            pair<pair<string,string>,double> temp= {{edge->getOrig()->getInfo(),edge->getDest()->getInfo()},edge->getWeight()};
            water_supply.removeEdge(edge->getOrig()->getInfo(),edge->getDest()->getInfo());
            for(auto city : city_map){
                double max_flow = MaxFlow(city.first);
                if(max_flow <  city.second.getCityDemand() and max_flow != city_flow.find(city)->second){
                    cout << "removing the pipeline from src: " << temp.first.first << " to dest: "<< temp.first.second
                    << " will result in a deficit of " << city.second.getCityDemand() - max_flow << "m3/s in the city "<< city.second.getCityName()
                    << ","<<city.first<<endl;
                }
                edges.push_back(temp);
            }
        }
        for(auto edge: edges){
            water_supply.addEdge(edge.first.first,edge.first.second,edge.second);
        }
    }
}
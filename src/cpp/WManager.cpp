//
// Created by joao on 18-03-2024.
//

#include "../h/WManager.h"
WManager::WManager(){
    return;
};
WManager::WManager(string parse) {
    if(parse == "large"){
        parser.parse_Cities_Large();
        parser.parse_Reservoirs_Large();
        parser.parse_Stations_Large();
        parser.parse_Pipes_Large();
    }
    if(parse == "small"){
        parser.parse_Cities_Small();
        parser.parse_Reservoirs_Small();
        parser.parse_Stations_Small();
        parser.parse_Pipes_Small();
    }
    city_map = parser.getCityMap();
    station_map = parser.getStationMap();
    reservoir_map = parser.getReservoirMap();
    water_supply = parser.getWater_Suply();
    super_source_sink();
    initializeFlow(&water_supply);
    edmondsKarp(&water_supply,"super_source","super_sink");
    set_all_flow();
}
double WManager::MaxFlow(string city) {
    Vertex<string>*  city2 = water_supply.findVertex(city);
    for(auto e : city2->getAdj()){
            return e->getFlow();
    }
}

void WManager::super_source_sink() {
    water_supply.addVertex("super_source");
    water_supply.addVertex("super_sink");
    for(auto reservoir : reservoir_map){
        water_supply.addEdge("super_source",reservoir.first,reservoir.second.getMaxDelivery());
    }
    for(auto station : city_map){
        water_supply.addEdge(station.first,"super_sink",station.second.getCityDemand());
    }
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
    auto it = water_supply.findVertex(reservoir);
    if(it == NULL){
        cout << "Invalid Input"<<'\n';
        return;
    }
    auto itr = reservoir_map.find(reservoir);
    pair<string ,Reservoir> old = *itr;
    reservoir_map.erase(itr);
    double max_flow;
    for(auto city : city_map){
        max_flow = MaxFlow(city.first);
        auto itr = city_flow.find({city.first,city.second});
        if(itr->second != max_flow){
            cout << itr->first.second.getCityName() << " : "<< max_flow << " m3/s" << endl;
        }
    }
    reservoir_map.insert(old);
}
void WManager::removePSinput() {
    string PS;
    cout << "Code of the Pumping Station: ";
    getline(cin >> ws, PS);
    auto itr = station_map.find(PS);
    if(itr == station_map.end()){
        cout << "INVALID INPUT!\n";
        return;
    }
    auto vertex = water_supply.findVertex(PS);
    for (auto city: city_map) {
        vector<pair<pair<string, string>, double>> edges;
        for (auto e: vertex->getAdj()) {
                    pair<pair<string, string>, double> temp = {{e->getOrig()->getInfo(), e->getDest()->getInfo()},
                                                               e->getWeight()};
                    edges.push_back(temp);
        }
        for (auto v: water_supply.getVertexSet()) {
            for (auto e: v->getAdj()) {
                if (e->getDest()->getInfo() == vertex->getInfo()) {
                            pair<pair<string, string>, double> temp = {
                                    {e->getOrig()->getInfo(), e->getDest()->getInfo()}, e->getWeight()};
                            edges.push_back(temp);
                }
            }
        }
        int expected_val = city_flow.find({city})->second;
        string ps = vertex->getInfo();
        water_supply.removeVertex(vertex->getInfo());
        int new_val = MaxFlow(city.first);
        if (expected_val != new_val) {
            cout << "Removing the Station " << PS << " will afect the value of the flow in the city "<< city.first << " , " << city.second.getCityName() << endl;
            cout << "Old flow: "<<expected_val<<endl;
            cout << "New flow: "<< new_val<< endl;
        }
        water_supply.addVertex(ps);
        for (auto e: edges) {
            water_supply.addEdge(e.first.first, e.first.second, e.second);
        }
    }

}
void WManager::removePS(){
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
void WManager::TotalMaxFlow() {
    int sum = 0;
    for(auto city : city_flow){
        sum += city.second;
    }
    cout<< "The total max flow is: " << sum << " m3/s!"<< endl;
}
void WManager::removePipesCities() {
    string city;
    cout << "Code of the City: ";
    getline(cin >> ws, city);
    auto itr = city_map.find(city);
    if(itr == city_map.end()){
        cout << "INVALID INPUT!\n";
        return;
    }
    for (auto vertex: water_supply.getVertexSet()) {
        City cidade = city_map.find(city)->second;
        for (auto edge: vertex->getAdj()) {
            pair<pair<string, string>, double> temp = {{edge->getOrig()->getInfo(), edge->getDest()->getInfo()},
                                                       edge->getWeight()};
            water_supply.removeEdge(edge->getOrig()->getInfo(), edge->getDest()->getInfo());
            double max_flow = MaxFlow(city);
            if (max_flow < cidade.getCityDemand() and max_flow != city_flow.find({city, cidade})->second) {
                cout << "removing the pipeline from src: " << temp.first.first << " to dest: " << temp.first.second
                     << " will result in a deficit of " << cidade.getCityDemand() - max_flow << "m3/s in the city "
                     << cidade.getCityName()
                     << "," << city << endl;
            }
            water_supply.addEdge(temp.first.first, temp.first.second, temp.second);
        }
    }
}
void WManager::removePipe() {

    for(auto vertex : water_supply.getVertexSet()){
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
            }
            water_supply.addEdge(temp.first.first,temp.first.second,temp.second);
        }
    }
}
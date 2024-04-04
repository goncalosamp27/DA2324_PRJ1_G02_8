#include "../h/WManager.h"
/**
 * @brief Default constructor for WManager class.
 */
WManager::WManager(){
    return;
};

/**
 * @brief Parameterized constructor. Applies the parsing to either the large or the small data set according to the input.
 * @param parse The parse string.
 */
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
    set_all_flow();
}

/**
 * @brief Computes the maximum flow for a given city.
 *
 * @details
 * - Initializes local variables for computing the maximum flow.
 * - Iterates over the city map to find the city object corresponding to the input city name.
 * - Computes the flow from each reservoir to the given city using the Edmonds-Karp algorithm.
 * - Updates the city demand and accumulates the flow for each reservoir.
 * - Returns the maximum flow for the given city.
 *
 * @param city The city for which to compute the maximum flow.
 * @return The maximum flow for the given city.
 */
double WManager::MaxFlow(string city) {
    City city2;
    double max_flow = 0;
    double flow;
    initializeFlow(&water_supply);
    for (auto cit : city_map){
        if(cit.first == city){
            city2 = cit.second;
        }
    }
    for (auto& reservoir : reservoir_map){
        flow = edmondsKarp(&water_supply,reservoir.second,city2);
        city2.setCityDemand(city2.getCityDemand() - flow);
        max_flow += flow;
    }
    city2.setCityDemand(city2.getCityDemand() + max_flow);
    return max_flow;
}

/**
 * @brief Getter for city flow.
 * @return The city flow map.
 */
unordered_map<pair<string ,City>,double,WManager::HashCityFlow> WManager::getCityFlow() {
    return city_flow;
}

/**
 * @brief Sets flow for all nodes in the water supply graph.
 */
void WManager::set_all_flow() {
    double max_flow;
    for(auto city : city_map){
        max_flow = MaxFlow(city.first);
        city_flow.insert({city,max_flow});
    }
}

/**
 * @brief Removes a reservoir.
 *
 * @details
 * - Prompts the user to input the code of the reservoir.
 * - Checks if the reservoir exists in the water supply graph.
 * - If the reservoir doesn't exist, displays an error message and returns.
 * - Finds the reservoir in the reservoir map.
 * - If the reservoir is not found, displays an error and returns.
 * - Backs up the reservoir data before removal.
 * - Removes the reservoir from the reservoir map.
 * - Iterates over all cities in the city map.
 *   - Computes the maximum flow for each city after reservoir removal.
 *   - Finds the city-flow pair corresponding to the current city in the city flow map.
 *   - If the maximum flow has changed, displays the city and its updated maximum flow.
 * - Re-inserts the removed reservoir back into the reservoir map.
 */
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

/**
 * @brief Removes a pumping station from the water supply graph.
 *
 * @details
 * - Prompts the user to input the code of the pumping station.
 * - Checks if the pumping station exists in the station map.
 * - If the pumping station doesn't exist, displays an error message and returns.
 * - Finds the vertex corresponding to the pumping station in the water supply graph.
 * - Iterates over all cities in the city map:
 *   - Collects edges connected to the pumping station and adjacent vertices.
 *   - Computes the expected flow value for the current city before removal of the pumping station.
 *   - Removes the pumping station from the water supply graph and recomputes the maximum flow for the city.
 *   - If the expected flow value differs from the new flow value:
 *     - Displays a warning message indicating the impact on the city's flow value.
 *     - Displays the old and new flow values for comparison.
 *   - Re-adds the pumping station to the water supply graph and restores its edges.
 *
 * @sa MaxFlow(string city)
 */
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

/**
 * @brief Removes all pumping stations that do not affect the flow in any city.
 *
 * @details
 * - Iterates over all vertices in the water supply graph.
 * - For each vertex representing a pumping station:
 *   - Iterates over all cities in the city map:
 *     - Collects edges connected to the pumping station and adjacent vertices.
 *     - Computes the expected flow value for the current city before removal of the pumping station.
 *     - Removes the pumping station from the water supply graph and recomputes the maximum flow for the city.
 *     - If the expected flow value differs from the new flow value, adds the pumping station to the list of removed pumping stations.
 *     - Re-adds the pumping station to the water supply graph and restores its edges.
 * - Iterates over all pumping stations in the station map:
 *   - If a pumping station is not in the list of removed pumping stations, displays a message indicating that it will not affect the flow in any city if removed.
 */
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

/**
 * @brief Computes the total maximum flow for all cities.
 *
 * @details
 * - Iterates over all cities in the city flow map.
 * - Accumulates the maximum flow values for all cities.
 * - Displays the total maximum flow.
 */
void WManager::TotalMaxFlow() {
    int sum = 0;
    for(auto city : city_flow){
        sum += city.second;
    }
    cout<< "The total max flow is: " << sum << " m3/s!"<< endl;
}

/**
 * @brief Removes pipelines connected to a specified city and checks for flow deficits.
 *
 * @details
 * - Prompts the user to input the code of the city.
 * - Checks if the city exists in the city map.
 * - If the city doesn't exist, displays an error message and returns.
 * - Iterates over all vertices in the water supply graph:
 *   - Retrieves the city object corresponding to the specified city code.
 *   - Iterates over all edges adjacent to the current vertex:
 *     - Removes the edge temporarily and recomputes the maximum flow for the specified city.
 *     - If the maximum flow is less than the city demand and differs from the existing flow in the city:
 *       - Displays a message indicating the deficit in flow if the pipeline is removed.
 *     - Restores the removed edge.
 *
 * @sa MaxFlow(string city)
 */
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

/**
 * @brief Removes each pipeline in the water supply graph and checks for flow deficits in all cities.
 *
 * @details
 * - Iterates over all vertices in the water supply graph.
 * - Iterates over all edges adjacent to each vertex.
 * - Removes the current pipeline temporarily.
 * - For each city in the city map:
 *   - Computes the maximum flow after removing the pipeline.
 *   - If the maximum flow is less than the city demand and differs from the existing flow in the city:
 *     - Displays a message indicating the deficit in flow if the pipeline is removed.
 * - Restores the removed pipeline.
 */
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
                water_supply.addEdge(temp.first.first,temp.first.second,temp.second);
            }
        }
    }
}
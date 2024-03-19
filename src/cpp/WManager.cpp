#include "../h/WManager.h"

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

void WManager::removePS()
{
    vector<pair<string,string>> removedPS;
    vector<pair<pair<string,string>,pair<double,double>>> dontRemovePS;

    for(const auto& city : city_map)
    {
        double expected_value = MaxFlow(city.first);

        for(Vertex<string> * vert : water_supply.getVertexSet())
        {
            string code = vert->getInfo();
            if(!code.empty() && code[0] == 'P')
            {
                auto aux = water_supply;
                water_supply.removeVertex(code);
                double real_value = MaxFlow(city.first);

                if(real_value == expected_value) {
                    removedPS.emplace_back(code,city.second.getCityName());
                }
                else {
                    dontRemovePS.emplace_back(make_pair(code,city.second.getCityName()), make_pair(real_value, expected_value));
                }
                water_supply = aux;
            }
        }
    }

    for (auto s:removedPS){
        cout << "Removing the Pumping Station: " << s.first << " would not affect the flow in: " << s.second << "." << endl;
    }
    cout << endl << endl;
    for (auto s:dontRemovePS){
        cout << "Removing the Pumping Station: " << s.first.first << " would affect the flow in: " << s.first.second << ":" << endl;
        cout << " - The real flow value is " << s.second.first << " and would be converted to " << s.second.second << "." << endl;
    }
    cout << endl;
}
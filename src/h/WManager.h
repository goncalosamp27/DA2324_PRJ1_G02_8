#ifndef DA2324_PRJ1_G02_8_WMANAGER_H
#define DA2324_PRJ1_G02_8_WMANAGER_H
#include <unordered_map>
#include <list>
#include "City.h"
#include "Reservoir.h"
#include "Stations.h"
#include "Parser.h"
using namespace std;

/**
 * @file WManager.h
 * @brief Declaration of the WManager class.
 */
class WManager {
public:
    WManager();
    WManager(string parse);
    double MaxFlow(string city);
    void super_source_sink();
    void set_all_flow();
    void RemoveReservoir();
    void removess();
    void removePSinput();
    void removePS();
    void removePipe();
    void TotalMaxFlow();
    void removePipesCities();
    struct HashCityFlow {
        int operator()(const pair<string ,City>& city) const {
            int v = 0;
            for (char i: city.first) {
                v = 37 * v + i;
            }
            return v;
        }

        bool operator()(const pair<string, City>& city1, const pair<string, City>& city2) const {
            // Compare both the string and City parts
            return city1.first == city2.first && (city1.second == city2.second);
        }
    };
    unordered_map<pair<string ,City>,double,HashCityFlow> getCityFlow();

private:
    unordered_map<string,City,City::HashCity> city_map;
    unordered_map<pair<string ,City>,double,HashCityFlow> city_flow;
    unordered_map<string,Reservoir ,Reservoir::ReservoirHash> reservoir_map;
    unordered_map<string ,Station,Station::StationHash> station_map;
    Graph<string> water_supply;
    Parser parser;

    void geral();
};


#endif //DA2324_PRJ1_G02_8_WMANAGER_H

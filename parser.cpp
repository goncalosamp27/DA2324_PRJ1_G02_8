//
// Created by joao on 18-03-2024.
//

#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>
unordered_map<string,Reservoir, Reservoir::ReservoirHash> parser::parse_Reservoirs() {
    unordered_map<string,Reservoir,Reservoir::ReservoirHash> reservoir_map;
    ifstream in;
    in.open("../Project1LargeDataSet/Reservoir.csv");
    string line;
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string reservoir_name, municipality, code;
        int id, Maxdelivery;
        getline(ss, reservoir_name, ',');
        getline(ss, municipality, ',');
        ss >> id;
        ss.ignore(1);
        getline(ss, code, ',');
        ss >> Maxdelivery;
        ss.ignore(1);
        Reservoir reservoir = Reservoir(reservoir_name,municipality,id,code,Maxdelivery);
        reservoir_map.insert({code, reservoir});
        water_suply.addVertex(code);
    }
    return reservoir_map;
}

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
unordered_map<string ,Station,Station::StationHash> parser::parse_Stations(){
    unordered_map<string,Station,Station::StationHash> stations_map;
    ifstream in;
    in.open("../Project1LargeDataSet/Stations.csv");
    string line;
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    getline(in, line);
    while (getline(in, line)) {
     stringstream ss(line);
     string Code;
     int id;
     ss >> id;
     ss.ignore(1);
     getline(ss, Code, '\r');
     Station station(id,Code);
     stations_map.insert({Code,station});
     water_suply.addVertex(Code);
    }
    return stations_map;
}
unordered_map<string,City,City::HashCity> parser::parse_Cities(){
    unordered_map<string,City,City::HashCity> cities_map;
    ifstream in;
    in.open("../Project1LargeDataSet/Cities.csv");
    string line;
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string City_name,Code;
        int id,population;
        double demand;
        getline(ss, City_name, ',');
        ss >> id;
        ss.ignore(1);
        getline(ss, Code, ',');
        ss >> demand;
        ss.ignore(1);
        ss >> population;
        ss.ignore(1);
        City city(City_name,id,Code,demand,population);
        water_suply.addVertex(Code);
    }
    return cities_map;
}

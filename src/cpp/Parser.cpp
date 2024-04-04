#include "../h/Parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @brief Parses the reservoir data from a CSV file (from the large data set) and populates the reservoir map.
 */
void Parser::parse_Reservoirs_Large() {
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
}

/**
 * @brief Default constructor for the Parser class.
 */
Parser::Parser() {
}

/**
 * @brief Parses the station data from a CSV file (from the large data set) and populates the stations map.
 */
void Parser::parse_Stations_Large() {
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
}

/**
 * @brief Parses the city data from a CSV file (from the large data set) and populates the cities map.
 */
void Parser::parse_Cities_Large() {
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
        cities_map.insert({Code,city});
        water_suply.addVertex(Code);
    }
}
/**
 * @brief Parses the pipe data from a CSV file (from the large data set) and populates the water supply graph with edges.
 */
void Parser::parse_Pipes_Large() {
    ifstream in;
    in.open("../Project1LargeDataSet/Pipes.csv");
    string line;
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string Service_Point_A,Service_Point_B;
        int Capacity;
        bool Direction;
        getline(ss, Service_Point_A, ',');
        getline(ss, Service_Point_B, ',');
        ss >> Capacity;
        ss.ignore(1);
        ss >> Direction;
        ss.ignore(1);
        if(Direction == 1){
            water_suply.addEdge(Service_Point_A,Service_Point_B,Capacity);
        }
        if(Direction == 0){
            water_suply.addEdge(Service_Point_A,Service_Point_B,Capacity);
            water_suply.addEdge(Service_Point_B,Service_Point_A,Capacity);
        }

    }
}
/**
 * @brief Parses the reservoir data from a CSV file (from the small data set) and populates the reservoir map.
 */
void Parser::parse_Reservoirs_Small() {
    ifstream in;
    in.open("../Project1DataSetSmall/Reservoirs_Madeira.csv");
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
        ss.ignore(2);
        Reservoir reservoir = Reservoir(reservoir_name,municipality,id,code,Maxdelivery);
        reservoir_map.insert({code, reservoir});
        water_suply.addVertex(code);
    }
}

/**
 * @brief Parses the city data from a CSV file (from the small data set) and populates the cities map.
 */
void Parser::parse_Cities_Small() {
    ifstream in;
    in.open("../Project1DataSetSmall/Cities_Madeira.csv");
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
        ss.ignore(2);
        ss >> population;
        ss.ignore(1);
        City city(City_name,id,Code,demand,population);
        cities_map.insert({Code,city});
        water_suply.addVertex(Code);
    }
}
/**
 * @brief Parses the station data from a CSV file (from the small data set) and populates the stations map.
 */
void Parser::parse_Stations_Small() {
    ifstream in;
    in.open("../Project1DataSetSmall/Stations_Madeira.csv");
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
        getline(ss, Code, ',');
        ss.ignore(1);
        Station station(id,Code);
        stations_map.insert({Code,station});
        water_suply.addVertex(Code);
    }
}
/**
 * @brief Parses the pipe data from a CSV file (from the small data set) and populates the water supply graph with edges.
 */
void Parser::parse_Pipes_Small() {
    ifstream in;
    in.open("../Project1DataSetSmall/Pipes_Madeira.csv");
    string line;
    if (!in.is_open()){
        cout << "File not found!"<<'\n';
    }
    getline(in, line);
    while (getline(in, line)) {
        stringstream ss(line);
        string Service_Point_A,Service_Point_B;
        int Capacity;
        bool Direction;
        getline(ss, Service_Point_A, ',');
        getline(ss, Service_Point_B, ',');
        ss >> Capacity;
        ss.ignore(1);
        ss >> Direction;
        ss.ignore(1);
        if(Direction == 1){
            water_suply.addEdge(Service_Point_A,Service_Point_B,Capacity);
        }
        if(Direction == 0){
            water_suply.addEdge(Service_Point_A,Service_Point_B,Capacity);
            water_suply.addEdge(Service_Point_B,Service_Point_A,Capacity);
        }

    }
}

/**
 * @brief Getter function for retrieving the water supply graph.
 *
 * @return The water supply graph.
 */
Graph<string> Parser::getWater_Suply() {
    return water_suply;
}

/**
 * @brief Getter function for retrieving the reservoir map.
 *
 * @return The reservoir map.
 */
unordered_map<string,Reservoir, Reservoir::ReservoirHash> Parser::getReservoirMap(){
    return reservoir_map;
}

/**
 * @brief Getter function for retrieving the city map.
 *
 * @return The city map.
 */
unordered_map<string,City,City::HashCity> Parser::getCityMap() {
    return cities_map;
}

/**
 * @brief Getter function for retrieving the station map.
 *
 * @return The station map.
 */
unordered_map<string ,Station,Station::StationHash> Parser::getStationMap() {
    return stations_map;
}

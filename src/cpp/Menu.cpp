//
// Created by ubuntiago on 19-03-2024.
//
#include "../h/Menu.h"
#include <iostream>

Menu::Menu(WManager manager, Parser parser) {
    this->manager = manager;
    this->parser = parser;
}

void Menu::startMenu() {
    cout << "Welcome to the Water Management System" << endl;
    cout << "Please select an option" << endl;
    cout << "1. Basic Service Metrics" << endl;
    cout << "2. Exit" << endl;
    int option;
    cin >> option;
    switch (option) {
        case 1:
            Menu1();
            break;
        case 2:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            startMenu();

    }
}

void Menu::Menu1() {
    cout << "Please select an option" << endl;
    cout << "1. Max Flow for one city" << endl;
    cout << "2. Max Flow for all cities" << endl;
    cout << "3. Cities with not enough max flow" << endl;
    cout << "4. Exit" << endl;
    int option;
    cin >> option;
    double max_flow = 0;
    string name;
    switch (option) {
        case 1:
            cout << "Please enter the city name" << endl;
            cin >> name;
            for (auto& city : parser.parse_Cities()){
                max_flow = manager.MaxFlow(city.first);
                if (name == city.second.getCityName()){
                    cout << city.second.getCityName() << " : " <<  max_flow  << " m3/s" << endl;
                }
            }
            break;
        case 2:
            for (auto& city : parser.parse_Cities()){
                max_flow = manager.MaxFlow(city.first);
                    cout << city.second.getCityName() << " : " <<  max_flow  << " m3/s" << endl;
            }
            break;
        case 3:
            for (auto& city : parser.parse_Cities()){
                max_flow = manager.MaxFlow(city.first);
                if (max_flow < city.second.getCityDemand()){
                    cout << city.second.getCityName() << " needs " <<  city.second.getCityDemand()  << " m3/s";
                    cout << " and only has " << max_flow << " m3/s" << endl;
                }
            }
            break;
        case 4:
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option" << endl;
            Menu1();
    }
}
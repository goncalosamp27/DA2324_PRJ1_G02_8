//
// Created by ubuntiago on 19-03-2024.
//
#include "../h/Menu.h"
#include <iostream>

Menu::Menu(Parser parser) {
    this->parser = parser;
}
void Menu::Parsetype() {
    int c = true;
    string parsing;
    while(c){
        cout << "---------------------------------------------" << endl;
        cout << "|Welcome to the Water Management System     |" << endl;
        cout << "|Select a parsing option                    |" << endl;
        cout << "|1. SmallDataSet                            |" << endl;
        cout << "|2. LargeDataSet                            |" << endl;
        cout << "|3. Exit                                    |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                parsing = "small";
                c = false;
                break;
            case 2:
                parsing = "large";
                c = false;
                break;
            case 3:
                c = false;
                cout << "Goodbye!" << endl;
                return;
            default:
                cout << "Invalid Input!" << endl;

        }
    }
    WManager manager(parsing);
    this->manager = manager;
    startMenu();
}
void Menu::startMenu() {
    int c = true;
    while (c) {
        cout << "---------------------------------------------" << endl;
        cout << "|Welcome to the Water Management System     |" << endl;
        cout << "|Please select an option                    |" << endl;
        cout << "|1. Basic Service Metrics                   |" << endl;
        cout << "|2. Reliability and Sensitivity to Failures |" << endl;
        cout << "|3. Parse Type                              |" << endl;
        cout << "|4. Exit                                    |" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                MetricsMenu();
                break;
            case 2:
                RealibilityMenu();
                break;
            case 3:
                Parsetype();
                break;
            case 4:
                c = false;
                break;
            default:
                cout << "Invalid Input!" << endl;

        }
    }
}
void Menu::MetricsMenu(){
    int c = true;
    while(c){
        cout << "-------------------------------------" << endl;
        cout << "|Please select an option            |" << endl;
        cout << "|1. Max Flow for one city           |"<< endl;
        cout << "|2. Max Flow for all cities         |" << endl;
        cout << "|3. Cities with not enough max flow |" << endl;
        cout << "|4. Total Max Flow                  |" << endl;
        cout << "|5. Exit                            |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        unordered_map<pair<string ,City>,double,WManager::HashCityFlow> city_flow = manager.getCityFlow();
        double max_flow = 0;
        string name;
        switch (option) {
            case 1:
                cout << "Please enter the city name" << endl;
                getline(cin>>ws,name);
                for(auto city : city_flow){
                    if(name  == city.first.second.getCityName()){
                        cout << city.first.second.getCityName() << " : " <<  city.second << " m3/s" << endl;
                    }
                }
                break;
            case 2:
                for(auto city : city_flow){
                    cout << city.first.second.getCityName() << " : " <<  city.second  << " m3/s" << endl;
                }
                break;
            case 3:
                for (auto& city : city_flow){
                    max_flow = city.second;
                    if (max_flow < city.first.second.getCityDemand()){
                        cout << city.first.second.getCityName() << " needs " <<  city.first.second.getCityDemand()  << " m3/s";
                        cout << " and only has " << max_flow << " m3/s" << endl;
                    }
                }
                break;
            case 4:
                manager.TotalMaxFlow();
                break;
            case 5:
                c = false;
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }
    }
}
void Menu::RealibilityMenu() {
    int c = true;
    while(c){
        cout << "-------------------------------------" << endl;
        cout << "|Please select an option            |" << endl;
        cout << "|1. Reservoir Out                   |"<< endl;
        cout << "|2. Pumping Station Out             |" << endl;
        cout << "|3. Pipeline Out                    |" << endl;
        cout << "|4. Exit                            |" << endl;
        cout << "-------------------------------------" << endl;
        cout << "Choose an option: ";
        int option;
        cin >> option;
        switch (option) {
            case 1:
                manager.RemoveReservoir();
                break;
            case 2:
                manager.removePS();
                break;
            case 3:
                cout << "-------------------------------------" << endl;
                cout << "|1-City                             |"<< endl;
                cout << "|2-Pipeline                         |"<< endl;
                cout << "|3-Back                             |"<< endl;
                cout << "-------------------------------------" << endl;
                cout << "Choose an option: ";
                int option1;
                cin >> option1;
                if(option1 == 1)manager.removePipesCities();
                if(option1 == 2)manager.removePipe();
                break;
            case 4:
                c = false;
                break;
            default:
                cout << "Invalid Input!"<<'\n';
        }
    }
}
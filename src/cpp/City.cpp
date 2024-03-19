#include "../h/City.h"

using namespace std;

City::City(string name, int id, string code, double demand, int population) {
    this->city_name = name;
    this->city_id = id;
    this->city_code = code;
    this->city_demand = demand;
    this->city_population = population;
}

string City::getCityName() const {return city_name;}
void City::setCityName(string name) {this->city_name = name;}

int City::getCityId() const {return city_id;}
void City::setCityId(int id) {this->city_id = id;}

string City::getCityCode() const {return city_code;}
void City::setCityCode(string code) {this->city_code = code;}

double City::getCityDemand() const {return city_demand;}
void City::setCityDemand(double demand) {this->city_demand = demand;}

int City::getCityPopulation() const {return city_population;}
void City::setCityPopulation(int pop) {this->city_population = pop;}


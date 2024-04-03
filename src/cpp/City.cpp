#include "../h/City.h"

using namespace std;

/**
 * @brief Constructor for the City class.
 *
 * @param name The name of the city.
 * @param id The ID of the city.
 * @param code The code of the city.
 * @param demand The demand of the city.
 * @param population The population of the city.
 */
City::City(string name, int id, string code, double demand, int population) {
    this->city_name = name;
    this->city_id = id;
    this->city_code = code;
    this->city_demand = demand;
    this->city_population = population;
}

/**
 * @brief Getter function for retrieving the name of the city.
 *
 * @return The name of the city.
 */
string City::getCityName() const {return city_name;}

/**
 * @brief Setter function for setting the name of the city.
 *
 * @param name The name of the city.
 */
void City::setCityName(string name) {this->city_name = name;}

/**
 * @brief Getter function for retrieving the ID of the city.
 *
 * @return The ID of the city.
 */
int City::getCityId() const {return city_id;}

/**
 * @brief Setter function for setting the ID of the city.
 *
 * @param id The ID of the city.
 */
void City::setCityId(int id) {this->city_id = id;}

/**
 * @brief Getter function for retrieving the code of the city.
 *
 * @return The code of the city.
 */
string City::getCityCode() const {return city_code;}

/**
 * @brief Setter function for setting the code of the city.
 *
 * @param code The code of the city.
 */
void City::setCityCode(string code) {this->city_code = code;}

/**
 * @brief Getter function for retrieving the demand of the city.
 *
 * @return The demand of the city.
 */
double City::getCityDemand() const {return city_demand;}

/**
 * @brief Setter function for setting the demand of the city.
 *
 * @param demand The demand of the city.
 */
void City::setCityDemand(double demand) {this->city_demand = demand;}

/**
 * @brief Getter function for retrieving the population of the city.
 *
 * @return The population of the city.
 */
int City::getCityPopulation() const {return city_population;}

/**
 * @brief Setter function for setting the population of the city.
 *
 * @param pop The population of the city.
 */
void City::setCityPopulation(int pop) {this->city_population = pop;}

/**
 * @brief Equality operator for comparing two city objects.
 *
 * @param other The other city object to compare with.
 * @return True if the cities have the same code, false otherwise.
 */
bool City::operator==(const City& other) const {

    return city_code == other.getCityCode();
}

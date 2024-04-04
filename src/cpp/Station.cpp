#include "../h/Stations.h"
using namespace std;

/**
 * @brief Default constructor for the Station class.
 * Initialize station ID to zero
 * Initialize station code to an empty string
 */
Station::Station() {
    Id_ = 0;
    Code_ = "";
}

/**
 * @brief Parameterized constructor for the Station class.
 *
 * @param Id The ID of the station.
 * @param Code The code of the station.
 */
Station::Station(int Id, string Code) :
        Id_(Id), Code_(Code) {}

/**
 * @brief Getter function for retrieving the ID of the station.
 *
 * @return The ID of the station.
 */
int Station::getId() const {
    return Id_;
}

/**
 * @brief Setter function for setting the ID of the station.
 *
 * @param Id The ID of the station.
 */
void Station::setId(int Id) {
    Id_ = Id;
}

/**
 * @brief Getter function for retrieving the code of the station.
 *
 * @return The code of the station.
 */
string Station::getCode() const {
    return Code_;
}

/**
 * @brief Setter function for setting the code of the station.
 *
 * @param Code The code of the station.
 */
void Station::setCode(string Code) {
    Code_ = Code;
}


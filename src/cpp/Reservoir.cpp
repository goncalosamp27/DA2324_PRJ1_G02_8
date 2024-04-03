//
// Created by joao on 18-03-2024.
//

#include "../h/Reservoir.h"
using namespace std;

/**
 * @brief Default constructor for the Reservoir class.
 * Initializes member variables to default values.
 */
Reservoir::Reservoir() {
    Reservoir_ = "";
    Municipality_ = "";
    Id_ = 0;
    Code_ = "";
    MaxDelivery_ = 0;
}

/**
 * @brief Parameterized constructor for the Reservoir class.
 *
 * @param Reservoir The name of the reservoir.
 * @param Municipality The name of the municipality.
 * @param Id The ID of the reservoir.
 * @param Code The code of the reservoir.
 * @param MaxDelivery The maximum delivery capacity of the reservoir.
 */
Reservoir::Reservoir(std::string Reservoir, std::string Municipality, int Id, std::string Code, int MaxDelivery) :
    Reservoir_(Reservoir), Municipality_(Municipality),Id_(Id),Code_(Code),MaxDelivery_(MaxDelivery){};

/**
 * @brief Getter function for retrieving the name of the reservoir.
 *
 * @return The name of the reservoir.
 */
string Reservoir::getReservoir() const {
    return Reservoir_;
}
/**
 * @brief Setter function for setting the name of the reservoir.
 *
 * @param Reservoir The name of the reservoir.
 */
void Reservoir::setReservoir(string Reservoir) {
    Reservoir_ = Reservoir;
}

/**
 * @brief Getter function for retrieving the name of the municipality.
 *
 * @return The name of the municipality.
 */
string Reservoir::getMunicipality() const {
    return Municipality_;
}

/**
 * @brief Setter function for setting the name of the municipality.
 *
 * @param Municipality The name of the municipality.
 */
void Reservoir::setMunicipality(string Municipality) {
    Municipality_ = Municipality;
}

/**
 * @brief Getter function for retrieving the ID of the reservoir.
 *
 * @return The ID of the reservoir.
 */
int Reservoir::getId() const {
    return Id_;
}
/**
 * @brief Setter function for setting the ID of the reservoir.
 *
 * @param Id The ID of the reservoir.
 */
void Reservoir::setId(int Id) {
    Id_ = Id;
}
/**
 * @brief Getter function for retrieving the code of the reservoir.
 *
 * @return The code of the reservoir.
 */
string Reservoir::getCode() const {
    return Code_;
}
/**
 * @brief Setter function for setting the code of the reservoir.
 *
 * @param Code The code of the reservoir.
 */
void Reservoir::setCode(string Code) {
    Code_ = Code;
}
/**
 * @brief Getter function for retrieving the maximum delivery capacity of the reservoir.
 *
 * @return The maximum delivery capacity of the reservoir.
 */
int Reservoir::getMaxDelivery() const {
    return MaxDelivery_;
}

/**
 * @brief Setter function for setting the maximum delivery capacity of the reservoir.
 *
 * @param MaxDelivery The maximum delivery capacity of the reservoir.
 */
void Reservoir::setMaxDelivery(int MaxDelivery) {
    MaxDelivery_ = MaxDelivery;
}

/**
 * @brief Equality operator for comparing two reservoir objects.
 *
 * @param reservoir The reservoir object to compare with.
 * @return True if the reservoirs have the same code, false otherwise.
 */
bool Reservoir::operator==(const Reservoir& reservoir) const {
    return this->getCode() == reservoir.getCode();
}
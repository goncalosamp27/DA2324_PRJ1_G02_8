//
// Created by joao on 18-03-2024.
//

#include "Reservoir.h"
using namespace std;
Reservoir::Reservoir() {
    Reservoir_ = "";
    Municipality_ = "";
    Id_ = 0;
    Code_ = "";
    MaxDelivery_ = 0;
}
Reservoir::Reservoir(std::string Reservoir, std::string Municipality, int Id, std::string Code, int MaxDelivery) :
    Reservoir_(Reservoir), Municipality_(Municipality),Id_(Id),Code_(Code),MaxDelivery_(MaxDelivery){};
string Reservoir::getReservoir() const {
    return Reservoir_;
}
void Reservoir::setReservoir(string Reservoir) {
    Reservoir_ = Reservoir;
}
string Reservoir::getMunicipality() const {
    return Municipality_;
}
void Reservoir::setMunicipality(string Municipality) {
    Municipality_ = Municipality;
}
int Reservoir::getId() const {
    return Id_;
}
void Reservoir::setId(int Id) {
    Id_ = Id;
}
string Reservoir::getCode() const {
    return Code_;
}
void Reservoir::setCode(string Code) {
    Code_ = Code;
}
int Reservoir::getMaxDelivery() const {
    return MaxDelivery_;
}
void Reservoir::setMaxDelivery(int MaxDelivery) {
    MaxDelivery_ = MaxDelivery;
}
bool Reservoir::operator==(const Reservoir& reservoir) const {
    return this->getCode() == reservoir.getCode();
}
//
// Created by joao on 18-03-2024.
//

#include "Stations.h"
using namespace std;
Stations::Stations() {
    Id_ = 0;
    Code_ = "";
}
Stations::Stations(int Id, string Code) :
        Id_(Id), Code_(Code) {}
int Stations::getId() const {
    return Id_;
}
void Stations::setId(int Id) {
    Id_ = Id;
}
string Stations::getCode() const {
    return Code_;
}
void Stations::setCode(string Code) {
    Code_ = Code;
}


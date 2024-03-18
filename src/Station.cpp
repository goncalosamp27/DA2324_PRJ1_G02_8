//
// Created by joao on 18-03-2024.
//

#include "h/Stations.h"
using namespace std;
Station::Station() {
    Id_ = 0;
    Code_ = "";
}
Station::Station(int Id, string Code) :
        Id_(Id), Code_(Code) {}
int Station::getId() const {
    return Id_;
}
void Station::setId(int Id) {
    Id_ = Id;
}
string Station::getCode() const {
    return Code_;
}
void Station::setCode(string Code) {
    Code_ = Code;
}


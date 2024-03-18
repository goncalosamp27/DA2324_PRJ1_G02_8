#include "Pipes.h"

Pipes::Pipes(std::string pSPA, std::string pSPB, int p_c, bool p_d) {
    this->pipe_direction = p_d;
    this->pipe_capacity = p_c;
    this->pipe_service_Point_A = pSPA;
    this->pipe_service_Point_B = pSPB;
}

string Pipes::getPipeServicePointA() const {
    return pipe_service_Point_A;
}

void Pipes::setPipeServicePointA(string servicePointA) {
    pipe_service_Point_A = servicePointA;
}

string Pipes::getPipeServicePointB() const {
    return pipe_service_Point_B;
}

void Pipes::setPipeServicePointB(string servicePointB) {
    pipe_service_Point_B = servicePointB;
}

int Pipes::getPipeCapacity() const {
    return pipe_capacity;
}

void Pipes::setPipeCapacity(int capacity) {
    pipe_capacity = capacity;
}

bool Pipes::getPipeDirection() const {
    return pipe_direction;
}

void Pipes::setPipeDirection(bool direction) {
    pipe_direction = direction;
}

#include "Pipes.h"

Pipe::Pipe(std::string pSPA, std::string pSPB, int p_c, bool p_d) {
    this->pipe_direction = p_d;
    this->pipe_capacity = p_c;
    this->pipe_service_Point_A = pSPA;
    this->pipe_service_Point_B = pSPB;
}

string Pipe::getPipeServicePointA() const {
    return pipe_service_Point_A;
}

void Pipe::setPipeServicePointA(string servicePointA) {
    pipe_service_Point_A = servicePointA;
}

string Pipe::getPipeServicePointB() const {
    return pipe_service_Point_B;
}

void Pipe::setPipeServicePointB(string servicePointB) {
    pipe_service_Point_B = servicePointB;
}

int Pipe::getPipeCapacity() const {
    return pipe_capacity;
}

void Pipe::setPipeCapacity(int capacity) {
    pipe_capacity = capacity;
}

bool Pipe::getPipeDirection() const {
    return pipe_direction;
}

void Pipe::setPipeDirection(bool direction) {
    pipe_direction = direction;
}

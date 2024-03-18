#ifndef DA2324_PRJ1_G02_8_PIPES_H
#define DA2324_PRJ1_G02_8_PIPES_H
#include <string>

using namespace std;

class Pipes {
public:
    string getPipeServicePointA() const;
    void setPipeServicePointA(string servicePointA);

    string getPipeServicePointB() const;
    void setPipeServicePointB(string servicePointB);

    int getPipeCapacity() const;
    void setPipeCapacity(int capacity);

    bool getPipeDirection() const;
    void setPipeDirection(bool direction);

    Pipes(string pSPA, string pSPB, int p_c, bool p_d);
    Pipes();

private:
    string pipe_service_Point_A;
    string pipe_service_Point_B;
    int pipe_capacity;
    bool pipe_direction;
};

#endif //DA2324_PRJ1_G02_8_PIPES_H
#include <string>

using namespace std;

class Pipe {
public:
    string getPipeServicePointA() const;
    void setPipeServicePointA(string servicePointA);

    string getPipeServicePointB() const;
    void setPipeServicePointB(string servicePointB);

    int getPipeCapacity() const;
    void setPipeCapacity(int capacity);

    bool getPipeDirection() const;
    void setPipeDirection(bool direction);

    Pipe(string pSPA, string pSPB, int p_c, bool p_d);
    Pipe();

private:
    string pipe_service_Point_A;
    string pipe_service_Point_B;
    int pipe_capacity;
    bool pipe_direction;
};


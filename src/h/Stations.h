#ifndef DA2324_PRJ1_G02_8_STATIONS_H
#define DA2324_PRJ1_G02_8_STATIONS_H
#include <string>
using namespace std;

/**
 * @file Station.h
 * @brief Declaration of the Station class.
 */
class Station {
public:
    Station();
    Station(int Id, string Code);
    int getId() const;
    void setId(int Id);
    string getCode() const;
    void setCode(string Code);
    struct StationHash{
        int operator()(const string& station) const{
            int v=0;
            for(char i:station){
                v=37*v+i;
            }
            return v;
        }
        bool operator()(const string& station1,const string& station2) const{
            return station1==station2;
        }
    };

private:
    int Id_;
    string Code_;
};


#endif //DA2324_PRJ1_G02_8_STATIONS_H

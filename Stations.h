//
// Created by joao on 18-03-2024.
//

#ifndef DA2324_PRJ1_G02_8_STATIONS_H
#define DA2324_PRJ1_G02_8_STATIONS_H
#include <string>
using namespace std;

class Station {
public:
    Station();
    Station(int Id, string Code);
    int getId() const;
    void setId(int Id);
    string getCode() const;
    void setCode(string Code);

    struct StationHash{
        int operator()(const Station& station) const{
            return std::hash<int>()(station.getId());
        }
        bool operator()(const Station& station1,const Station& station2) const{
            return station1.getId()==station2.getId();
        }
    };

private:
    int Id_;
    string Code_;
};


#endif //DA2324_PRJ1_G02_8_STATIONS_H

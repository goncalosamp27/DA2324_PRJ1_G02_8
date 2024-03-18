//
// Created by joao on 18-03-2024.
//

#ifndef DA2324_PRJ1_G02_8_RESERVOIR_H
#define DA2324_PRJ1_G02_8_RESERVOIR_H
#include <string>
using namespace std;
class Reservoir {
public:
    Reservoir();
    Reservoir(string Reservoir, string Municipality,int Id, string Code, int MaxDelivery);
    string getReservoir() const ;
    void setReservoir(string Reservoir) ;
    string getMunicipality() const ;
    void setMunicipality(string Municipality) ;
    int getId() const;
    void setId(int Id);
    string getCode() const;
    void setCode(string Code);
    int getMaxDelivery() const;
    void setMaxDelivery(int MaxDelivery);
private:
    string Reservoir_;
    string Municipality_;
    int Id_;
    string Code_;
    int MaxDelivery_;
};


#endif //DA2324_PRJ1_G02_8_RESERVOIR_H
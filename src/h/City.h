#ifndef DA2324_PRJ1_G02_8_CITY_H
#define DA2324_PRJ1_G02_8_CITY_H
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;
/**
 * @brief The City class represents a city with its attributes (name, ID, Code, Demand and Population).
 */
class City {
public:
    string getCityName() const;
    void setCityName(string name);

    int getCityId() const;
    void setCityId(int id);

    string getCityCode() const;
    void setCityCode(string code);

    double getCityDemand() const;
    void setCityDemand(double demand);

    int getCityPopulation() const;
    void setCityPopulation(int pop);

    City(string name, int id, string code, double demand, int population);
    City();
    bool operator==(const City& other) const;
    struct HashCity {
        int operator()(const string& city) const {
            int v=0;
            for(char i:city){
                v=37*v+i;
            }
            return v;
        }
        bool operator()(const string& city1, const string& city2) const{
            return city1 == city2;
        }
    };

private:
    string city_name;
    int city_id;
    string city_code;
    double city_demand;
    int city_population;
};

#endif //DA2324_PRJ1_G02_8_CITY_H
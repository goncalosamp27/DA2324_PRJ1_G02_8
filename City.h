#include <string>

using namespace std;

class City {
public:
    string getCityName() const;
    void setCityName(string name);

    int getCityId() const;
    void setCityId(int id);

    string getCityCode() const;
    void setCityCode(string code);

    int getCityDemand() const;
    void setCityDemand(int demand);

    int getCityPopulation() const;
    void setCityPopulation(int pop);

    City(string name, int id, string code, int demand, int population);
    City();

private:
    string city_name;
    int city_id;
    string city_code;
    int city_demand;
    int city_population;
};


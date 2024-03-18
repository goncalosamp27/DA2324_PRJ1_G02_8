#include <string>
#include <unordered_map>
#include <unordered_set>

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

    struct HashCity {
        size_t operator()(const City& city) const {
            return hash<int>{}(city.getCityId());
        }
        bool operator()(const City& city1, const City& city2) const{
            return city1.getCityId() == city2.getCityId();
        }
    };

private:
    string city_name;
    int city_id;
    string city_code;
    int city_demand;
    int city_population;
};


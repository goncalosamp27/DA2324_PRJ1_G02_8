//
// Created by joao on 18-03-2024.
//

#include "WaterSupplyManagement.h"
#include "parser.h"
WaterSupplyManagement::WaterSupplyManagement() {
    parser parser;
    city_map = parser.parse_Cities();
    reservoir_map = parser.parse_Reservoirs();
    station_map = parser.parse_Stations();
    water_suply = parser.getWater_Suply();
}
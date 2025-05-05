#pragma once
#include "factories/airportFactory.hpp"
#include "map.hpp"
#include <vector>

class AirportManager
{
public:
    AirportManager(int amount, const Map* map);

    void update();

    void display(sf::RenderWindow* window);

private:
    std::vector<Airport> airports;
};
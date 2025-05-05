#pragma once
#include "factories/airportFactory.hpp"
#include <vector>

class AirportManager
{
public:
    AirportManager(int amount);

    void update();

    void display(sf::RenderWindow* window);

private:
    std::vector<Airport> airports;
};
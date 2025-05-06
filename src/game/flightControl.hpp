#pragma once
#include "airportManagerInterface.hpp"
#include "gameObjects/factories/flyableFactory.hpp"

class FlightControl
{
public:
    FlightControl(sf::Vector2u mapSize, int startingPlanes, IAirportManager&);

    void update() {}

    void display(sf::RenderWindow*) {}

private:
    std::vector<std::unique_ptr<IFlyable>> objects;
};
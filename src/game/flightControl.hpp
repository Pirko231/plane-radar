#pragma once
#include "airportManagerInterface.hpp"
#include "gameObjects/factories/flyableFactory.hpp"

class FlightControl
{
public:
    FlightControl(sf::Vector2u mapSize, int startingPlanes, IAirportManager&);

    void update(bool paused = false);

    void display(sf::RenderWindow*);

private:
    IAirportManager& airportManager;
    std::vector<std::unique_ptr<IFlyable>> objects;
};
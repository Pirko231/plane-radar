#pragma once
#include "airportManager.hpp"
#include "gameObjects/factories/flyableFactory.hpp"

class FlightControl
{
public:


private:
    std::vector<std::unique_ptr<IFlyable>> objects;
};
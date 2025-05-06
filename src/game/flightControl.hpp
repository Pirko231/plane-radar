#pragma once
#include "airportManagerInterface.hpp"
#include "gameObjects/factories/flyableFactory.hpp"

class FlightControl
{
public:
    FlightControl(int startingPlanes, IAirportManager&);



private:
    std::vector<std::unique_ptr<IFlyable>> objects;
};
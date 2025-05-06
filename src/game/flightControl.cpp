#include "flightControl.hpp"

FlightControl::FlightControl(int startingPlanes, IAirportManager& airportManager)
{
    FlyableFactory factory;
    for (int i = 0; i < startingPlanes; i++)
    {
        objects.push_back(factory.createPlane());
        airportManager.requestLanding(*objects[i].get(), objects[i]->getPosition());
    }
}

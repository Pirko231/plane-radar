#pragma once
#include "airport.hpp"
#include "flyable.hpp"

class IAirportManager
{
public:
    virtual Airport* getClosestAirport(sf::Vector2f pos) = 0;

    virtual bool requestLanding(IFlyable*, IAirport*) = 0;

    virtual Airport* getRandomAirport() = 0;
};
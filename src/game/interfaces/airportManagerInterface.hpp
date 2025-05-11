#pragma once
#include "factories/airportFactory.hpp"
#include "factories/flyableFactory.hpp"

class IAirportManager
{
public:
    virtual Airport* getClosestAirport(sf::Vector2f pos) = 0;

    virtual bool requestLanding(IFlyable*, IAirport*) = 0;

    virtual Airport* getRandomAirport() = 0;
};
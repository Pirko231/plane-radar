#pragma once
#include "factories/airportFactory.hpp"
#include "factories/flyableFactory.hpp"

class IAirportManager
{
public:
    virtual const Airport& getClosestAirport(sf::Vector2f pos) const = 0;

    virtual bool requestLanding(IFlyable&, sf::Vector2f) = 0;


};
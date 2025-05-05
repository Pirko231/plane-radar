#pragma once
#include "airport.hpp"

class AirportFactory
{
public:
    Airport create(sf::Vector2f pos)
    {
        return Airport{pos};
    }
};
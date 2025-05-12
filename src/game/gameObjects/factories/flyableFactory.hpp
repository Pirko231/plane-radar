#pragma once
#include "airportManagerInterface.hpp"
#include "plane.hpp"
#include "helicopter.hpp"
#include <memory>

class FlyableFactory
{
public:
    std::unique_ptr<IFlyable> createPlane(IAirport* target, IAirportManager* requestHandler)
    {
        auto obj {std::make_unique<Plane>(target)};
        requestHandler->requestLanding(obj.get(), target);
        return obj;
    }
    std::unique_ptr<IFlyable> createHeli(sf::Vector2f pos)
    {
        return std::make_unique<Helicopter>(pos);
    }
};
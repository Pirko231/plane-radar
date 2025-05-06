#pragma once
#include "plane.hpp"
#include "helicopter.hpp"
#include <memory>

class FlyableFactory
{
public:
    std::unique_ptr<IFlyable> createPlane(sf::Vector2f pos)
    {
        return std::make_unique<Plane>(pos);
    }
    std::unique_ptr<IFlyable> createHeli(sf::Vector2f pos)
    {
        return std::make_unique<Helicopter>(pos);
    }
};
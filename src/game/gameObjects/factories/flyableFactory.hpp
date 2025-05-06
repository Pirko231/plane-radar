#pragma once
#include "plane.hpp"
#include "helicopter.hpp"
#include <memory>

class FlyableFactory
{
public:
    std::unique_ptr<IFlyable> createPlane()
    {
        return std::make_unique<Plane>();
    }
    std::unique_ptr<IFlyable> createHeli()
    {
        return std::make_unique<Helicopter>();
    }
};
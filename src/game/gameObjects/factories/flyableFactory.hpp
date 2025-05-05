#pragma once
#include "../planes/plane.hpp"
#include "../planes/helicopter.hpp"
#include <memory>

class FlyableFactory
{
public:
    std::unique_ptr<IFlyable> createPlane()
    {
        return std::make_unique<IFlyable>(Plane{});
    }
    std::unique_ptr<IFlyable> createHeli()
    {
        return std::make_unique<IFlyable>(Helicopter{});
    }
};
#pragma once
#include "flyable.hpp"
#include "base.hpp"

class Plane : public IFlyable
{
public:
    Plane(sf::Vector2f pos);
    void update() override;
    void setDestination() override;
private:
};
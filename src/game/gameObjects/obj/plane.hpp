#pragma once
#include "flyable.hpp"
#include "base.hpp"

class Plane : public IFlyable
{
public:
    Plane(sf::Vector2f pos);
    void update() override;
    void depart(sf::Vector2f target) override;
    bool isNearTarget() const override;
private:
    sf::Vector2f destination;
};
#pragma once
#include "flyable.hpp"
#include "base.hpp"

class Helicopter : public IFlyable
{
public:
    Helicopter(sf::Vector2f pos);
    void update() override;
    void depart(sf::Vector2f target) override {}
    bool isNearTarget() const override;
private:

};
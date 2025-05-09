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
    void land() override {status = Status::DOCKED; destination = getPosition();}
private:
    sf::Vector2f destination;
};
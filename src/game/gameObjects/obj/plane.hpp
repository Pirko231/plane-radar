#pragma once
#include "flyable.hpp"
#include "base.hpp"
#include "airportInterface.hpp"

class Plane : public IFlyable
{
public:
    Plane(sf::Vector2f pos);
    void update() override;
    void depart(IAirport* target) override;
    bool isNearTarget() const override;
    void land() override {status = Status::DOCKED; destination = getPosition();}

#ifdef IMGUI
    sf::Vector2f getDestination() const {return destination;}
#endif
private:
    sf::Vector2f destination;
    IAirport* target{};
};
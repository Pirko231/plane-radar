#pragma once
#include "flyable.hpp"
#include "base.hpp"
#include "airportInterface.hpp"

class Plane : public IFlyable
{
public:
    Plane(IAirport*);
    void update() override;
    void depart(IAirport* target) override;
    IAirport* getTarget() const override
    {
        if (target)
            return target;
        return nullptr;
    }
    void land() override {status = Status::DOCKED; destination = getPosition(); moveBy = {}; hasClosestAirport = false;}

#ifdef IMGUI
    sf::Vector2f getDestination() const {return destination;}
#endif
private:
    void crash();
    
    sf::Vector2f destination;
    sf::Vector2f moveBy;
    IAirport* target{};
};
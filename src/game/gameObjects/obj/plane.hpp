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
    sf::FloatRect getTarget() const override
    {
        if (target)
            return target->getGlobalBounds();
        return sf::FloatRect{};
    }
    void land() override {status = Status::DOCKED; destination = getPosition(); moveBy = {};}

#ifdef IMGUI
    sf::Vector2f getDestination() const {return destination;}
#endif
private:
    sf::Vector2f destination;
    sf::Vector2f moveBy;
    IAirport* target{};
};
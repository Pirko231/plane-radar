#pragma once
#include "flyable.hpp"

class Plane : public IFlyable
{
public:
    Plane();
    void update();
    void setDestination();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        
    }
};
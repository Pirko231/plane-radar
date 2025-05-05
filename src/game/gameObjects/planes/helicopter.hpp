#pragma once
#include "flyable.hpp"

class Helicopter : public IFlyable
{
public:
    Helicopter();
    void update();
    void setDestination();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        
    }
};
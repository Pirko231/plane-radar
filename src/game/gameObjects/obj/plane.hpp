#pragma once
#include "flyable.hpp"

class Plane : public IFlyable
{
public:
    Plane();
    void update() override;
    void setDestination() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        
    }
};
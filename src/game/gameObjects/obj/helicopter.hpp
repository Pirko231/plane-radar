#pragma once
#include "flyable.hpp"

class Helicopter : public IFlyable
{
public:
    Helicopter();
    void update() override;
    void setDestination() override;
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        
    }
};
#pragma once
#include "flyable.hpp"
#include "base.hpp"

class Plane : public IFlyable
{
public:
    Plane();
    void update() override;
    void setDestination() override;
    sf::FloatRect getGlobalBounds() const override {return sprite.getGlobalBounds();}
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        
    }
    sf::Sprite sprite;
};
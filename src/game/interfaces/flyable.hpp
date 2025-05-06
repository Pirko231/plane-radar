#pragma once
#include <SFML/Graphics.hpp>

class IFlyable : public sf::Drawable, public sf::Transformable
{
public:
    IFlyable() = default;
    virtual void update() = 0;
    virtual void setDestination() = 0;

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
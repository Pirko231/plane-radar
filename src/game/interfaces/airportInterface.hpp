#pragma once
#include <SFML/Graphics.hpp>
#ifdef IMGUI
#include "imgui.h"
#include "imgui-SFML.h"
#endif


class IAirport : public sf::Drawable, public sf::Transformable
{
public:
    virtual sf::FloatRect getGlobalBounds() const = 0;
protected:
    //virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};
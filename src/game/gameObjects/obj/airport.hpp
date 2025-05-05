#pragma once
#include <SFML/Graphics.hpp>
#include "base.hpp"

class Airport : public sf::Drawable, public sf::Transformable
{
public:
    Airport(sf::Vector2f pos);

    void update();

private:
    sf::Sprite sprite;
};
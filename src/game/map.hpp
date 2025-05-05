#pragma once
#include <SFML/Graphics.hpp>
#include <span>

class Map : public sf::Drawable
{
public:
    Map(sf::Vector2u _windowSize);
    ~Map();
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(sprite, states);
    }
    sf::Vector2u windowSize;
    sf::Texture texture;
    sf::Sprite sprite;
    std::uint8_t* pixels {new std::uint8_t[windowSize.x * windowSize.y * 4]};
};
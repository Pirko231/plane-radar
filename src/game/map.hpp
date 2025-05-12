#pragma once
#include <SFML/Graphics.hpp>
#include <span>
#include "base.hpp"

struct Tile
{
public:
    using uint = std::uint8_t;
    using Color = std::tuple<uint,uint,uint,uint>;

    Tile(uint R, uint G, uint B, uint A = 255) {color = {R,G,B,A};}
    sf::Color color;

    static sf::Color empty;
    static sf::Color water;
    static sf::Color grass;
};

class Map : public sf::Drawable
{
public:
    Map(sf::Vector2u mapSize);
    ~Map();

    sf::Vector2f getRandomPoint() const;

    sf::Vector2f getCenter() const {return sprite.getGlobalBounds().getCenter();}

    sf::FloatRect getGlobalBounds() const {return sprite.getGlobalBounds();}
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override
    {
        target.draw(sprite, states);
    }

    

    sf::Color getRandomTerrain() const;
    void generateMap(sf::Texture& texture, std::span<std::uint8_t>, sf::Vector2i mapSize);
    
    sf::Vector2u windowSize;
    sf::Texture texture;
    sf::Sprite sprite;
    std::uint8_t* pixelsArr {new std::uint8_t[windowSize.x * windowSize.y * 4]};
};

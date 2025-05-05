#include "map.hpp"

Map::Map(sf::Vector2u _mapSize)
: windowSize{_mapSize}, texture{windowSize}, sprite{texture}
{
    
}

Map::~Map()
{
    delete [] pixels;
}

sf::Vector2f Map::getRandomPoint() const
{
    sf::Vector2f pos{std::rand() % windowSize.x + 1.f, std::rand() % windowSize.y + 1.f};
    return pos;
}

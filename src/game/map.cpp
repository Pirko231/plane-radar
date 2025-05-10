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
    std::uniform_int_distribution<int> x(0, windowSize.x);
    std::uniform_int_distribution<int> y(0, windowSize.y);
    sf::Vector2f pos{static_cast<float>(x(util::engine)), static_cast<float>(y(util::engine))};
    return pos;
}

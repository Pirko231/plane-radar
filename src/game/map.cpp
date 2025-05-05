#include "map.hpp"

Map::Map(sf::Vector2u _mapSize)
: windowSize{_mapSize}, texture{windowSize}, sprite{texture}
{
    
}

Map::~Map()
{
    delete [] pixels;
}

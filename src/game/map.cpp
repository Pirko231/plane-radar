#include "map.hpp"

Map::Map(sf::Vector2u _windowSize)
: windowSize{_windowSize}, texture{windowSize}, sprite{texture}
{
    
}

Map::~Map()
{
    delete [] pixels;
}

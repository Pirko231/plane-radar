#include "map.hpp"

sf::Color Tile::empty{0,0,0};
sf::Color Tile::water{0,0,255};
sf::Color Tile::grass{0,255,0};

Map::Map(sf::Vector2u _mapSize)
: windowSize{_mapSize}, texture{windowSize}, sprite{texture}
{
    generateMap(texture, {pixelsArr, windowSize.x * windowSize.y * 4}, (sf::Vector2i)_mapSize);
}

Map::~Map()
{
    delete [] pixelsArr;
}

sf::Vector2f Map::getRandomPoint() const
{
    std::uniform_int_distribution<int> x(0, windowSize.x);
    std::uniform_int_distribution<int> y(0, windowSize.y);
    sf::Vector2f pos{static_cast<float>(x(util::engine)), static_cast<float>(y(util::engine))};
    return pos;
}

sf::Color Map::getRandomTerrain() const
{
    std::uniform_int_distribution<int> randomTerrain (0,2);
    int random{randomTerrain(util::engine)};
    if (random == 0)
        return Tile::water;
    else
        return Tile::grass;
}

void Map::generateMap(sf::Texture &txt, std::span<std::uint8_t> data, sf::Vector2i mapSize)
{
    auto [width, height] {mapSize};

    int waterAmount{4};

    
    std::uniform_int_distribution<int> TerrainSize (0,9);
    std::uniform_int_distribution<int> TerrainBalance (0,3);


    txt.update(data.data());
}

#include "map.hpp"

sf::Color Tile::empty{0,0,0};
sf::Color Tile::water{0,0,255};
sf::Color Tile::grass{0,255,0};

Map::Map(sf::Vector2u _mapSize)
: windowSize{_mapSize}, texture{windowSize}, sprite{texture}
{
    generateMap(texture, {pixelsArr, windowSize.x * windowSize.y * 4}, (sf::Vector2i)_mapSize);
    delete [] pixelsArr;
    pixelsArr = nullptr;
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

void Map::generateLakes(std::span<std::uint8_t> data, int lakesAmount, sf::Vector2i mapSize)
{
    int lakeSize{200}; //od razu bierze pod uwage piksele
    for (int lakes = 0; lakes < lakesAmount; lakes++)
    {
        sf::Vector2i lakePos = static_cast<sf::Vector2i>(getRandomPoint());
        for (std::size_t x = lakePos.x; x < (lakePos.x + lakeSize) * 4; x++)
        {
            for (std::size_t y = 0; y < lakeSize; y += 4)
            {
                std::size_t pos = x + y * mapSize.y;

                setColor(&data[pos], Tile::water);
            }
        }
    }
}

void Map::fillEmpty(std::span<std::uint8_t> data, sf::Vector2i mapSize)
{
    auto isEmpty = [](std::uint8_t* where){return sf::Color{*(where), *(where + 1), *(where + 2), *(where + 3)} != Tile::empty;};


    for (std::size_t i = 0; i < mapSize.y * 4; i++)
    {
        for (std::size_t j = 0; j < mapSize.x; j += 4)
        {
            std::size_t pos = j + i * mapSize.y;

            auto color = getRandomTerrain();

            if (isEmpty(&data[pos]))
                setColor(&data[pos], color);

        }
    }
}

void Map::generateMap(sf::Texture &txt, std::span<std::uint8_t> data, sf::Vector2i mapSize)
{
    auto [width, height] {mapSize};
    int waterAmount{4};

    generateLakes(data, 20, mapSize);

    //fillEmpty(data, mapSize);

    txt.update(data.data());
}

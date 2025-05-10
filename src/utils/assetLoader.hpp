#pragma once
#include <SFML/Graphics.hpp>

#pragma GCC diagnostic ignored "-Wunused-result"


namespace util
{

class AssetLoader
{
public:
    static AssetLoader& get()
    {
        static AssetLoader a_loader;
        return a_loader;
    }

    sf::Texture airport;

    sf::Texture plane;
    sf::Texture helicopter;

    sf::Texture crash;
private:
    AssetLoader();
};

};

inline util::AssetLoader::AssetLoader()
{
    airport.loadFromFile("resources/textures/airport.png");

    plane.loadFromFile("resources/textures/plane.png");
    helicopter.loadFromFile("resources/textures/helicopter.png");

    crash.loadFromFile("resources/textures/explosion.png");
}



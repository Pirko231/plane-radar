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
private:
    AssetLoader();
};

};

inline util::AssetLoader::AssetLoader()
{
    airport.loadFromFile("resources/textures/airport.png");
}



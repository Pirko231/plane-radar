#include "airport.hpp"

Airport::Airport(sf::Vector2f pos) : sprite{util::AssetLoader::get().airport}
{
    sprite.setPosition(pos);

}

void Airport::update()
{
    
}

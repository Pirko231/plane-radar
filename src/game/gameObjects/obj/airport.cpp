#include "airport.hpp"

Airport::Airport(sf::Vector2f pos) : sprite{util::AssetLoader::get().airport}
{
    sprite.setPosition(pos);
    sprite.setScale({1.f,1.f});
}

void Airport::update()
{
    
}

bool Airport::requestLanding(IFlyable& obj)
{
    planes.push_back(&obj);
    return true;
}

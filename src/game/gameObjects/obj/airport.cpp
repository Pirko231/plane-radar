#include "airport.hpp"

Airport::Airport(sf::Vector2f pos) : sprite{util::AssetLoader::get().airport}
{
    setPosition(pos);
    sprite.setPosition(pos);
    sprite.setScale({1.f,1.f});
    
}

void Airport::update()
{
    for (auto& plane : objects)
        plane->refill();
}

bool Airport::requestLanding(IFlyable& obj)
{
    objects.push_back(&obj);
    return true;
}

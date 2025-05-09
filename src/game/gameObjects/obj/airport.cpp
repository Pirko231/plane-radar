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

void Airport::departReadyPlanes(std::function<sf::Vector2f()> where)
{
    for (auto plane = objects.begin(); plane != objects.end(); plane++)
        if ((*plane)->readyToDepart())
        {
            (*plane)->depart(where());
            if (plane == objects.end() - 1)
            {
                objects.erase(plane);
                break;
            }
            objects.erase(plane);
        }
}

bool Airport::requestLanding(IFlyable* obj)
{
    obj->land();
    objects.push_back(obj);
    return true;
}

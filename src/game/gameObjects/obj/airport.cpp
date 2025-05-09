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

void Airport::departReadyPlanes(std::function<IAirport*()> where)
{
    for (auto plane = objects.begin(); plane != objects.end(); plane++)
        if ((*plane)->readyToDepart())
        {
            IAirport* destination {where()};
            while (destination == this)
                destination = where();
            

            (*plane)->depart(destination);
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
    for (auto& i : objects)
        if (obj == i)
            return false;
        
    objects.push_back(obj);
    return true;
}

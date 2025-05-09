#include "plane.hpp"

Plane::Plane(sf::Vector2f pos)
: IFlyable{}, sprite{util::AssetLoader::get().airport}
{
    setPosition(pos);
}

void Plane::update()
{

}

void Plane::setDestination()
{

}
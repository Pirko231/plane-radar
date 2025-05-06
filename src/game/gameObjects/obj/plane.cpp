#include "plane.hpp"

Plane::Plane(sf::Vector2f pos)
: IFlyable{}, sprite{util::AssetLoader::get().airport}
{
    sprite.setPosition(pos);
}

void Plane::update()
{

}

void Plane::setDestination()
{

}
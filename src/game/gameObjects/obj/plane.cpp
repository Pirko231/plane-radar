#include "plane.hpp"

Plane::Plane(sf::Vector2f pos)
: IFlyable{util::AssetLoader::get().plane}
{
    setPosition(pos);
    sprite.setScale({0.15f,0.2f});
}

void Plane::update()
{

}

void Plane::setDestination()
{

}
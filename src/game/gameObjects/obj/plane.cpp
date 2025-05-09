#include "plane.hpp"

Plane::Plane(sf::Vector2f pos)
: IFlyable{util::AssetLoader::get().plane}
{
    setPosition(pos);
    sprite.setScale({0.15f,0.2f});
}

void Plane::update()
{
    if (getPosition() - destination != sf::Vector2f{0.f,0.f})
    {
        move({(getPosition() - destination).normalized()});
        setRotation((getPosition() - destination).angle());
    }
}

void Plane::setDestination()
{

}

void Plane::depart(sf::Vector2f target)
{
    status = Status::FLYING;
    destination = target;
}

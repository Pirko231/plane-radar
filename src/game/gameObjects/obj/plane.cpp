#include "plane.hpp"

Plane::Plane(IAirport* _target)
: IFlyable{util::AssetLoader::get().plane}
{
    target = _target;
    setPosition(target->getPosition());
    sprite.setScale({0.15f,0.2f});
    sprite.setOrigin(sprite.getGlobalBounds().getCenter());
}

void Plane::update()
{
    if (status == Status::FLYING)
    {
        fuel -= 0.1f;
        move(moveBy);
        setRotation(moveBy.angle());
    }
}

void Plane::depart(IAirport* _target)
{
    status = Status::FLYING;
    target = _target;
    destination = _target->getGlobalBounds().getCenter();
    if (destination - getPosition() != sf::Vector2f{})
        moveBy = (destination - getPosition()).normalized();
    else
        moveBy = {1.f,1.f};
}

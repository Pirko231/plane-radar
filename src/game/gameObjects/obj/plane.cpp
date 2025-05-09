#include "plane.hpp"

Plane::Plane(sf::Vector2f pos)
: IFlyable{util::AssetLoader::get().plane}
{
    setPosition(pos);
    sprite.setScale({0.15f,0.2f});
    sprite.setOrigin(sprite.getGlobalBounds().getCenter());
}

void Plane::update()
{
    if (status == Status::FLYING)
    {
        fuel--;
        move(moveBy);
        setRotation(moveBy.angle());
    }
}

void Plane::depart(IAirport* _target)
{
    status = Status::FLYING;
    target = _target;
    destination = _target->getPosition();
    if (destination - getPosition() != sf::Vector2f{})
        moveBy = (destination - getPosition()).normalized();
}

bool Plane::isNearTarget() const
{
    if (std::abs(getPosition().x - destination.x) < 40.f && std::abs(getPosition().y - destination.y) < 40.f  && status == Status::FLYING)
        return true;

    return true;
}

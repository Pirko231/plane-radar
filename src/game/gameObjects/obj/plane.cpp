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
    fuel--;
    if (getPosition() - destination != sf::Vector2f{0.f,0.f})
    {
        //move({(getPosition() - destination).normalized()});
        move(moveBy);
        setRotation(moveBy.angle());
    }
}

void Plane::depart(IAirport* _target)
{
    status = Status::FLYING;
    target = _target;
    destination = _target->getPosition();
    if (getPosition() - destination != sf::Vector2f{})
        moveBy = (getPosition() - destination).normalized();
}

bool Plane::isNearTarget() const
{
    if (std::abs(getPosition().x - destination.x) < 20.f && std::abs(getPosition().y - destination.y) < 20.f  && status == Status::FLYING)
        return true;

    return true;
}

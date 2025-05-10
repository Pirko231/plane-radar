#include "helicopter.hpp"

Helicopter::Helicopter(sf::Vector2f pos)
: IFlyable{util::AssetLoader::get().helicopter}
{
    setPosition(pos);
}

void Helicopter::update()
{

}

IAirport* Helicopter::getTarget() const
{
    return nullptr;
}
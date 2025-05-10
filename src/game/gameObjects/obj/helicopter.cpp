#include "helicopter.hpp"

Helicopter::Helicopter(sf::Vector2f pos)
: IFlyable{util::AssetLoader::get().helicopter}
{
    setPosition(pos);
}

void Helicopter::update()
{

}

sf::FloatRect Helicopter::getTarget() const
{
    return sf::FloatRect{};
}
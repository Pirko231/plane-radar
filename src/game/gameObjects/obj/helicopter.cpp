#include "helicopter.hpp"

Helicopter::Helicopter(sf::Vector2f pos)
: IFlyable{util::AssetLoader::get().helicopter}
{
    setPosition(pos);
}

void Helicopter::update()
{

}

void Helicopter::setDestination()
{
    
}
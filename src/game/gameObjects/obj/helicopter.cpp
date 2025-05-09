#include "helicopter.hpp"

Helicopter::Helicopter(sf::Vector2f pos)
: IFlyable{}, sprite{util::AssetLoader::get().airport}
{
    setPosition(pos);
}

void Helicopter::update()
{

}

void Helicopter::setDestination()
{
    
}
#include "program.hpp"
#include <iostream>

int main()
{
    sf::Clock deltaTimeClock;
    Program program;
    while (program.running())
    {
        util::dt = deltaTimeClock.restart().asSeconds();
        program.handleEvents();
        program.update();
        program.display();
    }
}
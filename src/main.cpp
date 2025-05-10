#include "program.hpp"
#include <ctime>

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
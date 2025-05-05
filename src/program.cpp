#include "program.hpp"

Program::Program()
: map{{200u,200u}}, airportManager{10, &map}
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode{{1280, 720}, 32}, sf::String{"Plane radar"} , sf::Style::Close | sf::Style::Titlebar);
}

Program::~Program()
{
    delete window;
}

void Program::handleEvents()
{
    while (const std::optional ev = window->pollEvent())
    {
        if (ev->is<sf::Event::Closed>())
            window->close();
    }
    
}

void Program::update()
{
    airportManager.update();
}

void Program::display()
{
    window->clear();


    airportManager.display(window);


    window->display();
}

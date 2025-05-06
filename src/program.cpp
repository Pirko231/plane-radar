#include "program.hpp"

Program::Program()
: map{mapSize}, airportManager{4, &map}
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode{mapSize, 32}, sf::String{"Plane radar"} , sf::Style::Close | sf::Style::Titlebar);

    view.setCenter(map.getCenter());
    view.zoom(0.5f);
}

Program::~Program()
{
    delete window;
}

void Program::handleEvents()
{
    keyPressed.clear();
    keyReleased.clear();
    while (const std::optional ev = window->pollEvent())
    {
        if (ev->is<sf::Event::Closed>())
            window->close();
        if (const auto* keyP = ev->getIf<sf::Event::KeyPressed>())
            keyPressed[keyP->code] = true;
        if (const auto* keyR = ev->getIf<sf::Event::KeyReleased>())
            keyReleased[keyR->code] = true;
    }
    
}

void Program::update()
{
    airportManager.update();

    manageView();
}

void Program::display()
{
    window->clear();
    window->setView(view);

    airportManager.display(window);

    
    window->display();
}

void Program::manageView()
{   
    sf::Vector2f moveView{};
    if (keyPressed[sf::Keyboard::Key::W])
        moveView += {0.f,-1.f};
    if (keyPressed[sf::Keyboard::Key::S])
        moveView += {0.f,1.f};
    if (keyPressed[sf::Keyboard::Key::A])
        moveView += {-1.f,0.f};
    if (keyPressed[sf::Keyboard::Key::D])
        moveView += {1.f,0.f};
    
    if (moveView != sf::Vector2f{})
        moveView = moveView.normalized();
    moveView *= moveViewSpeed;
    
    view.move(moveView);
}

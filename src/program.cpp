#include "program.hpp"

Program::Program()
: map{mapSize}, airportManager{4, &map}, flightControl{(sf::Vector2u)map.getGlobalBounds().size, 10, airportManager}
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode{mapSize, 32}, sf::String{"Plane radar"} , sf::Style::Close | sf::Style::Titlebar);
    window->setFramerateLimit(75);

    view.setCenter(map.getCenter());
    view.zoom(0.5f);
}

Program::~Program()
{
    delete window;
}

void Program::handleEvents()
{
    //released dziala tylko na jedna klatke
    for (auto& key : keys)
        key.second.released = false;
    for (auto& mButton : mButtons)
        mButton.second.released = false;
    
    scrolled = 0.f;
    while (const std::optional ev = window->pollEvent())
    {
        if (ev->is<sf::Event::Closed>())
            window->close();
        if (const auto* keyP = ev->getIf<sf::Event::KeyPressed>())
            keys[keyP->scancode].pressed = true;
        if (const auto* keyR = ev->getIf<sf::Event::KeyReleased>())
        {
            keys[keyR->scancode].pressed = false;
            keys[keyR->scancode].released = true;
        }
        if (const auto* mButtonP = ev->getIf<sf::Event::MouseButtonPressed>())
            mButtons[mButtonP->button].pressed = true;
        if (const auto* mButtonR = ev->getIf<sf::Event::MouseButtonReleased>())
        {
            mButtons[mButtonR->button].pressed = true;
            mButtons[mButtonR->button].released = true;
        }
        if (const auto* mWheel = ev->getIf<sf::Event::MouseWheelScrolled>())
            scrolled = mWheel->delta;
    }
    
}

void Program::update()
{
    airportManager.update();
    flightControl.update();

    manageView();
}

void Program::display()
{
    window->clear();
    window->setView(view);

    airportManager.display(window);
    flightControl.display(window);

    
    window->display();
}

void Program::manageView()
{   
    //move the view
    sf::Vector2f moveView{};
    if (keys[sf::Keyboard::Scan::W].pressed)
        moveView += {0.f,-1.f};
    if (keys[sf::Keyboard::Scan::S].pressed)
        moveView += {0.f,1.f};
    if (keys[sf::Keyboard::Scan::A].pressed)
        moveView += {-1.f,0.f};
    if (keys[sf::Keyboard::Scan::D].pressed)
        moveView += {1.f,0.f};
    
    if (moveView != sf::Vector2f{})
        moveView = moveView.normalized();
    moveView *= moveViewSpeed * util::dt;
    
    view.move(moveView);

    //zoom the view

    if (scrolled > 0)
        view.zoom(0.9f);
    if (scrolled < 0)
        view.zoom(1.1f);
    
}

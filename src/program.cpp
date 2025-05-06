#include "program.hpp"

Program::Program()
: map{mapSize}, airportManager{4, &map}
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
    keyPressed.clear();
    keyReleased.clear();
    mButtonPressed.clear();
    mButtonReleased.clear();
    scrolled = 0.f;
    while (const std::optional ev = window->pollEvent())
    {
        if (ev->is<sf::Event::Closed>())
            window->close();
        if (const auto* keyP = ev->getIf<sf::Event::KeyPressed>())
            keyPressed[keyP->scancode] = true;
        if (const auto* keyR = ev->getIf<sf::Event::KeyReleased>())
            keyReleased[keyR->scancode] = true;
        if (const auto* mButtonP = ev->getIf<sf::Event::MouseButtonPressed>())
            mButtonPressed[mButtonP->button] = true;
        if (const auto* mButtonR = ev->getIf<sf::Event::MouseButtonReleased>())
            mButtonReleased[mButtonR->button] = true;
        if (const auto* mWheel = ev->getIf<sf::Event::MouseWheelScrolled>())
            scrolled = mWheel->delta;
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
    //move the view
    sf::Vector2f moveView{};
    if (keyPressed[sf::Keyboard::Scan::W])
        moveView += {0.f,-1.f};
    if (keyPressed[sf::Keyboard::Scan::S])
        moveView += {0.f,1.f};
    if (keyPressed[sf::Keyboard::Scan::A])
        moveView += {-1.f,0.f};
    if (keyPressed[sf::Keyboard::Scan::D])
        moveView += {1.f,0.f};
    
    if (moveView != sf::Vector2f{})
        moveView = moveView.normalized();
    moveView *= moveViewSpeed * util::dt;
    
    view.move(moveView);

    //zoom the view
    /*float zoomView{};
    if (scrolled > 0)
        zoomView = zoomViewSpeed;
    if (scrolled < 0)
        zoomView = 1.f / zoomViewSpeed;

    zoomView *= util::dt;
    view.zoom(zoomView);*/
}

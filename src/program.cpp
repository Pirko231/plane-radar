#include "program.hpp"

Program::Program()
: map{mapSize}, airportManager{util::ConfigLoader::get().airportAmount, &map}, flightControl{(sf::Vector2u)map.getGlobalBounds().size, 4, airportManager}
{
    window = new sf::RenderWindow;
    window->create(sf::VideoMode{{1280u,720u}, 32}, sf::String{"Plane radar"} , sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    window->setFramerateLimit(75);
#ifdef IMGUI
    ImGui::SFML::Init(*window);
#endif

    view.setCenter(map.getCenter());
    view.setSize(map.getGlobalBounds().size);
}

Program::~Program()
{
#ifdef IMGUI
    ImGui::SFML::Shutdown();
#endif
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

#ifdef IMGUI
        ImGui::SFML::ProcessEvent(*window, *ev);
#endif
    }
    
}

void Program::update()
{
#ifdef IMGUI
    ImGui::SFML::Update(*window, sf::seconds(util::dt));
    ImGui::Begin("Debug tools");
    if (ImGui::Button("Pause"))
        paused = !paused;
    ImGui::End();
#endif

    manageView();
    if (keys[sf::Keyboard::Scan::Space].released)
        paused = !paused;

    airportManager.update(paused);
    flightControl.update(paused);
}

void Program::display()
{
    window->clear();
    window->setView(view);

    airportManager.display(window);
    flightControl.display(window);


#ifdef IMGUI
    ImGui::SFML::Render(*window);
#endif
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
    
    moveView.x *= view.getSize().x / 140.f *  moveViewSpeed * util::dt;
    moveView.y *= view.getSize().x / 140.f *  moveViewSpeed * util::dt; //celowo x aby poruszal sie rownomiernie
    
    if (keys[sf::Keyboard::Scan::LShift].pressed)
        moveView *= 3.f;
    
    view.move(moveView);

    //zoom the view

    if (scrolled > 0)
        view.zoom(0.9f);
    if (scrolled < 0)
        view.zoom(1.1f);
    
}

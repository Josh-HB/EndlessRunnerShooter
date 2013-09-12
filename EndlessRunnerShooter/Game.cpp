#include "Game.h"

Game::Game()
{
    mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768),"Game", sf::Style::Default);
}

void Game::Run()
{
    //TIme Step
    sf::Clock clock;

    //main Character
    Hero hero(0, sf::Vector2f(200.f,200.f), 20.f, 1.f);

    //main loop
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow->close();
        }
        sf::Time timePassed = clock.restart();
        hero.Update(timePassed.asSeconds(), *mWindow);
        mWindow->clear();
        hero.Render(*mWindow);
        mWindow->display();
    }
}
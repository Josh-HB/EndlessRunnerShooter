#include "Game.h"

Game::Game()
{
    mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768),"Game", sf::Style::Default);
}

void Game::Run()
{
    while (mWindow->isOpen())
    {
        sf::Event event;
        while (mWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                mWindow->close();
        }

        mWindow->clear();

        mWindow->display();
    }
}
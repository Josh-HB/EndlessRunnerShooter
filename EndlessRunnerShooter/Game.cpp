#include "Game.h"

Game::Game() : 
    mShotList(std::make_shared<std::vector<Shot> >()) 
{
    mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(1024, 768),"Game", sf::Style::Default);
    if(!mBackground.loadFromFile("Art/Background.png"));
    {
        //assert out
    }
    mBgSprite.setTexture(mBackground);
    mShotTex.loadFromFile("Art/Shot.png");
}                                                                                                                                                                                                                                                                                                                

void Game::Run()
{
    //TIme Step
    sf::Clock clock;

    //main Character
    Hero hero(0, sf::Vector2f(200.f,200.f), 32.f, 1.f, *this);

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
        
        float secondsPassed = timePassed.asSeconds();
        hero.Update(secondsPassed, *mWindow);

        for(int i = 0; i < mShotList->size(); i++)
        {
            Shot &pShot = mShotList->at(i);
            pShot.Update(secondsPassed);
            float posX = pShot.GetPosition().x;
            float posY = pShot.GetPosition().y;
            //TODO: Shot max distance
            if(posX < 0 || posX > 1024 ||
               posY < 0 || posY > 768)
            {
                mShotList->erase(mShotList->begin() + i);
                i++;
            }
        } 

        mWindow->clear();
        mWindow->draw(mBgSprite);
        hero.Render(*mWindow);
        for(int i = 0; i < mShotList->size(); i++)
        {
            Shot &pShot = mShotList->at(i);
            pShot.Draw(*mWindow);
        }
        mWindow->display();
    }
}

void Game::shoot(sf::Transformable& performer)
{
    mShotList->push_back(Shot(performer.getPosition(), performer.getRotation(), mShotTex)); 
}
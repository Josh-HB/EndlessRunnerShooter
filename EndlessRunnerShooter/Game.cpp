#include <iterator>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Game.h"
#include "Shot.h"
#include "ShotPtr.h"
#include "HeroPtr.h"
#include "Hero.h"
#include "IDrawablePtr.h"
#include "Platform.h"
#include "IDrawable.h"


static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 768;

Game::Game() : 
    mWindow(NULL),
    mDrawableList(),
    mNewDrawables(),
    mTime(0.0f),
    mDeltaTime(0.01f),
    mAccumulator(0.0f)
{
    mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Default);
    mWindow->setKeyRepeatEnabled(false);
    if(!mBackground.loadFromFile("Art/Background.png"))
    {
        //assert out
    }
    mBgSprite.setTexture(mBackground);
    mShotTex.loadFromFile("Art/Shot.png");

}

bool HasLifetimeExpired(IDrawablePtr drawable, const sf::Time& currentTime)
{
    /*float durationOfLife = (currentTime - drawable->GetTimeOfBirth()).asSeconds();
    float maximumLifetime = drawable->GetTimeToLive();
    if(drawable->GetTimeToLive() > 0)
    {
    if(durationOfLife > maximumLifetime)
    {
    return true;
    }
    } 
    return false;*/
    return false;
}

bool IsOutOfBounds(IDrawablePtr drawable)
{
    sf::Vector2f pos;
    drawable->GetPosition(pos);
    if(drawable->DestroyOnScreenExit())
    {
        if(pos.x < 0 || pos.x > WINDOW_WIDTH ||
            pos.y < 0 || pos.y > WINDOW_HEIGHT)
        {
            return true;
        }
    }
    return false;
}

void Game::Run()
{
    //TIme Step
    sf::Clock clock;

    //main Character
    std::shared_ptr<Hero> hero = std::make_shared<Hero>(sf::Vector2f(200.f,200.f), 32.f, 1.f, *this);
    mDrawableList.push_back(hero);

    //main Platform
    std::shared_ptr<Platform> platform = std::make_shared<Platform>(1, sf::Vector2f(50.f, 500.f), 400.f, 100.f, *this);
    mDrawableList.push_back(platform);

    //main loop
    while (mWindow->isOpen())
    {
        float frameTime = clock.restart().asSeconds();
        if(frameTime > 0.25f)
            frameTime = 0.25f;

        mAccumulator += frameTime;

        while( mAccumulator >= mDeltaTime )
        {
            //event loop / non-blocking
            sf::Event event;
            while (mWindow->pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    mWindow->close();
                if(event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                        hero->Shooting();
                }
            }

            mDrawableList.insert(mDrawableList.end(), mNewDrawables.begin(), mNewDrawables.end());
            mNewDrawables.clear();
            for(std::vector<IDrawablePtr>::iterator it = mDrawableList.begin(); it != mDrawableList.end();)
            {
                (*it)->Update(1.f/60.f, *mWindow);
                if(IsOutOfBounds(*it))// || HasLifetimeExpired(*it, currentTime))
                {
                    it = mDrawableList.erase(it);
                }
                else
                {
                    it++;
                }
            }

            mTime += mDeltaTime;
            mAccumulator -= mDeltaTime;
        }

        std::cout << 1.f /frameTime << "\n";

        mWindow->clear();
        mWindow->draw(mBgSprite);		
        for(std::vector<IDrawablePtr>::iterator it = mDrawableList.begin(); it != mDrawableList.end(); ++it)
        {
            (*it)->Draw(*mWindow);
        }
        mWindow->display();
    }
}

void Game::Shoot(sf::Transformable& performer)
{
    mNewDrawables.push_back(std::make_shared<Shot>(performer.getPosition(), performer.getRotation(), mShotTex));
}
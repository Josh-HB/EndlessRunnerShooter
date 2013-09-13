#include <iterator>
#include <vector>
#include "Game.h"
#include "Shot.h"
#include "Hero.h"

static const int WINDOW_WIDTH = 1024;
static const int WINDOW_HEIGHT = 768;

static const float MAX_SHOT_DISTANCE = 400;
static const float MAX_SHOT_DISTANCE_SQ = MAX_SHOT_DISTANCE*MAX_SHOT_DISTANCE;

Game::Game() : 
    mShotList(std::make_shared<std::vector<ShotPtr> >()) 
{
    mWindow = std::make_shared<sf::RenderWindow>(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game", sf::Style::Default);
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
        float secondsPassed = clock.restart().asSeconds();
        hero.Update(secondsPassed, *mWindow);

        for(std::vector<ShotPtr>::iterator it = mShotList->begin(); it != mShotList->end();)
        {
            (*it)->Update(secondsPassed);
			sf::Vector2f shotPos = (*it)->GetPosition();
			// Would it be better to base this on travel time to live?
			sf::Vector2f travelVector = shotPos - hero.getPosition();
            if(shotPos.x < 0 || shotPos.x > WINDOW_WIDTH ||
               shotPos.y < 0 || shotPos.y > WINDOW_HEIGHT||
			   (travelVector.x*travelVector.x + travelVector.y*travelVector.y) > MAX_SHOT_DISTANCE_SQ)
            {
                it = mShotList->erase(it);
            }
			else 
			{
				it++;
			}
        } 

        mWindow->clear();
        mWindow->draw(mBgSprite);
        hero.Render(*mWindow);
        for(int i = 0; i < mShotList->size(); i++)
        {
            ShotPtr pShot = mShotList->at(i);
            pShot->Draw(*mWindow);
        }
        mWindow->display();
    }
}

void Game::shoot(sf::Transformable& performer)
{
    mShotList->push_back(std::make_shared<Shot>(performer.getPosition(), performer.getRotation(), mShotTex)); 
}
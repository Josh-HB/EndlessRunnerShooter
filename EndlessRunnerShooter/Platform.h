#ifndef PLATFORM_H
#define PLATFORM_H

#include "StationaryEntity.h"
#include "IDrawable.h"
#include <SFML/Graphics/RectangleShape.hpp>

class IActions;

class Platform : public StationaryEntity, public IDrawable
{
private:
    //Rectangle dimensions
    float mWidth;
    float mHeight;

    sf::RectangleShape mShape;
    
    IActions& mActions;
public:
    //starting and end point for each platform, used for interpolation
    sf::Vector2f mStartPoint, mEndPoint;

    Platform(int id, sf::Vector2f pos, float width, float height, IActions& actions);
    virtual void Update(float time_passed, sf::RenderWindow &win);
    virtual void Draw(sf::RenderWindow &window);
    virtual void GetPosition(sf::Vector2f& position) { position = mPosition; }
    virtual float GetTimeToLive() const { return -1; }
    virtual sf::Time GetTimeOfBirth() const { return sf::Time::Zero; }
    virtual bool DestroyOnScreenExit() const { return false; }
};

#endif

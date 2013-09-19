#ifndef HERO_H
#define HERO_H

#include "MovingEntity.h"
#include "IDrawable.h"
#include <cmath>
#include <algorithm>
#include <memory>

//Only cool kids forward declare
class IActions;

class Hero : public MovingEntity, public IDrawable
{
private:
    sf::Texture mWheelTexture;
    sf::Sprite mWheelSprite;

    sf::Texture mHelmetTexture;
    sf::Sprite mHelmetSprite;

    sf::CircleShape mMountSprite;
    sf::RectangleShape mTurretSprite;

    // TODO: This is not required, Entity.h Has a BoundingRadius attribute.
    // We can either remove this or re factor the base to not require a radius
    // Which might be a better idea.
    float mRadius;

    IActions& mActions;

    void SetPosition(sf::Vector2f& newPosition);
    
public:
    Hero(sf::Vector2f pos, float radius, float scale, IActions& actions);
    virtual void Update(float time_passed, sf::RenderWindow &win);
    virtual void Draw(sf::RenderWindow &window);
	virtual void GetPosition(sf::Vector2f& position) { position = mPosition; }
	virtual float GetTimeToLive() const { return -1; }
	virtual bool DestroyOnScreenExit() const { return false; }

    void Shooting();
    void Jump();
};

#endif
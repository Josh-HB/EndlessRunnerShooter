#ifndef ENEMEY_H 
#define ENEMEY_H

#include "MovingEntity.h"
#include "IDrawable.h"
#include <cmath>
#include <algorithm>
#include <memory>

//forward declare to be cool
class IActions;

class Enemy : public MovingEntity, public IDrawable
{
protected:
    sf::Texture mEnemyTexture;
    sf::Sprite mEnemySprite;

    float mRadius;

    IActions& mActions;

    void SetPosition(sf::Vector2f& newPosition);

public:
    Enemy(sf::Vector2f pos, float radius, float scale, IActions& actions, sf::Time currentTime);
    virtual void Update(float time_passed, sf::RenderWindow &win);
    virtual void Draw(sf::RenderWindow &window);
    virtual void GetPosition(sf::Vector2f& position) { position = mPosition; }
    virtual float GetTimeToLive() const { return -1; }
    virtual bool DestroyOnScreenExit() const { return false; }
};

#endif
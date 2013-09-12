#include "Shot.h"

Shot::Shot(sf::Vector2f pos, float rotation) : mPosition(pos),
                                               mRotation(rotation)
{
    mShotSprite = sf::RectangleShape(sf::Vector2f(3.f, 1.f));
    mShotSprite.setOrigin(sf::Vector2f(0.f, 0.5f));
    mShotSprite.setPosition(mPosition);
    mShotSprite.setRotation(mRotation);
}

void Shot::Update(float time_passed)
{
    //need to convert from degrees to radians
    float angle = (3.14159/180) * mShotSprite.getRotation();
    float newx = time_passed * cos(angle);
    float newy = time_passed * sin(angle);

    //need to have a specific shot speed
    sf::Vector2f newPos = mShotSprite.getPosition();
    newPos.x += newx * 250.f;
    newPos.y += newy * 250.f;

    mShotSprite.setPosition(newPos);
}

void Shot::Draw(sf::RenderWindow &window)
{
   window.draw(mShotSprite);
}
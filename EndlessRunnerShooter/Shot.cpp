#include "Shot.h"

Shot::Shot(sf::Vector2f pos, float rotation, sf::Texture& texture) : 
mPosition(pos),
mRotation(rotation)
{
    mShotSprite = sf::CircleShape(2.f);
    mShotSprite.setOrigin(2.f, 2.f);
    mShotSprite.setPosition(mPosition);
    mShotSprite.setRotation(mRotation);
    mShotSprite.setTexture(&texture);
}

void Shot::Update(float time_passed, sf::RenderWindow &win)
{
    //need to convert from degrees to radians
    float angle = (3.14159f/180) * mShotSprite.getRotation();
    float newx = time_passed * cos(angle);
    float newy = time_passed * sin(angle);

    //need to have a specific shot speed
    sf::Vector2f newPos = mShotSprite.getPosition();
    newPos.x += newx * 750.f;
    newPos.y += newy * 750.f;
    mPosition = newPos;
    mShotSprite.setPosition(mPosition);
}

void Shot::Draw(sf::RenderWindow &window)
{
   window.draw(mShotSprite);
}
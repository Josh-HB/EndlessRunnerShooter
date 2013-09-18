#include "Enemy.h"

static const float PI = 3.14159f;
static const float PI_RAD = 180 / PI;

Enemy::Enemy(sf::Vector2f pos, float radius, float scale, IActions& actions, sf::Time currentTime) : 
MovingEntity(0, pos, radius, scale), 
mActions(actions)
{

}

void Enemy::Update(float time_passed, sf::RenderWindow &win)
{
    /*float currentRotation = mWheelSprite.getRotation();
    mWheelSprite.setRotation( currentRotation += 1000.f * time_passed );

    float dx =  sf::Mouse::getPosition(win).x - mMountSprite.getPosition().x;
    float dy = sf::Mouse::getPosition(win).y - mMountSprite.getPosition().y;

    float mountRotation = (atan2(dy,dx)) * PI_RAD;
    mMountSprite.setRotation(mountRotation);
    mTurretSprite.setRotation(mMountSprite.getRotation());

    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        mActions.Shoot(mTurretSprite);
    } 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if(mDownwardVelocity == 0)
        {
            mDownwardVelocity = 0.25f;
        }
    }

    sf::Vector2f currentPos;
    GetPosition(currentPos);
    mDownwardVelocity -= time_passed;
    SetPosition(currentPos - sf::Vector2f(0, mDownwardVelocity));*/
}

void Enemy::Draw(sf::RenderWindow &window)
{
    window.draw(mEnemySprite);
}

void Enemy::SetPosition(sf::Vector2f& newPosition)
{
//    static const int WINDOW_HEIGHT = 768; //This is temporary, Hero shouldn't know about window dimensions
//    if(newPosition.y > (WINDOW_HEIGHT - mWheelSprite.getLocalBounds().height/2.0f)){
//        mDownwardVelocity = 0;
//        return;
//    }
//    mPosition = newPosition;
//    mWheelSprite.setPosition(newPosition);
//    mHelmetSprite.setPosition(mWheelSprite.getPosition() - mWheelSprite.getOrigin());
//    mMountSprite.setPosition(mWheelSprite.getPosition());
//    mTurretSprite.setPosition(mMountSprite.getPosition());
//    mTurretSprite.setRotation(mMountSprite.getRotation());
}
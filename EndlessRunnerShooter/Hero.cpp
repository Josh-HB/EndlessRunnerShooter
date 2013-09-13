#include "Hero.h"
#include "IActions.h"

Hero::Hero(int id, sf::Vector2f pos, float radius, float scale, IActions& actions):MovingEntity(id, pos, radius, scale), mActions(actions)
{
    if(!mWheelTexture.loadFromFile("Art/Wheelie.png"));
    {
        //assert out
    }
    mWheelSprite.setTexture((mWheelTexture));
    mWheelSprite.setOrigin(sf::Vector2f(mBoundingRadius, mBoundingRadius));
    mWheelSprite.setPosition(mPosition);

    if(!mHelmetTexture.loadFromFile("Art/Helmet.png"))
    {

    }
    mHelmetSprite.setTexture(mHelmetTexture);
    mHelmetSprite.setPosition(mWheelSprite.getPosition() - mWheelSprite.getOrigin());

    mMountSprite = sf::CircleShape(mBoundingRadius/6.f);
    mMountSprite.setOrigin(sf::Vector2f(mBoundingRadius/6.f, mBoundingRadius/6.f));
    mMountSprite.setFillColor(sf::Color::Red);
    mMountSprite.setPosition(mWheelSprite.getPosition());

    mTurretSprite = sf::RectangleShape(sf::Vector2f(16.f, 6.f));
    mTurretSprite.setOrigin(sf::Vector2f(0.f, 3.f));
    mTurretSprite.setFillColor(sf::Color::Green);
    mTurretSprite.setPosition(mMountSprite.getPosition());
    mTurretSprite.setRotation(mMountSprite.getRotation());

}

void Hero::Update(float time_passed, sf::RenderWindow &win)
{
    float currentRotation = mWheelSprite.getRotation();
    mWheelSprite.setRotation( currentRotation += 1000.f * time_passed );

    float dx =  sf::Mouse::getPosition(win).x - mMountSprite.getPosition().x;
    float dy = sf::Mouse::getPosition(win).y - mMountSprite.getPosition().y;

    float mountRotation = (atan2(dy,dx)) * 180 / 3.14159;
    mMountSprite.setRotation(mountRotation);
    mTurretSprite.setRotation(mMountSprite.getRotation());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        mActions.shoot(mTurretSprite);
    }
}

void Hero::Render(sf::RenderWindow &window)
{
    window.draw(mWheelSprite);
    window.draw(mHelmetSprite);
    window.draw(mMountSprite);
    window.draw(mTurretSprite);
}
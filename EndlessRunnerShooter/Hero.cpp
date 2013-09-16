#include "Hero.h"
#include "IActions.h"

static const float PI = 3.14159f;
static const float PI_RAD = 180 / PI;

Hero::Hero(sf::Vector2f pos, float radius, float scale, IActions& actions, sf::Time currentTime) : 
	MovingEntity(0, pos, radius, scale), 
	mActions(actions), 
	mTimeOfBirth(currentTime)
{
    if(!mWheelTexture.loadFromFile("Art/Wheelie.png"))
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

    float mountRotation = (atan2(dy,dx)) * PI_RAD;
    mMountSprite.setRotation(mountRotation);
    mTurretSprite.setRotation(mMountSprite.getRotation());

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        mActions.Shoot(mTurretSprite);
    }
}

void Hero::Draw(sf::RenderWindow &window)
{
    window.draw(mWheelSprite);
    window.draw(mHelmetSprite);
    window.draw(mMountSprite);
    window.draw(mTurretSprite);
}
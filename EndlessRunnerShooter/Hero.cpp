#include "Hero.h"

Hero::Hero(int id, sf::Vector2f pos, float radius, float scale):MovingEntity(id, pos, radius, scale) 
{
    if(!mWheelTexture.loadFromFile("Art/Wheelie.png"));
    {
        //assert out
    }
    mWheelSprite.setTexture((mWheelTexture));
    mWheelSprite.setOrigin(sf::Vector2f(mBoundingRadius, mBoundingRadius));
    mWheelSprite.setPosition(mPosition);

    mMountSprite = sf::CircleShape(mBoundingRadius/6.f);
    mMountSprite.setOrigin(sf::Vector2f(mBoundingRadius/6.f, mBoundingRadius/6.f));
    mMountSprite.setFillColor(sf::Color::Red);
    mMountSprite.setPosition(mWheelSprite.getPosition());

    mTurretSprite = sf::RectangleShape(sf::Vector2f(16.f, 6.f));
    mTurretSprite.setOrigin(sf::Vector2f(0.f, 3.f));
    mTurretSprite.setFillColor(sf::Color::Green);
    mTurretSprite.setPosition(mMountSprite.getPosition());
    mTurretSprite.setRotation(mMountSprite.getRotation());

    mShotList = std::make_shared<std::vector<Shot> >();
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
        mShotList->push_back(Shot(mTurretSprite.getPosition(), mTurretSprite.getRotation()));
    }
    
    for(int i = 0; i < mShotList->size(); i++)
    {
        Shot &pShot = mShotList->at(i);
        pShot.Update(time_passed);
        float posX = pShot.GetPosition().x;
        float posY = pShot.GetPosition().y;
        //TODO: Shot max distance
        if(posX < 0 || posX > 1024 ||
              posY < 0 || posY > 768)
        {
            mShotList->erase(mShotList->begin() + i);
            i++;
        }
    }
    
}

void Hero::Render(sf::RenderWindow &window)
{
    window.draw(mWheelSprite);
    window.draw(mMountSprite);
    window.draw(mTurretSprite);
    for(int i = 0; i < mShotList->size(); i++)
    {
        Shot &pShot = mShotList->at(i);
        pShot.Draw(window);
    }

}
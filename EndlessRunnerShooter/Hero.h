#include "MovingEntity.h"
#include "IDrawable.h"
#include "SFML/System/Clock.hpp"
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

    float mRadius;

    IActions& mActions;
	sf::Time mTimeOfBirth;
    
public:
    Hero(sf::Vector2f pos, float radius, float scale, IActions& actions, sf::Time currentTime);
    virtual void Update(float time_passed, sf::RenderWindow &win);
    virtual void Draw(sf::RenderWindow &window);
	virtual void GetPosition(sf::Vector2f& position) { position = mPosition; }
	virtual float GetTimeToLive() const { return -1; }
	virtual sf::Time GetTimeOfBirth() const { return mTimeOfBirth; }
	virtual bool DestroyOnScreenExit() const { return false; }
};
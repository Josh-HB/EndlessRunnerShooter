#include "MovingEntity.h"
#include "Shot.h"
#include <cmath>
#include <algorithm>
#include <memory>

class IActions;

class Hero : public MovingEntity
{
private:
    sf::CircleShape mHeroSprite;
    sf::CircleShape mMountSprite;
    sf::RectangleShape mTurretSprite;
	IActions& mActions;
public:
    Hero(int id, sf::Vector2f pos, float radius, float scale, IActions& actions);
    void Update(float time_passed, sf::RenderWindow &win);
    void Render(sf::RenderWindow &window);

};
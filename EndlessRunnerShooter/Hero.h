#include "MovingEntity.h"
#include <cmath>
#include <algorithm>
#include <memory>

//Only cool kids forward declare
class IActions;

class Hero : public MovingEntity
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
    
public:
    Hero(int id, sf::Vector2f pos, float radius, float scale, IActions& actions);
    void Update(float time_passed, sf::RenderWindow &win);
    void Render(sf::RenderWindow &window);

};
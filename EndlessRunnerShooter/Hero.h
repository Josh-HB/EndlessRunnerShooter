#include "MovingEntity.h"
#include "Shot.h"
#include <cmath>
#include <algorithm>
#include <memory>

class Hero : public MovingEntity
{
private:
    sf::Texture mWheelTexture;
    sf::Sprite mWheelSprite;

    sf::CircleShape mMountSprite;
    sf::RectangleShape mTurretSprite;

    float mRadius;

    std::shared_ptr<std::vector<Shot> > mShotList;
    
public:
    Hero(int id, sf::Vector2f pos, float radius, float scale);
    void Update(float time_passed, sf::RenderWindow &win);
    void Render(sf::RenderWindow &window);

};
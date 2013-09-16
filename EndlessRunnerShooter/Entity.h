#include "SFML/Graphics.hpp"

class Entity
{
protected:
    int mId;
    sf::Vector2f mPosition;
    float mBoundingRadius;
    float mScale;
public:
    Entity(int id, sf::Vector2f pos, float radius, float scale) : mId(id),
                                                                  mPosition(pos),
                                                                  mBoundingRadius(radius),
                                                                  mScale(scale) {}
};
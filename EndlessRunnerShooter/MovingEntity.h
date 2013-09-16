#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "Entity.h"

class MovingEntity : public Entity
{
protected:
    sf::Vector2f mVelocity;
    sf::Vector2f mHeading;
    sf::Vector2f mSide;
    double mMass;
    double mMaxSpeed;
    double mMaxForce;

public:
    MovingEntity(int id, sf::Vector2f pos, float radius, float scale):Entity(id, pos, radius, scale){}

};

#endif
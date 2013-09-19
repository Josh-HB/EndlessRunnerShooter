#ifndef MOVINGENTITY_H
#define MOVINGENTITY_H

#include "Entity.h"

class MovingEntity : public Entity
{
protected:
    sf::Vector2f mTrajectory; // used for determining the entities movement direction
    sf::Vector2f mHeading; // used for forward facing value
    sf::Vector2f mSide; // used to determine which way is up
    double mMass;
    double mMaxSpeed;
    double mMaxForce;

public:
    MovingEntity(int id, sf::Vector2f pos, float radius, float scale):Entity(id, pos, radius, scale){}
    virtual void Update(float time_passed);

};

#endif
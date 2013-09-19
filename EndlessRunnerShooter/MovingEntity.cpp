#include "MovingEntity.h"

void MovingEntity::Update(float time_passed)
{
    mPosition.y += mTrajectory.y * time_passed;
    mTrajectory.y += 1500.f /*Gravity*/ * time_passed; 
}
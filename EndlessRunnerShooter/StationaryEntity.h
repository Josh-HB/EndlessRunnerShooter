#ifndef _STATIONARY_ENTITY_H
#define _STATIONARY_ENTITY_H

#include "Entity.h"

class StationaryEntity : public Entity
{
protected:
public:
    StationaryEntity(int id, sf::Vector2f pos, float radius, float scale):Entity(id, pos, radius, scale){}
};

#endif
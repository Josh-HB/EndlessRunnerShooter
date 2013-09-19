#ifndef __IDRAWABLE__H_
#define __IDRAWABLE__H_

#include "SFML/System/Vector2.hpp"

namespace sf {
	class RenderWindow;
}

class IDrawable
{
public:
	virtual void Draw(sf::RenderWindow &window) = 0;
	virtual void Update(float time_passed, sf::RenderWindow &win) = 0;
	virtual void GetPosition(sf::Vector2f& position) = 0;
	virtual float GetTimeToLive() const = 0;
	virtual bool DestroyOnScreenExit() const = 0;
};

#endif
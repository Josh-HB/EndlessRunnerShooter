#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Transform.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

#include "IDrawable.h"

class Shot : public IDrawable
{
 public:
     Shot(sf::Vector2f pos, float rotation, sf::Texture& texture, sf::Time currentTime);
	 virtual void Update(float time_passed, sf::RenderWindow &win);
	 virtual void Draw(sf::RenderWindow &window);
     virtual void GetPosition(sf::Vector2f& position) { position = mPosition; }
	 virtual float GetTimeToLive() const { return 0.4f; }
	 virtual sf::Time GetTimeOfBirth() const { return mTimeOfBirth; }
	 virtual bool DestroyOnScreenExit() const { return true; }

 private:
     sf::CircleShape mShotSprite;
     sf::Vector2f mPosition;
     float mRotation;
	 sf::Clock mCreationTime;
	 sf::Time mTimeOfBirth;
 };
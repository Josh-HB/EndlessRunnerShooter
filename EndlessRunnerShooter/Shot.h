#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/Transform.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

class Shot
 {
 public:
     Shot(sf::Vector2f pos, float rotation);
     void Update(float time_passed);
     void Draw(sf::RenderWindow &window);
 private:
     sf::RectangleShape mShotSprite;
     sf::Vector2f mPosition;
     float mRotation;
 };
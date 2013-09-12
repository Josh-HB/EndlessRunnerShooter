#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/Transform.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

class Shot
 {
 public:
     Shot(sf::Vector2f pos, float rotation, sf::Texture& texture);
     void Update(float time_passed);
     void Draw(sf::RenderWindow &window);

     sf::Vector2f GetPosition()const{return mShotSprite.getPosition();}

 private:
     sf::CircleShape mShotSprite;
     sf::Vector2f mPosition;
     float mRotation;
 };
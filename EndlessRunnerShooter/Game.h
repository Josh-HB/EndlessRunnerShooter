#include <memory>
#include "SFML/Graphics.hpp"
#include "IActions.h"
#include "ShotPtr.h"
#include "IDrawablePtr.h"

class Game : public IActions
{
private:
    std::shared_ptr<sf::RenderWindow> mWindow;
    //Textures
    sf::Texture mBackground;
    sf::Texture mShotTex;
    //Sprites
    sf::Sprite mBgSprite;

	std::vector<IDrawablePtr> mDrawableList;
	std::vector<IDrawablePtr> mNewDrawables;
	sf::Time mPreviousTime;
    
public:
    Game();
    ~Game() {};
    void Run();

    //IActions Interface
    void Shoot(sf::Transformable& performer);
};
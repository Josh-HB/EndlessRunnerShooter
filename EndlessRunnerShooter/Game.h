#include <memory>
#include "SFML/Graphics.hpp"
#include "IActions.h"
#include "ShotPtr.h"

class Game : public IActions
{
private:
    std::shared_ptr<sf::RenderWindow> mWindow;
    //Textures
    sf::Texture mBackground;
    sf::Texture mShotTex;
    //Sprites
    sf::Sprite mBgSprite;
    VectorPtr_ShotPtr mShotList;
    
public:
    Game();
    ~Game() {};
    void Run();

    //IActions Interface
    void shoot(sf::Transformable& performer);
};
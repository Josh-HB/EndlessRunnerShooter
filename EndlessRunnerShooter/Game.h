#include <memory>
#include "SFML/Graphics.hpp"
#include "Hero.h"

class Game
{
private:
    std::shared_ptr<sf::RenderWindow> mWindow;
    sf::Texture mBackground;
    sf::Sprite mBgSprite;
public:
    Game();
    ~Game() {};
    void Run();
};
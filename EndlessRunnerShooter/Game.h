#include <memory>
#include "SFML/Graphics.hpp"
#include "Hero.h"

class Game
{
private:
    std::shared_ptr<sf::RenderWindow> mWindow;
public:
    Game();
    ~Game() {};
    void Run();
};
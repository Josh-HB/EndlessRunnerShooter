#include <memory>
#include "SFML/Graphics.hpp"
#include "Hero.h"
#include "IActions.h"

class Game : public IActions
{
private:
    std::shared_ptr<sf::RenderWindow> mWindow;
    sf::Texture mBackground;
	sf::Texture mShotTex;
    sf::Sprite mBgSprite;
	std::shared_ptr<std::vector<Shot> > mShotList;
public:
    Game();
    ~Game() {};
    void Run();

	//IActions Interface
	void shoot(sf::Transformable& performer);
};
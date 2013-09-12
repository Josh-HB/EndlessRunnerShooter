namespace sf{
	class Transformable;
}

class IActions {
public:
	virtual void shoot(sf::Transformable& performer) = 0;
};
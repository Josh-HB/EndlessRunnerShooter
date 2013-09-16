namespace sf {
    class Transformable;
}

class IActions
{
public:
    virtual void Shoot(sf::Transformable& performer) = 0;
};
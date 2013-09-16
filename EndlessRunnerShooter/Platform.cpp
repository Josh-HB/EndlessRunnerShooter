#include "Platform.h"

Platform::Platform(int id, sf::Vector2f pos, float width, float height, IActions& actions) : 
    StationaryEntity(id, pos, width/2.f, 1.f),
    mWidth(width),
    mHeight(height),
    mActions(actions)
{
    //put the start point at the top left corner and end point at the top right corner
    mStartPoint = mPosition;
    mEndPoint = mStartPoint;
    mEndPoint.x += mWidth;

    mShape = sf::RectangleShape(sf::Vector2f(mWidth, mHeight));
    mShape.setPosition(mPosition);
    mShape.setFillColor(sf::Color::Red);
    mShape.setOutlineColor(sf::Color::Yellow);
    mShape.setOutlineThickness(5.f);
}

void Platform::Update(float time_passed, sf::RenderWindow &win)
{
    //intentionally left blank for now
}
    
void Platform::Draw(sf::RenderWindow &window)
{
    window.draw(mShape);
}
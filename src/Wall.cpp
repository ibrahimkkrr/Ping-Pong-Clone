#include "Wall.h"


Wall::Wall()
{
	top_wall.setSize(sf::Vector2f(512.0f, 10.0f));
	top_wall.setPosition(0.0f, 0.9f);

	bottom_wall.setSize(sf::Vector2f(512.0f, 10.0f));
	bottom_wall.setPosition(0.0f, 500.0f);

	right_wall.setSize(sf::Vector2f(10.0f, 512.0f));
	right_wall.setPosition(sf::Vector2f(510.0f, 0));

	left_wall.setSize(sf::Vector2f(2.5f,512.0f));
	left_wall.setPosition(sf::Vector2f(0.0f, 0.0f));

}

sf::RectangleShape& Wall::getTopShape()
{
	return top_wall;
}

sf::RectangleShape& Wall::getBottomShape()
{
	return bottom_wall;
}

sf::RectangleShape& Wall::getLeftShape()
{
	return left_wall;
}

sf::RectangleShape& Wall::getRightShape()
{
	return right_wall;
}

void Wall::drawWalls(sf::RenderWindow& window)
{
	window.draw(top_wall);
	window.draw(bottom_wall);
	window.draw(right_wall);
	window.draw(left_wall);
}
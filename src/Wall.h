#pragma once
#include "SFML/Graphics.hpp"
class Wall
{
private:
	sf::RectangleShape top_wall;
	sf::RectangleShape right_wall;
	sf::RectangleShape left_wall;
	sf::RectangleShape bottom_wall;
	
public:
	Wall();
	void drawWalls(sf::RenderWindow&);

	sf::RectangleShape& getTopShape();
	sf::RectangleShape& getBottomShape();
	sf::RectangleShape& getRightShape();
	sf::RectangleShape& getLeftShape();


};


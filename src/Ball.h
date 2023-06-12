#pragma once
#include "SFML/Graphics.hpp"
#include <random>
#include <cmath>

class Ball
{
private:
	sf::Vector2f initial_velocity;
	sf::Vector2f velocity;
	sf::CircleShape ball;
	


public:
	Ball();
	void randomSpawnSpeed();
	void randomSapwnLocation();
	sf::Vector2f getInitialVelocity() const;
	sf::Vector2f getVelocity() const;
	sf::CircleShape getShape() const;
	void setVelocity(float,float);
	void setVelocityX(float);
	void setVelocityY(float);
	void incressVelocityX();
	void incressVelocityY();
	void move();
	void drawBall(sf::RenderWindow&);



	

};


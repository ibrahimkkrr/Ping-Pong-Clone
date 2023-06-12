#pragma once
#include "Ball.h"
#include "Wall.h"
#include "Player.h"
#include <iostream>
#include <tuple>

class Collision
{
private:
	float clampX(float value, float min, float  max);
	float clampY(float value, float min, float  max);
	typedef std::tuple<bool, sf::Vector2f> collision;


		collision CheckCollision(sf::RectangleShape*, sf::CircleShape*);
		bool top_bottom_checker(sf::RectangleShape& paddle, sf::CircleShape& ball);


public:
	void moveBall(sf::CircleShape& ball_shape, sf::Vector2f new_velocity);
		void DoCollisionsLeft(Ball& ball, Player& player);
		void DoCollisionsRight(Ball& ball, Player& player);
		void DoCollisionsWalls(Ball& ball, Wall& wall);
		void DoCollisionGoals(Ball& ball, Wall& wall,Player&,Player&);




};


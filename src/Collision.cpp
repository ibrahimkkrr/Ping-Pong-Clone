#include "Collision.h"




Collision::collision Collision ::CheckCollision(sf::RectangleShape* player, sf::CircleShape* ball)
{

	sf::Vector2f ballCenter(ball->getPosition().x + ball->getRadius(), ball->getPosition().y + ball->getRadius());
	sf::Vector2f player_half_aabb(player->getSize().x / 2, player->getSize().y / 2);
	sf::Vector2f playerCenter(player->getPosition().x + player_half_aabb.x, player->getPosition().y + player_half_aabb.y);

	sf::Vector2f difference = ballCenter - playerCenter;
	sf::Vector2f clamped(clampX(difference.x, -player_half_aabb.x, player_half_aabb.x), clampY(difference.y, -player_half_aabb.y, player_half_aabb.y));

	sf::Vector2f closest = playerCenter + clamped;

	difference = closest - ballCenter;

	float distence = std::sqrt((difference.x * difference.x) + (difference.y * difference.y));

	if (ball->getRadius() > distence)
	{

		return std::make_tuple(true, difference);
	}
	else
	{
		return std::make_tuple(false, sf::Vector2f(0.0f, 0.0f));

	}

}


void Collision::DoCollisionsLeft(Ball& ball,Player& player)
{

	collision collision_checker = CheckCollision(&player.getShape(), &ball.getShape());


	if (std::get<0>(collision_checker) && ball.getVelocity().x == -std::abs(ball.getVelocity().x))
	{
		if (ball.getVelocity().x < 0 )
		{

			
			
			ball.setVelocityX((ball.getVelocity().x * -1));
			ball.incressVelocityX();
		}
	
		
	}

	
	

}

void Collision::DoCollisionsRight(Ball& ball,Player& player)
{

	collision collision_checker = CheckCollision(&player.getShape(), &ball.getShape());


	if (std::get<0>(collision_checker) && ball.getVelocity().x == std::abs(ball.getVelocity().x))
	{
		if (ball.getVelocity().x > 0)
		{

			ball.setVelocityX((ball.getVelocity().x * -1));
			ball.incressVelocityX();

		}


	}




}

bool Collision::top_bottom_checker(sf::RectangleShape & paddle, sf::CircleShape & ball)
{
	sf::FloatRect paddleBounds = paddle.getGlobalBounds();
	sf::FloatRect ballBounds = ball.getGlobalBounds();

	if (paddleBounds.intersects(ballBounds))
	{
		float ballCenterY = ball.getPosition().y + ball.getRadius();
		float paddleCenterY = paddle.getPosition().y + paddle.getSize().y / 2.f;

		if (ballCenterY < paddleCenterY)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}



void Collision::DoCollisionsWalls(Ball& ball,Wall& wall)
{

	collision collision_checker_top = CheckCollision(&wall.getTopShape(), &ball.getShape());
	collision collision_checker_bottom = CheckCollision(&wall.getBottomShape(), &ball.getShape());


	if (std::get<0>(collision_checker_bottom) || std::get<0>(collision_checker_top))
	{
		
		 if (ball.getVelocity().y + 1 <= wall.getBottomShape().getPosition().y)
		{
			ball.setVelocityY((ball.getVelocity().y * -1));
			ball.incressVelocityY();

		}else if (ball.getVelocity().y + 1 >= wall.getTopShape().getPosition().y)
		{
			ball.setVelocityY((ball.getVelocity().y * -1));
			ball.incressVelocityY();
		}

	}
	



}


void Collision::DoCollisionGoals(Ball& ball, Wall& wall,Player& player1, Player& player2)
{

	collision collision_checker_right = CheckCollision(&wall.getRightShape(), &ball.getShape());
	collision collision_checker_left = CheckCollision(&wall.getLeftShape(), &ball.getShape());

	if (std::get<0>(collision_checker_right))
	{
		ball.randomSpawnSpeed();
		ball.randomSapwnLocation();
		player1.playerOneScored();
	}
	else if (std::get<0>(collision_checker_left))
	{ 
		ball.randomSpawnSpeed();
		ball.randomSapwnLocation();
		player2.playerTwoScored();
	}

}

void Collision::moveBall(sf::CircleShape& ball_shape, sf::Vector2f new_velocity)
{

	ball_shape.move(new_velocity);
}


float Collision::clampX(float value, float min, float  max)
{
	return std::max(min, std::min(max, value));
}

float Collision::clampY(float value, float min, float  max)
{
	return std::max(min, std::min(max, value));
}

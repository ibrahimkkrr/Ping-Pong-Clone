#include "Ball.h"

Ball::Ball()
{
	initial_velocity.x = -1.0f;
	initial_velocity.y = 0.5;
	randomSpawnSpeed();
	ball.setRadius(7.5f);
	ball.setPointCount(36);
	randomSapwnLocation();
	
}


void Ball::move()
{

	ball.move(velocity);
}



void Ball::drawBall(sf::RenderWindow& window)
{

	window.draw(ball);
}

sf::CircleShape Ball::getShape() const
{
	return ball;
}


sf::Vector2f Ball::getVelocity() const
{
	return velocity;
}

sf::Vector2f Ball::getInitialVelocity() const
{
	return initial_velocity;
}


void Ball ::incressVelocityX()
{
	if (velocity.x > 0)
	
		if (velocity.x + 1 < 10)
           velocity.x++;
	else
	
	  if (velocity.x - 1 > 10)
	    	velocity.x--;
}

void Ball::incressVelocityY()
{
	if (velocity.y> 0)

		if(velocity.y  < 10)
		     velocity.y += 1.0f;
	else
       if(velocity.y  > -10)
		velocity.y -= 1.0f;
}


void Ball::setVelocity(float x, float y)
{
	velocity.x = x;
	velocity.y = y;
}

void Ball::setVelocityX(float new_velocity)
{
	this->velocity.x = new_velocity;
}

void Ball::setVelocityY(float new_velocity)
{
	this->velocity.y = new_velocity;
}

void Ball::randomSpawnSpeed()
{

	std::random_device rdX;
	std::mt19937 genX(rdX());
	std::random_device rdY;
	std::mt19937 genY(rdY());
	std::uniform_real_distribution<> disY(-1, 1);
	float randomX = 0;
	float randomY = disY(genY);
	   std::uniform_real_distribution<> disX(-1.9f, 1.9f);
	     randomX = disX(genX);
		 if ( randomX > 0.0f)
		 {
			 velocity.x = 5.0f;
		 }
		 else if (randomX < 0)
		 {
			 velocity.x = -5.0f;
		 }

		 if (randomY > 0.0f)
		 {
			 velocity.y = 2.5f;
		 }
		 else if (randomY < 0.0f)
		 {
			 velocity.y = -2.5f;
		 }

	



}


void Ball::randomSapwnLocation()
{
	std::random_device rdX;
	std::mt19937 genX(rdX());
	std::random_device rdY;
	std::mt19937 genY(rdY());
	std::uniform_real_distribution<> disX(245.0f, 260.0f);
	std::uniform_real_distribution<> disY(10.0f, 450.0f);
	float randomX = disX(genX);
	float randomY = disY(genY);


	ball.setPosition(randomX, randomY);
}
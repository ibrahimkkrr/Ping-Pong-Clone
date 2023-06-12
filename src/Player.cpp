#include "Player.h"

int Player::players_number = 0;


void Player::check_spawn_postion()
{

	if (players_number == 1)
	{
	
		this->player_shape.setPosition(sf::Vector2f(10.0f, 256.0f));
	    player_number = 1;
	
	}
	else
	{
		this->player_shape.setPosition(sf::Vector2f(480.0f, 256.0f));
	    player_number = 2;

	}
}

Player::Player()
{
	this->player_shape.setSize(sf::Vector2f(10, 50));


	players_number++;
	check_spawn_postion();

}

sf::RectangleShape& Player::getShape()
{
	return player_shape;
}


void Player::drawPlayer(sf::RenderWindow& window)
{

	
	window.draw(player_shape);
}

void Player::playerOneScored()
{
	player1_score++;
}
void Player::playerTwoScored()
{
	player2_score++;
}

int Player::getPlayerOneScore()
{
	return  player1_score;
	
}

int Player::getPlayerTwoScore()
{
	return  player2_score;

}

void Player::move()
{

	if (this->player_number == 1)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) && player_shape.getPosition().y > 5.0f)
		{
			player_shape.move(0.0f, -10.0f);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player_shape.getPosition().y < 460.0f)
		{
			player_shape.move(0.0f, 10.0f);
		}
	}
	else
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && player_shape.getPosition().y > 5.0f)
		{
			player_shape.move(0.0f, -10.0f);

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player_shape.getPosition().y < 460.0f)
		{
			player_shape.move(0.0f, 10.0f);
		}
	}

}

int Player::getPlayerNumber()
{
	return player_number;
}

void Player::restPosition()
{
	if (this->players_number == 1)
	{

		this->player_shape.setPosition(sf::Vector2f(10.0f, 256.0f));

	}
	else if (this->player_number == 2)
	{
		this->player_shape.setPosition(sf::Vector2f(480.0f, 256.0f));

	}
}

void Player::restStates()
{
	player1_state = false;
	player2_state = false;
}

void Player::checkWinner()
{
	if (player1_score == 10)
	{
		player1_state = true;
	}
	else if (player2_score == 10)
	{
		player2_state = true;
	}
}



bool Player::getPlayerOneState()
{

	return player1_state;
}

bool Player::getPlayerTwoState()
{

	return player2_state;
}

void Player::restScore()
{
	player1_score = 0;
	player2_score = 0;
}
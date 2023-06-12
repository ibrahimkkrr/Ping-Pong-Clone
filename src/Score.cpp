#include "Score.h"


Score::Score()
{
	if (!font.loadFromFile("PingPong.otf"))
	{
		std::cout << "Font file didnt open..." << std::endl;
	}

	text.setFont(font);
	text.setPosition(sf::Vector2f(220.0f, 30.0f));
	text.setCharacterSize(50);
}


void Score::checkWinner(Ball& ball,Player& player1,Player& player2)
{



	if (player1.getPlayerOneScore() == 2)
	{
		player1Won = true;

		
	}
	else if (player2.getPlayerTwoScore() == 2)
	{
		    player2Won = true;

			player1.restScore();
			player1.restPosition();
			player2.restPosition();
			ball.randomSapwnLocation();
			ball.randomSpawnSpeed();
	}
}


void Score::draw(sf::RenderWindow& window,Player& player1, Player& player2)
{
	

	
		std::string score;
		score = std::to_string(player1.getPlayerOneScore()) + " : " + std::to_string(player2.getPlayerTwoScore());
		text.setString(score);
		window.draw(text);
	

	
}
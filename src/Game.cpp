#include "Game.h"

sf::RenderWindow Game::window(sf::VideoMode(512, 512), "k", sf::Style::Close | sf::Style::Titlebar);

Game::Game()
{
	if (!font.loadFromFile("PingPong.otf"))
	{
		std::cout << "Font file didnt open..." << std::endl;
	}

	text.setFont(font);
	text.setPosition(sf::Vector2f(220.0f, 30.0f));
	text.setCharacterSize(50);
	
}


void Game::startGame()
{
	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		eventRecorder();
		  input();
		  update();
 	      Render();
	}

}

void Game::eventRecorder()
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			window.close();

		default:
			break;
		}

	}
}

void Game::input()
{
	player1.move();
	player2.move();


}

void Game::update()
{
	ball.move();
	collision.DoCollisionsLeft(ball, player1);
	collision.DoCollisionsRight(ball, player2);
	collision.DoCollisionsWalls(ball, walls);
	collision.DoCollisionGoals(ball, walls, player1,player2);
    
	player1.checkWinner();
	player2.checkWinner();

	

}

void Game::Render()
{
	if ( winScreen == RenderWinScreen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			rest();

		}
	}
	else
	{
		window.clear();
		player1.drawPlayer(window);
		player2.drawPlayer(window);
		ball.drawBall(window);
		score.draw(window, player1,player2);
		window.display();
		winScreen = true;
	}

}

bool Game::RenderWinScreen()
{
	std::string player1Win = " Player1 Has Won ";
	std::string player2Win = " Player2 Has Won ";
	if (player1.getPlayerOneState())
	{
		text.setPosition(sf::Vector2f(100.0f, 256.0f));
		text.setString(player1Win);
		window.clear();
		window.draw(text);
		window.display();
		return true;

	}
	else if (player2.getPlayerTwoState())
	{

		text.setPosition(sf::Vector2f(100.0f, 256.0f));

		text.setString(player2Win);
		window.clear();
		window.draw(text);
		window.display();
		return true;
	}
	else
	{
		return false;
	}
}


void  Game::rest()
{
	player1.restScore();
	player2.restScore();

	player1.restStates();
	player2.restStates();

	player1.restPosition();
	player2.restPosition();
	ball.randomSapwnLocation();
	ball.randomSpawnSpeed();
}


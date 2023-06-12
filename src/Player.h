#pragma once
#include "SFML/Graphics.hpp"
class Player
{

private:

	int player_number;
	int player1_score = 0;
	int player2_score = 0;

	bool player1_state = false;
	bool player2_state = false;


	sf::RectangleShape top_wall;
	sf::RenderWindow window;
	sf::RectangleShape player_shape;
	static int players_number;
	void check_spawn_postion();

public:


	Player();
	int getPlayerNumber();
	int getPlayerOneScore();
	int getPlayerTwoScore();
	sf::RectangleShape& getShape();

	bool getPlayerOneState();
	bool getPlayerTwoState();


	void drawPlayer(sf::RenderWindow&);
	void move();
	void check_ball_collison(sf::CircleShape& ball);
	void checkWinner();
	void restScore();
	void restPosition();
	void restStates();
	void playerOneScored();
	void playerTwoScored();








};


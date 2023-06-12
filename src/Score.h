#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Ball.h"

class Score
{
private:
	sf::Font font;
	sf::Text text;
	bool player1Won = false;
	bool player2Won  = false;


public:
	Score();
	void checkWinner(Ball&,Player&,Player&);
	bool drawWinScreen(sf::RenderWindow& window, bool player1, bool player2);
	void draw(sf::RenderWindow&,Player&, Player&);

};


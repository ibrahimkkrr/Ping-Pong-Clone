#pragma once
#include <tuple>
#include "SFML/Graphics.hpp"
#include "Ball.h"
#include "Player.h"
#include "Collision.h"
#include "Score.h"
#include <memory>
#include <iostream>
#include <ctime>



class Game
{
private:
    Ball ball;
    Player player1;
    Player player2;
    Wall walls;
    Score score;
    Collision collision;


    sf::Event evnt;
    sf::Font font;
    sf::Text text;
    static sf::RenderWindow window;


    bool winScreen = true;

    void rest();
    bool RenderWinScreen();
    void input();
    void update();
    void eventRecorder();
    void Render();
public:

    Game();
    void startGame();

};


#pragma once
#include "gameState.h"
#include "SFML/Graphics.hpp"

const int windowWidth = 100; 
const int windowHeight = 100;

class Game {
private:
	GameState* state;
	sf::RenderWindow* window;
public:
	Game();
	void mainLoop();
};
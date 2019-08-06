#pragma once
#include "gameState.h"
#include "SFML/Graphics.hpp"

const int windowWidth = 320; 
const int windowHeight = 640;

class Game {
private:
	GameState* state;
	sf::RenderWindow* window;
public:
	Game();
	void setup();
	void mainLoop();

};
#include "game.h"
#include "gameState.h"
#include "SFML/Graphics.hpp"

Game::Game() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Tetris",
									sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);

	state = new StateMainMenu();
}

void Game::mainLoop() {
	while(window->isOpen()) {
		state->input();
		state->logic();
		state->render();
	}
}
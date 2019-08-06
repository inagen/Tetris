#include "game.h"
#include "gameState.h"
#include "SFML/Graphics.hpp"
//#include "Time.hpp"

Game::Game() {
	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), "Tetris",
									sf::Style::Titlebar | sf::Style::Close);
	window->setFramerateLimit(60);
	state = new StateMainMenu(window);
}

void Game::mainLoop() {
	while(window->isOpen()) {
		state->input();
		if(state->isStateChanged) {
			state = new StatePlay(window);
			continue;
		}
		state->logic();
		state->render();
	}
} 
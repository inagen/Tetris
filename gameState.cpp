#include "gameState.h"
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <time.h>

StateMainMenu::StateMainMenu(sf::RenderWindow* rw) {
	window = rw;
}

void StateMainMenu::input() {
	sf::Event event;
	while(window->pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			window->close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window->close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			isStateChanged = true;
			return;
		}
	}
}

void StateMainMenu::logic() {

}

void StateMainMenu::render() {
	window->clear();
	window->display();
}


/////////////////////////////////

StatePlay::StatePlay(sf::RenderWindow* rw) {
	window = rw;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 20; j++) {
			field[j][i] = '-';
		}
	}
	srand(time(NULL));
	currentTetromino = tetrominos[rand() % 7];
	tetrominoPosX = 4;
	tetrominoPosY = 0; 

	bricks[0].loadFromFile("contents/blue.png", sf::IntRect(0, 0, 32, 32));
	bricks[1].loadFromFile("contents/green.png", sf::IntRect(0, 0, 32, 32));
	bricks[2].loadFromFile("contents/lightBlue.png", sf::IntRect(0, 0, 32, 32));
	bricks[3].loadFromFile("contents/orange.png", sf::IntRect(0, 0, 32, 32));
	bricks[4].loadFromFile("contents/purple.png", sf::IntRect(0, 0, 32, 32));
	bricks[5].loadFromFile("contents/red.png", sf::IntRect(0, 0, 32, 32));
	bricks[6].loadFromFile("contents/yellow.png", sf::IntRect(0, 0, 32, 32));
}

void StatePlay::input() {
	sf::Event event;
	while(window->pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			window->close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			window->close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			LeftMoveRequested = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			RightMoveRequested = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			RotationRequested = true;
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			Pause = !Pause;
		}
	}
}

void StatePlay::logic() {
		/*if(Pause)
			return;*/
		float ElapsedTime = Clock.getElapsedTime().asSeconds();
		
		if(LeftMoveRequested && leftMoveIsReal()) {
			tetrominoPosX--;
			LeftMoveRequested = false;
		} else if(RightMoveRequested && rightMoveIsReal()) {
			tetrominoPosX++;
			RightMoveRequested = false;
		} else if(RotationRequested && rotationIsReal()){
			rotate();
			RotationRequested = false;
		}

		if(ElapsedTime >= 0.5) {
			tetrominoPosY++;
			Clock.restart();
		}

		if(ElapsedTime >= 0.5) {
			Clock.restart();
		}
}
void StatePlay::drawBricks(char c, int x, int y) {
	sf::Sprite sprite;
	if(c == 'I')
		sprite.setTexture(bricks[0]);
	if(c == 'T')
		sprite.setTexture(bricks[1]);
	if(c == 'J')
		sprite.setTexture(bricks[2]);
	if(c == 'L')
		sprite.setTexture(bricks[3]);
	if(c == 'O')
		sprite.setTexture(bricks[4]);
	if(c == 'Z')
		sprite.setTexture(bricks[5]);
	if(c == 'S')
		sprite.setTexture(bricks[6]);

	sprite.setPosition(x, y);
	window->draw(sprite);
}
void StatePlay::render() {

	window->clear();

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 20; j++) {
			char c = field[i][j];
			if(c == '-') {
				sf::RectangleShape shape;
				shape.setSize(sf::Vector2f(32, 32));
				shape.setFillColor(sf::Color::Black);
				shape.setPosition(i*32, j*32);
				window->draw(shape);
			} else {
				drawBricks(c, i*32, j*32);
			} 
			
		}
	}

	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++) {
			char c = currentTetromino[i][j];
			if(c != '-') {
				int posX = (i+tetrominoPosX)*32;
				int posY = (j+tetrominoPosY)*32;
				drawBricks(c, posX, posY);
			}
		}
	}

	window->display();
}

void StatePlay::rotate() {
	Array2d4 newTetromino;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			newTetromino[i][j] = currentTetromino[4 - j - 1][i];

	currentTetromino = newTetromino;
}

bool StatePlay::leftMoveIsReal() {
	return true;
}

bool StatePlay::rightMoveIsReal() {
	return true;
}

bool StatePlay::downMoveIsReal() {
	return true;
}

bool StatePlay::rotationIsReal() {
	return true;
}


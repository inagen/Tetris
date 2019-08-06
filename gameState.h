#pragma once
#include "SFML/Graphics.hpp"
#include <array>
#include "tetromino.h"

using array2d10_20 = std::array< std::array<char, 10>, 20>;

class Game;

class GameState {
public:
	bool isStateChanged = false;
public:
	virtual void input() = 0;
	virtual void logic() = 0;
	virtual void render() = 0;
};

class StateMainMenu : public GameState {

private:
	sf::Texture mainMenuSprite;
	sf::RenderWindow* window;
public:
	StateMainMenu(sf::RenderWindow*);
	void input() 	override;
	void logic() 	override;
	void render()	override;
};

class StatePlay : public GameState {
private:
	array2d10_20 field;
	Array2d4 currentTetromino;
	int tetrominoPosX;
	int tetrominoPosY;

	sf::Texture backgroundSprite;
	std::array<sf::Texture, 7> bricks;
	sf::RenderWindow* window;
	sf::Clock Clock;

	bool Pause = false;
	bool LeftMoveRequested = false;
	bool RightMoveRequested = false;
	bool RotationRequested = false;
private:
	void drawBricks(char, int, int);
	bool leftMoveIsReal();
	bool rightMoveIsReal();
	bool downMoveIsReal();
	bool rotationIsReal();
	void rotate();
	void getNewTetromino();

public:
	StatePlay(sf::RenderWindow*);
	void input()	override;
	void logic()	override;
	void render()	override;
};

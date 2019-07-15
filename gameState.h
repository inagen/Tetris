#pragma once

class Game;

class GameState {
public:
	virtual void input();
	virtual void logic();
	virtual void render();
};

class StateMainMenu : public GameState {
public:
	StateMainMenu();
	void input();
	void logic();
	void render();
};

class StatePlay : public GameState {
public:
	void input();
	void logic();
	void render();
};

class StateGameOver : public GameState {
public:
	void input();
	void logic();
	void render();
};
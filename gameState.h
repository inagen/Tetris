#pragma once

class Game;

class GameState {
public:
	virtual void input() = 0;
	virtual void logic() = 0;
	virtual void render() = 0;
};

class StateMainMenu : public GameState {
public:
	StateMainMenu();
	void input() 	override;
	void logic() 	override;
	void render()	override;
};

class StatePlay : public GameState {
public:
	void input()	override;
	void logic()	override;
	void render()	override;
};

class StateGameOver : public GameState {
public:
	void input()	override;
	void logic()	override;
	void render()	override;
};
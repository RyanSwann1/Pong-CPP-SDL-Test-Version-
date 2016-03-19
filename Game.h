#pragma once
#ifndef GAME_H
#define GAME_H

#include <SDL.h>
class HumanPlayer;
class Ball;
class Player;
class Game
{
public:
	Game();
	~Game();

	void update(Player& player1, Player& player2, Ball& ball);
	void endGame() { m_gameOver = true; }
	void inputManager(Player& player1, Player& player2);
	void collisionManagement(Player& player1, Player& player2, Ball& ball);
	void ballManagement(Ball& ball);
	bool playAgainstAI();

	bool gameOver() const { return m_gameOver; }

private:
	void checkBallBounds(Ball& ball);
	bool m_gameOver;

};
#endif // !GAME_H

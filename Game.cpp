#include "Game.h"
#include "Player.h"
#include "Ball.h"
#include "HumanPlayer.h"

#include <iostream>

Game::Game()
{
	m_gameOver = false;
}

Game::~Game()
{
}

void Game::update(Player & player1, Player & player2, Ball & ball)
{
	ballManagement(ball);
	collisionManagement(player1, player2, ball);
}

void Game::inputManager(Player& player1, Player& player2)
{
	const Uint8 *keyState = SDL_GetKeyboardState(nullptr);

	//Player1 movement
	if (keyState[SDL_SCANCODE_W]) {
		player1.movement(MoveDirection::UP);
	}
	if (keyState[SDL_SCANCODE_S]) {
		player1.movement(MoveDirection::DOWN);
	}
	
	//Player2 movement
	if (keyState[SDL_SCANCODE_UP]) {
		player2.movement(MoveDirection::UP);
	}
	if (keyState[SDL_SCANCODE_DOWN]) {
		player2.movement(MoveDirection::DOWN);
	}
}

void Game::collisionManagement(Player & player1, Player & player2, Ball & ball)
{
	//Player1/Ball collision
	if (ball.collision(player1))
	{
		ball.changeDir(ball.getHitPos(player1));
		//MoveDirection dir = ball.getHitPos(player1);
		//ball.changeDir(dir);
		//int yPos = ball.getHitFactor(player1);
		//std::cout << yPos;
		////Calculate hit factor
		//ball.changeDir(MoveDirection::RIGHT);
	}

	//Player2/ball Collision
	if (ball.collision(player2))
	{
		ball.changeDir(ball.getHitPos(player2));
	}
}

void Game::ballManagement(Ball & ball)
{
	ball.movement(ball.GetMoveDir());
	checkBallBounds(ball);

}

bool Game::playAgainstAI()
{
	bool playAI = false;
	bool decided = false;
	int userInput = 0;
	while (!decided)
	{
		std::cout << "Play vs Human: '1' or AI: '2'" << "\n";
		std::cin >> userInput;
		if (userInput == 1 || userInput == 2) {
			decided = true;
		}
	}
	if (userInput == 1) {
		playAI = false;
	}
	if (userInput == 2) {
		playAI = true;
	}

	return playAI;
}

void Game::checkBallBounds(Ball & ball)
{
	//If ball has exceeded minimum x position
	if (ball.getPos().x <= Ball::MIN_X_POS)
	{
		//Change direction
		if (ball.GetMoveDir() == MoveDirection::LEFTDOWN) {
			ball.changeDir(MoveDirection::RIGHTDOWN);
		}
		else if (ball.GetMoveDir() == MoveDirection::LEFTUP)
		{
			ball.changeDir(MoveDirection::RIGHTUP);
		}
		else {
			ball.changeDir(MoveDirection::RIGHT);
		}
	}
	//If ball has exceeded maximum x position
	if (ball.getPos().x >= Ball::MAX_X_POS)
	{
		//Change direction
		if (ball.GetMoveDir() == MoveDirection::RIGHTDOWN) {
			ball.changeDir(MoveDirection::LEFTDOWN);
		}
		else if (ball.GetMoveDir() == MoveDirection::RIGHTUP) {
			ball.changeDir(MoveDirection::LEFTUP);
		}
		else
		{
			ball.changeDir(MoveDirection::LEFT);
		}
	}

	//If ball has exceeded minimum y pos
	if (ball.getPos().y <= Ball::MIN_Y_POS)
	{
		//Change direction
		if (ball.GetMoveDir() == MoveDirection::LEFTUP) {
			ball.changeDir(MoveDirection::LEFTDOWN);
		}
		else
		{
			ball.changeDir(MoveDirection::RIGHTDOWN);
		}
	}

	if (ball.getPos().y >= Ball::MAX_Y_POS)
	{
		//Change Direction
		if (ball.GetMoveDir() == MoveDirection::RIGHTDOWN) {
			ball.changeDir(MoveDirection::RIGHTUP);
		}
		else
		{
			ball.changeDir(MoveDirection::LEFTUP);
		}
	}
}


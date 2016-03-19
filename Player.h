#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "MoveDirection.h"
#include <SDL.h>
class Ball;
class Player
{
public:
	Player();
	~Player();

	virtual void movement(const MoveDirection& dir) = 0;//Controls movement
	virtual SDL_Rect getPos() const = 0; //Gets player position
	SDL_Rect getBallPos(Ball& ball) const { return ball.getPos(); }

	//Player1 starting pos
	static constexpr int PLAYER1_START_X_POS = 75;
	static constexpr int PLAYER1_START_Y_POS = 220;
	//Player2 starting pos
	static constexpr int PLAYER2_START_X_POS = 700;
	static constexpr int PLAYER2_START_Y_POS = 220;



private:

};
#endif // !PLAYER_H

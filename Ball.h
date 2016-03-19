#pragma once

#ifndef BALL_H
#define BALL_H

#include "MoveDirection.h"
#include <SDL.h>
class Player;
class Ball
{
public:
	Ball();
	~Ball();

	void movement(const MoveDirection dir);
	bool collision(Player& player) const;
	void changeDir(const MoveDirection& dir);
	//void movementBounds();

	//Getters
	MoveDirection GetMoveDir() const { return m_dir; }
	SDL_Rect getPos() const { return m_pos; }
	MoveDirection getHitPos(const Player& player) const;

	//Movement bounds
	static constexpr int MIN_X_POS = 0;
	static constexpr int MIN_Y_POS = 0;
	static constexpr int MAX_X_POS = 750;
	static constexpr int MAX_Y_POS = 450;

private:
	SDL_Rect m_pos; //Position of the ball
	MoveDirection m_dir; //Move direction of ball
	//Starting position of ball
	static constexpr int START_X_POS = 300;
	static constexpr int START_Y_POS = 250;
	static constexpr int MOVEMENT_SPEED = 3;
	static constexpr int SIZE_WIDTH = 20;
	static constexpr int SIZE_HEIGHT = 20;


};
#endif // !BALL_H


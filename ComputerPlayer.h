#pragma once
#include "Player.h"
class Ball;
class ComputerPlayer :
	public Player
{
public:
	ComputerPlayer(const int startXPos, const int startYPos);
	~ComputerPlayer();

	void movement(const MoveDirection& dir) override;
	SDL_Rect getPos() const override;

private:
	SDL_Rect m_pos; //Position of player
	Ball ball;

	static constexpr int MOVEMENT_SPEED = 8;
	static constexpr int SIZE_WIDTH = 25;
	static constexpr int SIZE_HEIGHT = 75;
};


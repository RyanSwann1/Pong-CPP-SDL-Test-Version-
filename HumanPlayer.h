#pragma once
#include "Player.h"
class HumanPlayer :
	public Player
{
public:
	HumanPlayer(const int startXPos, const int startYPos);
	~HumanPlayer();

	void movement(const MoveDirection& dir) override; 
	SDL_Rect getPos() const override { return m_pos; }

private:
	SDL_Rect m_pos;

	static constexpr int MOVEMENT_SPEED = 8;
	static constexpr int SIZE_WIDTH = 25;
	static constexpr int SIZE_HEIGHT = 75;
};


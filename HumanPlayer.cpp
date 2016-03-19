#include "HumanPlayer.h"



HumanPlayer::HumanPlayer(const int startXPos, const int startYPos)
{
	m_pos.x = startXPos;
	m_pos.y = startYPos;
	m_pos.w = SIZE_WIDTH;
	m_pos.h = SIZE_HEIGHT;
}

HumanPlayer::~HumanPlayer()
{
}

void HumanPlayer::movement(const MoveDirection & dir)
{
	//Min/Max positions player can move to
	static constexpr int MIN_Y_POS = 5;
	static constexpr int MAX_Y_POS = 425;
	//Determines movement 
	switch (dir)
	{
		case MoveDirection::UP: 
		{
			//If position change is allowed
			if (m_pos.y > MIN_Y_POS) 
			{
				m_pos.y -= MOVEMENT_SPEED;
				break;
			}
		}
		case MoveDirection::DOWN:
		{
			//If position change is allowed
			if (m_pos.y < MAX_Y_POS)
			{
				m_pos.y += MOVEMENT_SPEED; 
				break;
			}
		}
	}
}

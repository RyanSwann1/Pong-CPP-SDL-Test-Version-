#include "ComputerPlayer.h"
#include "Ball.h"


ComputerPlayer::ComputerPlayer(const int startXPos, const int startYPos)
{
	//Initialize starting position and size of player
	m_pos.x = startXPos;
	m_pos.y = startYPos;
	m_pos.w = SIZE_WIDTH;
	m_pos.h = SIZE_HEIGHT;
}


ComputerPlayer::~ComputerPlayer()
{
}

void ComputerPlayer::movement(const MoveDirection & dir)
{
	
}

SDL_Rect ComputerPlayer::getPos() const
{
	return SDL_Rect();
}

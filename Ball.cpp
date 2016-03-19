#include "Ball.h"
#include "Player.h"

#include <iostream>

Ball::Ball()
{
	//Initialize ball
	m_pos.x = START_X_POS;
	m_pos.y = START_Y_POS;
	m_pos.w = SIZE_WIDTH;
	m_pos.h = SIZE_HEIGHT;
	m_dir = MoveDirection::LEFT;
}


Ball::~Ball()
{
}

void Ball::movement(const MoveDirection dir)
{
	//Determines movement
	switch (dir)
	{
		case MoveDirection::RIGHT: m_pos.x += MOVEMENT_SPEED; break;
		case MoveDirection::RIGHTUP:
		{
			m_pos.x += MOVEMENT_SPEED;
			m_pos.y -= 2;
			break;
		}
		case MoveDirection::RIGHTDOWN:
		{
			m_pos.x += MOVEMENT_SPEED;
			m_pos.y += 2;
			break;
		}
		case MoveDirection::LEFT: m_pos.x -= MOVEMENT_SPEED; break;
		case MoveDirection::LEFTUP:
		{
			m_pos.x -= MOVEMENT_SPEED;
			m_pos.y -= 2;
			break;
		}
		case MoveDirection::LEFTDOWN:
		{
			m_pos.x -= MOVEMENT_SPEED;
			m_pos.y += 2;
			break;
		}
	}
}

bool Ball::collision(Player & player) const
{
	//Player collision box
	const int playerLeft = player.getPos().x;
	const int playerRight = player.getPos().x + player.getPos().w;
	const int playerTop = player.getPos().y;
	const int playerBot = player.getPos().y + player.getPos().h;

	//Ball collision box
	const int ballLeft = m_pos.x;
	const int ballRight = m_pos.x + m_pos.w;
	const int ballTop = m_pos.y;
	const int ballBot = m_pos.y + m_pos.h;

	//Calculate collision
	if (ballLeft >= playerRight) { //False
		return false;
	}
	if (ballRight <= playerLeft) { //False
		return false;
	}
	if (ballBot <= playerTop) { //False
		return false;
	}
	if (ballTop >= playerBot) { //False. Collision happens
		return false;
	}

	return true;
}
void Ball::changeDir(const MoveDirection & dir)
{
	switch (dir)
	{
	case MoveDirection::RIGHT: m_dir = MoveDirection::RIGHT; break;
	case MoveDirection::RIGHTUP: m_dir = MoveDirection::RIGHTUP; break;
	case MoveDirection::RIGHTDOWN: m_dir = MoveDirection::RIGHTDOWN; break;

	case MoveDirection::LEFT: m_dir = MoveDirection::LEFT; break;
	case MoveDirection::LEFTUP: m_dir = MoveDirection::LEFTUP; break;
	case MoveDirection::LEFTDOWN: m_dir = MoveDirection::LEFTDOWN; break;
	}
}

MoveDirection Ball::getHitPos(const Player& player) const
{
	MoveDirection dir; //Direction of movement

	//If ball is moving left
	if (m_dir == MoveDirection::LEFT || m_dir == MoveDirection::LEFTDOWN || m_dir == MoveDirection::LEFTUP)
	{	
		int hitPos = m_pos.y - player.getPos().y; //Get hit position
		int playerSize = player.getPos().h / 2; 
		int offSet = 20; //Enables to split up positions into three seperate parts
		//Calculate dir change
		if (hitPos <= (playerSize - offSet)) {
			dir = MoveDirection::RIGHTUP;
		}
		else if (hitPos >= playerSize + (offSet - 10)) {
			dir = MoveDirection::RIGHTDOWN;
		}
		else {
			dir = MoveDirection::RIGHT;
		}
	}

	//If Ball is moving right
	if (m_dir == MoveDirection::RIGHT || m_dir == MoveDirection::RIGHTDOWN || m_dir == MoveDirection::RIGHTUP)
	{
		int hitPos = m_pos.y - player.getPos().y; //Get hit position
		int playerSize = player.getPos().h / 2;
		int offSet = 15; //Enables to split up positions into three seperate parts
		//Calculate dir change
		if (hitPos <= (playerSize - offSet)) {
			dir = MoveDirection::LEFTUP;
		}
		else if (hitPos >= (playerSize + (offSet - 10))) {
			dir = MoveDirection::LEFTDOWN;
		}
		else {
			dir = MoveDirection::LEFT;
		}
	}

	return dir;
}
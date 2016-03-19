#pragma once
#ifndef MOVEDIRECTION_H
#define MOVEDIRECTION_H

enum class MoveDirection
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	LEFTUP, //Ball diagonal movement
	LEFTDOWN, //Ball diagonal movement
	RIGHTUP, //Ball diagonal movement
	RIGHTDOWN //Ball diagonal movement
};
#endif // !MOVEDIRECTION_H
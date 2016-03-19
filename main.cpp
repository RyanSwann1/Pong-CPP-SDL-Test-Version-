#include "Window.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Game.h"
#include "Ball.h"

#include <SDL.h>
#include <memory>

int main(int argc, char* args[])
{
	Window window;
	Game game;
	std::unique_ptr<Player> player1(new HumanPlayer(Player::PLAYER1_START_X_POS, Player::PLAYER1_START_Y_POS)); //Player1
	std::unique_ptr<Player> player2;
	Ball ball; //Instantitaed object of ball on the stack

	//Decide opponent
	if (game.playAgainstAI()) {
		player2 = std::unique_ptr<Player>(new ComputerPlayer(Player::PLAYER2_START_X_POS, Player::PLAYER2_START_Y_POS));
	}
	else {
		player2 = std::unique_ptr<Player>(new HumanPlayer(Player::PLAYER2_START_X_POS, Player::PLAYER2_START_Y_POS));
	}

	SDL_Event e; //Event System
	//Game loop
	while (!game.gameOver())
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT) {
				game.endGame();
			}
		}
		
		game.inputManager(*player1, *player2);
		game.update(*player1, *player2, ball); 
		window.render(*player1, *player2, ball);
	}

	return 0;
}
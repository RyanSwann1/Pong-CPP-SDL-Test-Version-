#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
class Ball;
class Player;
class Window
{
public:
	Window();
	~Window();

	void render(Player& player1, Player& player2, Ball& ball);

	//Getters
	SDL_Surface* getWindowSurface() const { return m_windowSurface; }
	SDL_Window* getWindow() const { return m_window; }
	SDL_Renderer* getRenderer() const { return m_renderer; }

private:
	SDL_Window* m_window = nullptr;
	SDL_Surface* m_windowSurface = nullptr;
	SDL_Renderer* m_renderer = nullptr;

	void createWindow(); //Create SDL Window
	void createWindowSurface(); //Create window surface
	void createRenderer(); //Create SDL Renderer

	static constexpr int SCREEN_WIDTH = 800;
	static constexpr int SCREEN_HEIGHT = 500;
};

#endif // !WINDOW_H

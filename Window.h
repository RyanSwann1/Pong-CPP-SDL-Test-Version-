#pragma once

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL.h>
class Ball;
class Player;
class Window
{
public:
	Window(const int screenWidth, const int screenHeight);
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

	int m_screenWidth = 800;
	int m_screenHeight = 500;
};

#endif // !WINDOW_H

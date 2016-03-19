#include "Window.h"
#include "Player.h"
#include "Ball.h"

#include <assert.h>
#include <iostream>


Window::Window()
{
	std::cout << "Activate.";
	createWindow();
	createWindowSurface();
	createRenderer();
}

Window::~Window()
{
	//Destroy window
	SDL_DestroyWindow(m_window);
	m_window = nullptr;

	//Free window surface
	//SDL_FreeSurface(m_windowSurface);
	m_windowSurface = nullptr;

	//Destroy renderer
	SDL_DestroyRenderer(m_renderer);
	m_renderer = nullptr;
}

void Window::render(Player & player1, Player & player2, Ball & ball)
{
	SDL_RenderClear(m_renderer);

	//Players
	SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(m_renderer, &player1.getPos());
	SDL_RenderFillRect(m_renderer, &player2.getPos());

	//Ball
	SDL_RenderFillRect(m_renderer, &ball.getPos());

	//Background
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

	//Apply
	SDL_RenderPresent(m_renderer);
}

void Window::createWindow()
{
	m_window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	assert(m_window != nullptr);
}

void Window::createWindowSurface()
{
	m_windowSurface = SDL_GetWindowSurface(m_window);
	assert(m_windowSurface != nullptr);
}

void Window::createRenderer()
{
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	assert(m_renderer != nullptr);
}




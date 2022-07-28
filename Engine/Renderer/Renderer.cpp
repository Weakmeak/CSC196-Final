#include "Renderer.h" 
#include <SDL.h> 
#include <SDL_ttf.h> 

namespace digi
{
	SDL_Renderer* renderer{ nullptr };
	SDL_Window* window{ nullptr };

	void Renderer::CreateWindow(int width, int height, const char* name)
	{
		m_width = width;
		m_height = height;

		m_window = SDL_CreateWindow(name, 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}

	void Renderer::BeginFrame()
	{
		SDL_SetRenderDrawColor(m_renderer, m_clearColor.r, m_clearColor.g, m_clearColor.b, m_clearColor.a);
		SDL_RenderClear(m_renderer);
	}

	void Renderer::EndFrame()
	{
		SDL_RenderPresent(m_renderer);
	}

	void Renderer::drawLine(float x1, float y1, float x2, float y2, const Color& col)
	{
		SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, col.a);
		SDL_RenderDrawLineF(m_renderer, x1, y1, x2, y2);
	}

	void Renderer::drawLine(const Vector2& vec1, const Vector2& vec2, const Color& col)
	{
		SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, col.a);
		SDL_RenderDrawLineF(m_renderer, vec1.x, vec1.y, vec2.x, vec2.y);
	}

	void Renderer::drawPoint(float x, float y, const Color& col)
	{
		SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, col.a);
		SDL_RenderDrawPoint(m_renderer, x, y);
	}

	void Renderer::drawPoint(const Vector2& vec, const Color& col)
	{
		SDL_SetRenderDrawColor(m_renderer, col.r, col.g, col.b, col.a);
		SDL_RenderDrawPoint(m_renderer, vec.x, vec.y);
	}

	void Renderer::Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO);
		TTF_Init();
	}

	void Renderer::Shutdown()
	{
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		TTF_Quit();
	}
}
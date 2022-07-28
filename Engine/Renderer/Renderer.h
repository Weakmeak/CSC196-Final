#pragma once
#include "../Math/Vector2.h"
#include "../Math/Color.h"

class SDL_Renderer;	//Forward Declaration, we're coming back to this later
class SDL_Window;

namespace digi {

	class Renderer {
		public:
			Renderer() = default;
			~Renderer() = default;

			void Initialize();
			void Shutdown();

			void CreateWindow(int width, int height, const char* name);
			void BeginFrame();
			void EndFrame();
			inline void setClearColor(const Color& col) { m_clearColor = col; };

			void drawLine(float x1, float y1, float x2, float y2, const Color& col);
			void drawLine(const Vector2& vec1, const Vector2& vec2, const Color& col);
			void drawPoint(float x, float y, const Color& col);
			void drawPoint(const Vector2& vec, const Color& col);

			int getWindowWidth() { return m_width; }
			int getWindowHeight() { return m_height; }

			friend class Text;

		private:

			int m_width = 0;
			int m_height = 0;
			Color m_clearColor = Color{0,0,0,255};

			SDL_Renderer* m_renderer{ nullptr };
			SDL_Window* m_window{ nullptr };
	};

}
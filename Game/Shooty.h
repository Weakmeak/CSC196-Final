#pragma once
#include "Framework/Game.h"
namespace digi {
	class Font;
	class Text;
}
class Shooty : public digi::Game{
	// Inherited via Game
	public:
		Shooty() = default;
		~Shooty() = default;
		void Initialize() override;
		void Shutdown() override;
		void Update() override;
		void Draw(digi::Renderer& renderer) override;

	private:
		float timeSurvived = 0;
		float spawnTime = .5;
		std::unique_ptr<digi::Font> font1;
		std::unique_ptr<digi::Font> font2;
		std::unique_ptr<digi::Text> title1;
		std::unique_ptr<digi::Text> title2;
};
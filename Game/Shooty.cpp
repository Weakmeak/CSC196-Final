#include "Shooty.h"
#include "Player.h"
#include "Enemy.h"
#include "Spray.h"
#include "Engine.h"

using namespace digi;

void Shooty::Initialize()
{
	m_scene = std::make_unique<digi::Scene>(this);

	g_Miku.AddAudio("pew", "Laser_Shoot.wav");
	g_Miku.AddAudio("boom", "Explosion.wav");

	font1 = std::make_unique<Font>("Fonts/monogram-extended.ttf", 36);
	title1 = std::make_unique<Text>(font1.get());
	title1->Create(g_Ren, "Score: " + std::to_string(0), { 255, 0, 255, 255 });
	font2 = std::make_unique<Font>("Fonts/monogram-extended.ttf", 60);
	title2 = std::make_unique<Text>(font2.get());
	title2->Create(g_Ren, "GAME OVER", { 255, 0, 0, 255 });

	std::unique_ptr<Player> player = std::make_unique<Player>(Model{ "Model.txt" }, Transform{ Vector2{400,300} , 0, 5 });
	m_scene->Add(std::move(player));
}

void Shooty::Shutdown()
{

}

void Shooty::Update()
{
	g_Time.Tick();
	g_Innie.Update();
	g_Miku.Update();
	m_scene->Update();

	if (m_scene->GetActor<Player>())
	{
		timeSurvived += g_Time.deltaTime;
	}
	title1.get()->Create(g_Ren, "Score: " + std::to_string((int)round(timeSurvived * 100)), { 255, 255, 255, 255 });

	spawnTime -= g_Time.deltaTime;
	if (spawnTime < 0 && m_scene->GetActor<Player>()) {
		Vector2 temp{ digi::randomf(800), digi::randomf(600) };

		while (m_scene->GetActor<Player>()->GetTransform().position.Distance(temp) < 50) {
			temp.x = digi::randomf(800);
			temp.y = digi::randomf(600);
		}

		if (digi::random(136) % 2 == 0) {
			std::unique_ptr<Enemy> baddie = std::make_unique<Enemy>(Model{ "Enemy.txt" }, Transform{ temp , digi::randomf(6.28), 5 });
			m_scene->Add(std::move(baddie));

		}
		else {
			std::unique_ptr<Enemy> baddie = std::make_unique<Spray>(Model{ "Enemy2.txt" }, Transform{ temp , digi::randomf(6.28), 5 });
			m_scene->Add(std::move(baddie));
		}
		spawnTime = 2;
	}
}

void Shooty::Draw(digi::Renderer& renderer)
{
	m_scene->Draw(renderer);
	title1->Draw(g_Ren, { 0, 0 });
	if (!m_scene->GetActor<Player>()) {
		title2->Draw(g_Ren, { 300, 200 });
	}
}

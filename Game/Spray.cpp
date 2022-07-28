#include "Spray.h"
#include "Engine.h"
#include "Player.h"
#include "Bullet.h"
#include "Math/MathUtils.h"

using namespace digi;

void Spray::Shoot()
{
	digi::Transform tran = m_trans;

	std::unique_ptr<Bullet> bullet1 = std::make_unique<Bullet>(Model{ "Bullet.txt" }, tran);
	bullet1->SetTag("enemy");
	this->m_scene->Add(std::move(bullet1));

	tran.rotation += Math::DegToRad(5);

	std::unique_ptr<Bullet> bullet2 = std::make_unique<Bullet>(Model{ "Bullet.txt" }, tran);
	bullet2->SetTag("enemy");
	this->m_scene->Add(std::move(bullet2));

	tran.rotation -= Math::DegToRad(10);

	std::unique_ptr<Bullet> bullet3 = std::make_unique<Bullet>(Model{ "Bullet.txt" }, tran);
	bullet3->SetTag("enemy");
	this->m_scene->Add(std::move(bullet3));

	g_Miku.PlayAudio("pew");
}

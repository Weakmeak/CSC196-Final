#include "Enemy.h"
#include "Engine.h"
#include "Player.h"
#include "Bullet.h"

using namespace digi;

void Enemy::Initialize()
{
	m_fireTime = digi::randomf(1.0f, 1.5f);
	m_model.SetRadius();
}

void Enemy::Update()
{
	m_fireTime -= digi::g_Time.deltaTime;

	if (m_fireTime <= 0) {
		m_fireTime = digi::randomf(0.75f, 2.0f);
		Shoot();
	}

	Player* player = m_scene->GetActor<Player>();

	if (player) {
		digi::Vector2 direction = player->GetTransform().position - this->m_trans.position;
		m_trans.rotation = direction.GetAngle();
	}

	digi::Vector2 direction{ 1,0 };
	direction = digi::Vector2::Rotate(direction, m_trans.rotation);
	digi::Vector2 velocity = direction * m_speed * digi::g_Time.deltaTime;

	m_trans.position += velocity;

	if (m_trans.position.x > digi::g_Ren.getWindowWidth()) { m_trans.position.x = 0;}
	if (m_trans.position.x < 0) { m_trans.position.x = digi::g_Ren.getWindowWidth();}
	if (m_trans.position.y > digi::g_Ren.getWindowHeight()) { m_trans.position.y = 0;}
	if (m_trans.position.y < 0) { m_trans.position.y = digi::g_Ren.getWindowHeight();}
}

void Enemy::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other)) {
		if (other->GetTag() == "player")
		{
			destroyed = true;
			digi::g_Miku.PlayAudio("boom");
		}
	} else if (dynamic_cast<Player*>(other)) {
		destroyed = true;
		digi::g_Miku.PlayAudio("boom");
	}
}

void Enemy::Shoot()
{
	digi::Transform tran = m_trans;

	std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Model{ "Bullet.txt" }, tran);
	bullet->SetTag("enemy");
	this->m_scene->Add(std::move(bullet));

	g_Miku.PlayAudio("pew");
}

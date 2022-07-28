#include "Bullet.h"
#include "Engine.h"
#include "Enemy.h"
#include "Player.h"

using namespace digi;

void Bullet::OnCollision(Actor* other)
{
	if (dynamic_cast<Player*>(other)) {
		if (m_tag != "player") destroyed = true;
	}

	if (dynamic_cast<Enemy*>(other)) {
		if (m_tag != "enemy") destroyed = true;
	}
}

void Bullet::Update()
{
	m_lifespan -= g_Time.deltaTime;
	if (m_lifespan <= 0) { destroyed = true; }
	digi::Vector2 direction{ 1,0 };
	direction = digi::Vector2::Rotate(direction, m_trans.rotation);
	digi::Vector2 velocity = direction * m_speed * g_Time.deltaTime;

	m_trans.position += velocity;
}

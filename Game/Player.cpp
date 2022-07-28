#include "Player.h"
#include "Engine.h"
#include "Bullet.h"
#include "Enemy.h"
#include <iostream>

using namespace digi;

void Player::Update()
{
	m_velocity *= .95f;

	if (m_trans.position.x > digi::g_Ren.getWindowWidth()) { m_trans.position.x = 0; }
	if (m_trans.position.x < 0) { m_trans.position.x = (float)digi::g_Ren.getWindowWidth(); }
	if (m_trans.position.y > digi::g_Ren.getWindowHeight()) { m_trans.position.y = 0; }
	if (m_trans.position.y < 0) { m_trans.position.y = (float)digi::g_Ren.getWindowHeight(); }

	v_thrust = 0;
	h_thrust = 0;

	if (g_Innie.GetKeyDown(key_left))
	{
		h_thrust -= power * g_Time.deltaTime;
	}
	if (g_Innie.GetKeyDown(key_right))
	{
		h_thrust += power * g_Time.deltaTime;
	}
	if (g_Innie.GetKeyDown(key_up))
	{
		v_thrust -= power * g_Time.deltaTime;
	}
	if (g_Innie.GetKeyDown(key_down))
	{
		v_thrust += power * g_Time.deltaTime;
	}

	Vector2 force{ h_thrust, v_thrust };
	force *= 1.0f / (1.0f + (m_damping * g_Time.deltaTime));
	m_velocity += force;
	m_trans.position += m_velocity;

	Vector2 target = g_Innie.GetMousePosition();
	target -= m_trans.position;
	m_trans.rotation = target.GetAngle();

	if (g_Innie.GetButtonState(button_left) == InputSystem::State::Pressed)
	{
		//std::cout << "CLICK!\n";
		//fire boolet
		digi::Transform tran = m_trans;

		std::unique_ptr<Bullet> bullet = std::make_unique<Bullet>(Model{ "Bullet.txt" }, tran);
		bullet->SetTag("player");
		this->m_scene->Add(std::move(bullet));

		g_Miku.PlayAudio("pew");
	}


	
}

void Player::OnCollision(Actor* other)
{
	if (dynamic_cast<Bullet*>(other)) {
		if (other->GetTag() == "enemy")
		{
			destroyed = true;
			digi::g_Miku.PlayAudio("boom");
		}
	}
	else if (dynamic_cast<Enemy*>(other)) {
		destroyed = true;
		digi::g_Miku.PlayAudio("boom");
	}
}
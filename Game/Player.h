#pragma once
#include "../Engine/Framework/Actor.h"

class Player : public digi::Actor
{
	public:
		Player() = default;
		Player(const digi::Model& model, const digi::Transform& trans) : Actor{ model, trans } {}
		~Player() = default;

		void Update() override;
		void OnCollision(Actor* other) override;
	private:
		float m_topSpeed = 2;
		int power = 25;
		float v_thrust = 0;
		float h_thrust = 0;
};
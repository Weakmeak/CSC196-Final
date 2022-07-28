#pragma once
#include "../Engine/Framework/Actor.h"

class Enemy : public digi::Actor {
	public:
		Enemy() = default;
		Enemy(const digi::Model& model, const digi::Transform& trans) : Actor{ model, trans } { this->Initialize(); }
		~Enemy() = default;

		void Initialize();
		void Update();

		void OnCollision(Actor* other) override;

	protected:
		float m_fireTime = 1;
		float m_speed = 100;

		virtual void Shoot();
};
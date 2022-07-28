#pragma once
#include "../Engine/Framework/Actor.h"

class Bullet : public digi::Actor {
public:
	Bullet() = default;
	Bullet(const digi::Model& model, const digi::Transform& trans) : Actor{ model, trans } {}
	~Bullet() = default;

	void OnCollision(Actor* other) override;

	void Update() override;
private:
	float m_speed = 600;
	float m_lifespan = 3.5f;
};
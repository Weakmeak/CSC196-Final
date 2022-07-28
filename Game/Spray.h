#pragma once
#include "Enemy.h"
#include "../Engine/Framework/Actor.h"

class Spray : public Enemy {
	public:
		Spray(const digi::Model& model, const digi::Transform& trans) : Enemy{ model, trans } { this->Initialize(); }
		~Spray() = default;
	private :
		void Shoot() override;
};
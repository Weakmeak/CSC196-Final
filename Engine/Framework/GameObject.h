#pragma once
#include "../Math/Transform.h"

namespace digi 
{
	class GameObject 
	{
		public:
			GameObject() = default;
			GameObject(const Transform& trnsf) { m_trans = trnsf; }
			~GameObject() = default;

			float getSpeed() {}
			Transform& GetTransform() { return m_trans; }

			virtual void Update() = 0;
		protected:
			Transform m_trans;
	};
}
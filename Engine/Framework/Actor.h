#pragma once

#include "GameObject.h"
#include "../Renderer/Model.h"

namespace digi {

	class Scene;

	class Actor : public GameObject {
		public:
			Actor() = default;
			Actor(const Model& verts, const Transform& trans) : GameObject{ trans }, m_model{ verts } { m_model.SetRadius(this->GetRadius()); };
			~Actor() = default;

			virtual void Update() override {}
			virtual void Draw(Renderer ren);

			float GetRadius() { return m_model.GetRadius() * m_trans.scale; };
			std::string GetTag() { return m_tag; };
			void SetTag(const std::string& tag) { m_tag = tag; };
			virtual void OnCollision(Actor* other) {};

			friend class Scene;

		protected:
			bool destroyed = false;

			std::string m_tag = "";
			Scene* m_scene;
			Model m_model;
			Vector2 m_velocity;
			float m_damping = 1;
	};
}

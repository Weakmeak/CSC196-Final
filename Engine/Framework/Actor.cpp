#include "Actor.h"

namespace digi {
	void digi::Actor::Draw(Renderer ren)
	{
		m_model.Draw(ren, m_trans.position, m_trans.rotation, m_trans.scale);
	}
}

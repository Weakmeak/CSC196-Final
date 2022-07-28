#include "Model.h"
#include "../Core/File.h"
#include <sstream>
#include <iostream>

namespace digi {
	Model::Model(const std::string& filename)
	{
		Load(filename);
	}

	void Model::Draw(Renderer& ren, const Vector2& position, float angle, float scale)
	{
		for (size_t i = 0; i < m_points.size() - 1; i++)
		{
			Vector2 temp1 = Vector2::Rotate( (m_points[i] * scale), angle) + position;
			Vector2 temp2 = Vector2::Rotate((m_points[i + 1] * scale), angle) + position;
			ren.drawLine(temp1, temp2, m_color);
		}
	}

	float Model::calcRadius()
	{
		float rad = 0;

		for (Vector2 point : m_points) {
			if (point.Length() > rad) {
				rad = point.Length();
			}
		}

		//std::cout << rad << std::endl;
		return rad;
	}

	void Model::Load(const std::string& filename)
	{
		std::string buffer;
		ReadFile(filename, buffer);
		std::stringstream stream(buffer);

		stream >> m_color;

		std::string line;
		std::getline(stream, line);
		
		size_t numPoints = std::stoi(line);

		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;

			m_points.push_back(point);
		}
	}
}


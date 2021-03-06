#pragma once

#include "Camera.hpp"

#include <glm/vec3.hpp>

namespace GameEngine {


	class CameraObject: public Camera {
	public:

		enum class Direction {
			Up, Down, Left, Right, Forward, Back
		};

		CameraObject() = default;
		CameraObject(
			glm::vec3 _position,
			glm::vec3 _rotation,
			ProjectionType type,
			glm::vec3 _front = { 0.f, 0.f, -1.f }
		);

		void move(Direction dir, float deltaTime);
		void rotate(float x, float y);
		void update();
		void setType(ProjectionType type);
	private:

		ProjectionType type;

		glm::vec3 front = { 0.f, 0.f, -1.f };
		glm::vec3 up = { 0.0f, 1.0f, 0.0f };

		glm::vec3 position = { 0.f, 0.f, 0.f };
		glm::vec3 rotation = { 0.f, 0.f, 0.f };

		const float speed = 2.5f;
		const float sensitivity = 0.05;

		float lastX = 400, lastY = 300;
	};

}
#pragma once
#include "BEntity.h"
#include "BComponent.h"

namespace blue
{
	using namespace math;
	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		Vector2 GetPosition() const { return mPosition; }
		float GetRotation() const { return mRotation; }
		Vector2 GetScale() const { return mScale; }

		void SetPosition(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		void SetRotation(float rotate) { mRotation = rotate; }
		void SetScale(Vector2 scale) { mScale = scale; }

	private:
		Vector2 mPosition;
		Vector2 mScale;
		float mRotation;
	};
}

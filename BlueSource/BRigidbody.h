#pragma once
#include "BComponent.h"

namespace blue
{
	class Rigidbody: public Component
	{
	public:
		Rigidbody(eColliderType type);
		~Rigidbody();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

	private:
		float mMass;
		float mFriction;

		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
		Vector2 mGravity;
	};
}

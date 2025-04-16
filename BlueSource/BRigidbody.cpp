#include "BRigidbody.h"
#include "BTime.h"
#include "BTransform.h"
#include "BGameObject.h"

namespace blue
{
	Rigidbody::Rigidbody()
		: Component(enums::eComponentType::Rigidbody)
		, mbGround(false)
		, mMass(1.0f)
		, mFriction(10.0f)
		, mForce(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mLimitedVelocity(Vector2(200.0f, 1000.0f))
		, mGravity(Vector2(0.0f, 800.0f))
		, mAccelation(Vector2::Zero)
	{

	}

	Rigidbody::~Rigidbody()
	{

	}

	void Rigidbody::Initialize()
	{

	}

	void Rigidbody::Update()
	{
		mAccelation = mForce / mMass;
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			Vector2 gravity = mGravity;
			gravity.Normalize();

			float dot = mVelocity.Dot(gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			mVelocity += mGravity * Time::DeltaTime();
		}

		Vector2 gravity = mGravity;
		gravity.Normalize();
		float dot = mVelocity.Dot(gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocity.y < gravity.Length())
		{
			gravity.Normalize();
			gravity *= mLimitedVelocity.y;
		}

		if (mLimitedVelocity.x < sideVelocity.Length())
		{
			sideVelocity.Normalize();
			sideVelocity *= mLimitedVelocity.x;
		}
		mVelocity = gravity + sideVelocity;

		if (!(mVelocity == Vector2::Zero))
		{
			Vector2 friction = -mVelocity;
			friction.Normalize();
			friction = friction * mFriction * mMass * Time::DeltaTime();

			if (mVelocity.Length() <= friction.Length())
				mVelocity = Vector2::Zero;
			else
				mVelocity += friction;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		mForce = Vector2::One;
	}

	void Rigidbody::LateUpdate()
	{

	}

	void Rigidbody::Render()
	{

	}
}
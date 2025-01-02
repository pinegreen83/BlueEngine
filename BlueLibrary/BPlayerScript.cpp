#include "BPlayerScript.h"
#include "BInput.h"
#include "BTransform.h"
#include "BTIme.h"
#include "BGameObject.h"
#include "BAnimator.h"

namespace blue
{
	PlayerScript::PlayerScript()
		: mState(eState::SitDown)
		, mAnimator(nullptr)
	{

	}

	PlayerScript::~PlayerScript()
	{

	}

	void PlayerScript::Initialize()
	{

	}

	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case blue::PlayerScript::eState::SitDown:
			sitDown();
			break;
		case blue::PlayerScript::eState::Walk:
			move();
			break;
		case blue::PlayerScript::eState::Sleep:
			break;
		case blue::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}
	}

	void PlayerScript::LateUpdate()
	{

	}

	void PlayerScript::Render(HDC hdc)
	{

	}

	void PlayerScript::sitDown()
	{
		if (Input::GetKey(eKeyCode::A))
		{
			mState = eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk", true);
		}
		if (Input::GetKey(eKeyCode::D))
		{
			mState = eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk", true);
		}
		if (Input::GetKey(eKeyCode::W))
		{
			mState = eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk", true);

		}
		if (Input::GetKey(eKeyCode::S))
		{
			mState = eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk", true);
		}
	}

	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::A) || Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}
}
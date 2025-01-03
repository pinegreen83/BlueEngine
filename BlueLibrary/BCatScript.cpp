#include "BCatScript.h"
#include "BInput.h"
#include "BTransform.h"
#include "BTIme.h"
#include "BGameObject.h"
#include "BAnimator.h"

namespace blue
{
	CatScript::CatScript()
		: mState(eState::SitDown)
		, mAnimator(nullptr)
		, mTime(0.0f)
	{

	}

	CatScript::~CatScript()
	{

	}

	void CatScript::Initialize()
	{

	}

	void CatScript::Update()
	{
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case blue::CatScript::eState::SitDown:
			sitDown();
			break;
		case blue::CatScript::eState::Walk:
			move();
			break;
		case blue::CatScript::eState::Sleep:
			break;
		case blue::CatScript::eState::LayDown:
			break;
		case blue::CatScript::eState::Attack:
			break;
		default:
			break;
		}
	}

	void CatScript::LateUpdate()
	{

	}

	void CatScript::Render(HDC hdc)
	{

	}

	void CatScript::sitDown()
	{
		mTime += Time::DeltaTime();
		if (mTime > 3.0f)
		{
			mState = eState::Walk;
			int direction = rand() % 4;
			mDirection = (eDirection)direction;
			PlayWalkAnimationByDirection(mDirection);

			mTime = 0.0f;
		}
	}

	void CatScript::move()
	{
		mTime += Time::DeltaTime();
		if (mTime > 2.0f)
		{
			int isLayDown = rand() % 2;
			if (isLayDown)
			{
				mState = eState::LayDown;
				mAnimator->PlayAnimation(L"LayDown", false);
			}
			else
			{
				mState = eState::SitDown;
				mAnimator->PlayAnimation(L"SitDown", false);
			}
		}
		
		Transform* tr = GetOwner()->GetComponent<Transform>();
		translate(tr);
	}

	void CatScript::layDown()
	{

	}

	void CatScript::PlayWalkAnimationByDirection(eDirection dir)
	{
		switch (dir)
		{
		case blue::CatScript::eDirection::Left:
			mAnimator->PlayAnimation(L"LeftWalk", true);
			break;
		case blue::CatScript::eDirection::Right:
			mAnimator->PlayAnimation(L"RightWalk", true);
			break;
		case blue::CatScript::eDirection::Down:
			mAnimator->PlayAnimation(L"DownWalk", true);
			break;
		case blue::CatScript::eDirection::Up:
			mAnimator->PlayAnimation(L"UpWalk", true);
			break;
		default:
			assert(false);
			break;
		}
	}

	void CatScript::translate(Transform* tr)
	{
		Vector2 pos = tr->GetPosition();
		switch (mDirection)
		{
		case blue::CatScript::eDirection::Left:
			pos.x -= 100.0f * Time::DeltaTime();
			break;
		case blue::CatScript::eDirection::Right:
			pos.x += 100.0f * Time::DeltaTime();
			break;
		case blue::CatScript::eDirection::Down:
			pos.y += 100.0f * Time::DeltaTime();
			break;
		case blue::CatScript::eDirection::Up:
			pos.y -= 100.0f * Time::DeltaTime();
			break;
		default:
			assert(false);
			break;
		}
		tr->SetPosition(pos);
	}
}
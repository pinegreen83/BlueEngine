#include "BPlayerScript.h"
#include "BInput.h"
#include "BTransform.h"
#include "BTIme.h"
#include "BGameObject.h"
#include "BAnimator.h"
#include "BCat.h"
#include "BCatScript.h"
#include "BObject.h"
#include "BResources.h"
#include "BCollider.h"

namespace blue
{
	PlayerScript::PlayerScript()
		: mState(eState::Idle)
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
		case blue::PlayerScript::eState::Idle:
			idle();
			break;

		case blue::PlayerScript::eState::Walk:
			move();
			break;

		case blue::PlayerScript::eState::Sleep:
			break;

		case blue::PlayerScript::eState::GiveWater:
			giveWater();
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

	void PlayerScript::AttackEffect()
	{
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		CatScript* catScr = cat->AddComponent<CatScript>();

		catScr->SetPlayer(GetOwner());

		graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTex
			, Vector2(0.0f, 0.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTex
			, Vector2(0.0f, 32.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTex
			, Vector2(0.0f, 64.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTex
			, Vector2(0.0f, 96.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTex
			, Vector2(0.0f, 128.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTex
			, Vector2(0.0f, 160.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTex
			, Vector2(0.0f, 192.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);

		catAnimator->PlayAnimation(L"SitDown", false);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		Vector2 mousePos = Input::GetMousePosition();
		catScr->mDest = mousePos;
	}

	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
	}

	void PlayerScript::OnCollisionStay(Collider* other)
	{

	}

	void PlayerScript::OnCollisionExit(Collider* other)
	{

	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			CatScript* catScr = cat->AddComponent<CatScript>();

			catScr->SetPlayer(GetOwner());

			graphics::Texture* catTex = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTex
				, Vector2(0.0f, 0.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTex
				, Vector2(0.0f, 32.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTex
				, Vector2(0.0f, 64.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTex
				, Vector2(0.0f, 96.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTex
				, Vector2(0.0f, 128.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTex
				, Vector2(0.0f, 160.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTex
				, Vector2(0.0f, 192.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);

			catAnimator->PlayAnimation(L"SitDown", false);

			Transform* tr = GetOwner()->GetComponent<Transform>();

			cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = Input::GetMousePosition();
			catScr->mDest = mousePos;


			//mState = eState::GiveWater;
			//mAnimator->PlayAnimation(L"FrontGiveWater", false);

			//Vector2 mousePos = Input::GetMousePosition();
		}

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
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}

	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}
}
#include "BCameraScript.h"
#include "BInput.h"
#include "BTransform.h"
#include "BTime.h"
#include "BGameObject.h"
#include "BAnimator.h"
#include "BCat.h"
#include "BCatScript.h"
#include "BObject.h"
#include "BResources.h"

namespace blue
{
	CameraScript::CameraScript()
	{

	}

	CameraScript::~CameraScript()
	{

	}

	void CameraScript::Initialize()
	{

	}

	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}

	void CameraScript::LateUpdate()
	{

	}

	void CameraScript::Render()
	{

	}
}
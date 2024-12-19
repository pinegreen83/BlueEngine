#include "BGameObject.h"
#include "BInput.h"
#include "BTime.h"

namespace blue
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{
	
	}

	GameObject::~GameObject()
	{
	
	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A))
		{
			mX -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::D))
		{
			mX += speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::W))
		{
			mY -= speed * Time::DeltaTime();
		}

		if (Input::GetKey(eKeyCode::S))
		{
			mY += speed * Time::DeltaTime();
		}
	}

	void GameObject::LateUpdate()
	{
	
	}
	
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		HBRUSH randBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand()% 255));
		//HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, randBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));

		HPEN randPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		//HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		HPEN oldPen = (HPEN)SelectObject(hdc, randPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY, 100 + mX, 100 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}

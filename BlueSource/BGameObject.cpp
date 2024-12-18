#include "BGameObject.h"
#include "BInput.h"

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
		if (Input::GetKeyPressed(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (Input::GetKeyPressed(eKeyCode::D))
		{
			mX += 0.01f;
		}

		if (Input::GetKeyPressed(eKeyCode::W))
		{
			mY -= 0.01f;
		}

		if (Input::GetKeyPressed(eKeyCode::S))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{
	
	}
	
	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}

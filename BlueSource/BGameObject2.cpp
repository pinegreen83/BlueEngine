#include "BGameObject2.h"
#include "BInput.h"

namespace blue
{
	GameObject2::GameObject2()
		: mX(0.0f)
		, mY(0.0f)
	{

	}

	GameObject2::~GameObject2()
	{

	}
	void GameObject2::Update()
	{
		if (Input::GetKeyPressed(eKeyCode::A))
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState('D') & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState('W') & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState('S') & 0x8000)
		{
			mY += 0.01f;
		}
	}

	void GameObject2::LateUpdate()
	{

	}

	void GameObject2::Render(HDC hdc)
	{
		HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Ellipse(hdc, 1000 + mX, 600 + mY, 1100 + mX, 700 + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
		DeleteObject(redPen);
	}
}

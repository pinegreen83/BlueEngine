#include "BApplication.h"
#include "BInput.h"
#include "BTime.h"

namespace blue
{
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBitmap(NULL)
	{

    }

    Application::~Application()
    {

    }

    void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		RECT rect = {0, 0, width, height};
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);


		// 윈도우 해상도에 맞는 백 버퍼(도화지) 생성
		mBackBitmap = CreateCompatibleBitmap(mHdc, width, height);

		// 백 버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBitmap);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0.0f, 0.0f);
		//mPlayer2.SetPosition(0.0f, 0.0f);

		Input::Initialize();
		Time::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}
	
	void Application::Update()
	{
		Input::Update();
		Time::Update();

		mPlayer.Update();
		//mPlayer2.Update();
	}
	
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, 1600, 900);

		Time::Render(mBackHdc);

		mPlayer.Render(mBackHdc);
		//mPlayer2.Render(mHdc);

		// BackBuffer에 있던 걸 원본 Buffer에 복사
		BitBlt(mHdc, 0, 0, mWidth, mHeight
		, mBackHdc, 0, 0, SRCCOPY);
	}
}
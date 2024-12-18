#include "BApplication.h"
#include "BInput.h"

namespace blue
{
    Application::Application()
        : mHwnd(nullptr)
        , mHdc(nullptr)
        , mSpeed(0.0f)
    {

    }

    Application::~Application()
    {

    }

    void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mPlayer.SetPosition(0.0f, 0.0f);
		//mPlayer2.SetPosition(0.0f, 0.0f);

		Input::Initialize();
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

		mPlayer.Update();
		//mPlayer2.Update();
	}
	
	void Application::LateUpdate()
	{

	}

	void Application::Render()
	{
		mPlayer.Render(mHdc);
		//mPlayer2.Render(mHdc);
	}
}
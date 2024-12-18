#pragma once
#include "BGameObject.h"
#include "BGameObject2.h"

namespace blue
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hwnd);
		void Run();
		
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;

		GameObject mPlayer;
		//GameObject2 mPlayer2;
	};
}


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

		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();
		
		void Update();
		void LateUpdate();
		void Render();

	private:
		void clearRenderTarget();
		void copyRenderTarget(HDC source, HDC dest);
		void adjjustWindowRect(HWND hwnd, UINT width, UINT height);
		void createBuffer(UINT width, UINT height);
		void initializeEtc();

	private:
		HWND mHwnd;
		HDC mHdc;

		HDC mBackHdc;
		HBITMAP mBackBitmap;

		UINT mWidth;
		UINT mHeight;
	};
}


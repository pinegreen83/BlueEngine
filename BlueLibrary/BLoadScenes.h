#pragma once
#include "../BlueSource/BSceneManager.h"
#include "BPlayScene.h"

//#ifdef _DEBUG
//#pragma comment(lib, "../x64/Debug/BlueLibrary.lib")
//#else
//#pragma comment(lib, "../x64/Release/BlueLibrary.lib")
//#endif

namespace blue
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
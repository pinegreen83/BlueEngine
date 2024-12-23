#pragma once
#include "../BlueSource/BSceneManager.h"
#include "BPlayScene.h"
#include "BTItleScene.h"

namespace blue
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TItleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
#pragma once
#include "../BlueSource/BSceneManager.h"
#include "BPlayScene.h"
#include "BTItleScene.h"
#include "BToolScene.h"

namespace blue
{
	void LoadScenes()
	{
		SceneManager::CreateScene<TItleScene>(L"TitleScene");
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}
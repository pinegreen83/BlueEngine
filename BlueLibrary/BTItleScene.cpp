#include "BTItleScene.h"
#include "BInput.h"
#include "BPlayScene.h"
#include "BSceneManager.h"s

namespace blue
{
	TItleScene::TItleScene()
	{

	}
	
	TItleScene::~TItleScene()
	{

	}

	void TItleScene::Initialize()
	{
		Scene::Initialize();
	}

	void TItleScene::Update()
	{
		Scene::Update();
	}

	void TItleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TItleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}

	void TItleScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void TItleScene::OnExit()
	{
		Scene::OnExit();
	}
}
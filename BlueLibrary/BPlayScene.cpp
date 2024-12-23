#include "BPlayScene.h"
#include "BGameObject.h"
#include "BPlayer.h"
#include "BTransform.h"
#include "BSpriteRenderer.h"
#include "BInput.h"
#include "BTItleScene.h"
#include "BSceneManager.h"
#include "BObject.h"

namespace blue
{
	PlayScene::PlayScene()
	{

	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		{
			//bg = new Player();
			//Transform* tr = bg->AddComponent<Transform>();
			//tr->SetPos(Vector2(0,0));
			//tr->SetName(L"TR");

			//SpriteRenderer* sr
			//	= bg->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(L"../Resources/CygnusGarden.png");
			//AddGameObject(bg, enums::eLayerType::BackGround);

			bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"../Resources/CygnusGarden.png");
		}
	}

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}
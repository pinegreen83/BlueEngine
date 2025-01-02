#include "BPlayScene.h"
#include "BGameObject.h"
#include "BPlayer.h"
#include "BTransform.h"
#include "BSpriteRenderer.h"
#include "BInput.h"
#include "BTItleScene.h"
#include "BSceneManager.h"
#include "BObject.h"
#include "BTexture.h"
#include "BResources.h"
#include "BPlayerScript.h"
#include "BCamera.h"
#include "BRenderer.h"
#include "BAnimator.h"

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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Particle);
		/*SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSize(Vector2(3.0f, 3.0f));*/
		mPlayer->AddComponent<PlayerScript>();

		//graphics::Texture* packmanTexture = Resources::Find<graphics::Texture>(L"MapleEffect");
		//Animator* animator = mPlayer->AddComponent<Animator>();
		//animator->CreateAnimation(L"CatFrontMove", packmanTexture
		//	, Vector2(0.0f, 0.0f), Vector2(386.0f, 246.0f), Vector2::Zero, 8, 0.1f);
		//animator->PlayAnimation(L"CatFrontMove", true);

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"DownWalk", catTexture
			, Vector2(0.0f, 0.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"RightWalk", catTexture
			, Vector2(0.0f, 32.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"UpWalk", catTexture
			, Vector2(0.0f, 64.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"LeftWalk", catTexture
			, Vector2(0.0f, 96.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"SitDown", catTexture
			, Vector2(0.0f, 128.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);
		animator->CreateAnimation(L"Grooming", catTexture
			, Vector2(0.0f, 160.0f), Vector2(32, 32), Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"SitDown", false);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(100.0f, 100.0f));
		mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));
		//mPlayer->GetComponent<Transform>()->SetRotation(30.0f);
		/*sr->SetTexture(packmanTexture);*/

		GameObject* bg = object::Instantiate<GameObject>(enums::eLayerType::Player);
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		//bgSr->SetSize(Vector2(3.0f, 3.0f));

		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"Bubble");
		bgSr->SetTexture(bgTexture);

		Scene::Initialize();
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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
	}
}
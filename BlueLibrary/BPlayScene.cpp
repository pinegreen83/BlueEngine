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
#include "BCat.h"
#include "BCatScript.h"
#include "BBoxCollider2D.h"
#include "BCircleCollider2D.h"
#include "BCollisionManager.h"
#include "BTile.h"
#include "BTileMapRenderer.h"
#include "BRigidbody.h"
#include "BFloor.h"
#include "BFloorScript.h"

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

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);

		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		//CircleCollider2D* collider = mPlayer->AddComponent<CircleCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
		//mPlayer->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		mPlayer->AddComponent<Rigidbody>();

		Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(100.0f, 600.0f));
		floor->SetName(L"Floor");
		BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>();
		floorCol->SetSize(Vector2(3.0f, 1.0f));
		floor->AddComponent<FloorScript>();

		
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
		Scene::OnEnter();

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);
	}

	void PlayScene::OnExit()
	{
		Scene::OnExit();
	}
}
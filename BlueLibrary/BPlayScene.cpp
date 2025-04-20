#include "BPlayScene.h"
#include "BGameObject.h"
#include "BPlayer.h"
#include "BUIManager.h"
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
#include "BAudioClip.h"
#include "BAudioListener.h"
#include "BAudioSource.h"
#include "BGraphicDevice_DX11.h"
#include "BSpriteRenderer.h"
#include "BMaterial.h"

namespace blue
{
	PlayScene::PlayScene()
		: mPlayer(nullptr)
	{

	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		//// main camera
		//GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		//Camera* cameraComp = camera->AddComponent<Camera>();
		//renderer::mainCamera = cameraComp;

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);

		SpriteRenderer* sr = mPlayer->AddComponent<SpriteRenderer>();
		sr->SetSprite(Resources::Find<graphics::Texture>(L"Player"));

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

	void PlayScene::Render()
	{
		Scene::Render();
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();

		//CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		//CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);

		//UIManager::Push(eUIType::Button);
	}

	void PlayScene::OnExit()
	{
		//UIManager::Pop(eUIType::Button);

		Scene::OnExit();
	}
}
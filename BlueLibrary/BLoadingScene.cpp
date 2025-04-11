#include "BLoadingScene.h"
#include "BRenderer.h"
#include "BSceneManager.h"
#include "BResources.h"
#include "BTexture.h"

namespace blue
{
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
	{

	}

	LoadingScene::~LoadingScene()
	{
		delete mResourcesLoad;
		mResourcesLoad = nullptr;
	}

	void LoadingScene::Initialize()
	{
		mResourcesLoad = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutex));
	}

	void LoadingScene::Update()
	{
		if (mbLoadCompleted)
		{
			mResourcesLoad->join();

			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render(HDC hdc)
	{

	}

	void LoadingScene::OnEnter()
	{

	}

	void LoadingScene::OnExit()
	{

	}

	void LoadingScene::resourcesLoad(std::mutex& m)
	{
		m.lock();
		{
			Resources::Load <graphics::Texture>(L"Cat", L"../Resources/ChickenAlpha.bmp");
			Resources::Load <graphics::Texture>(L"Player", L"../Resources/Player.bmp");
			Resources::Load <graphics::Texture>(L"SpringFloor", L"../Resources/SpringFloor.bmp");
			Resources::Load <graphics::Texture>(L"HPBAR", L"../Resources/HPBAR.bmp");
			Resources::Load <graphics::Texture>(L"PixelMap", L"../Resources/pixelMap.bmp");
		}
		m.unlock();

		// complete
		mbLoadCompleted = true;
	}
}
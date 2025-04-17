#include "BLoadingScene.h"
#include "BRenderer.h"
#include "BSceneManager.h"
#include "BResources.h"
#include "BTexture.h"
#include "BApplication.h"

extern blue::Application application;

namespace blue
{
	LoadingScene::LoadingScene()
		: mbLoadCompleted(false)
		, mMutualExclusion()
		, mResourcesLoadThread()
	{

	}

	LoadingScene::~LoadingScene()
	{
		delete mResourcesLoadThread;
		mResourcesLoadThread = nullptr;
	}

	void LoadingScene::Initialize()
	{
		mResourcesLoadThread = new std::thread(&LoadingScene::resourcesLoad, this, std::ref(mMutualExclusion));
	}

	void LoadingScene::Update()
	{

	}

	void LoadingScene::LateUpdate()
	{

	}

	void LoadingScene::Render()
	{
		int a = 0;

		if (mbLoadCompleted /*&& application.IsLoaded()*/)
		{
			// 메인쓰레드가 종료될 때 자식쓰레드가 남아있다면
			// 자식쓰레드를 메인쓰레드에 편입시켜 메인쓰레드가 종료되기 전까지 block
			mResourcesLoadThread->join();

			// 메인쓰레드와 완전 분리 시켜 독립적인 쓰레드 운영가능
			//mResourcesLoadThread->detach();

			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void LoadingScene::OnEnter()
	{

	}

	void LoadingScene::OnExit()
	{

	}

	void LoadingScene::resourcesLoad(std::mutex& m)
	{
		while (true)
		{
			if (application.IsLoaded() == true)
				break;
		}

		m.lock();
		{
			Resources::Load<graphics::Texture>(L"Player", L"..\\Resources\\1.bmp");
		}
		m.unlock();

		// complete
		mbLoadCompleted = true;
	}
}
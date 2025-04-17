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
			// ���ξ����尡 ����� �� �ڽľ����尡 �����ִٸ�
			// �ڽľ����带 ���ξ����忡 ���Խ��� ���ξ����尡 ����Ǳ� ������ block
			mResourcesLoadThread->join();

			// ���ξ������ ���� �и� ���� �������� ������ �����
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
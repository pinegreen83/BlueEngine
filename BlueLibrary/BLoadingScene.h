#pragma once
#include "..\BlueSource\BScene.h"

namespace blue
{
	class LoadingScene : public Scene
	{
	public:
		LoadingScene();
		~LoadingScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

		void OnEnter() override;
		void OnExit() override;

	private:
		void resourcesLoad(std::mutex& m);

	private:
		bool mbLoadCompleted;
		std::thread* mResourcesLoadThread;
		std::mutex mMutualExclusion;
	};
}
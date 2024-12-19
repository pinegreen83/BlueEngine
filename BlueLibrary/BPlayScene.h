#pragma once
#include "../BlueSource/BScene.h"

namespace blue
{
	class PlayScene : public Scene
	{
	public:
		PlayScene();
		~PlayScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	};
}

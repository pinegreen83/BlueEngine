#pragma once
#include "../BlueSource/BScene.h"

namespace blue
{
	class TItleScene : public Scene
	{
	public:
		TItleScene();
		~TItleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		
	};
}

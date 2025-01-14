#pragma once
#include "../BlueSource/BGameObject.h"

namespace blue
{
	class Tile : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPosition(int x, int y);

	private:

	};
}

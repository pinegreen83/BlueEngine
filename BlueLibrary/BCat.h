#pragma once
#include "../BlueSource/BGameObject.h"

namespace blue
{
	class Cat : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

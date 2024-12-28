#pragma once
#include "../BlueSource/BScript.h"

namespace blue
{
	class PlayerScript :public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}

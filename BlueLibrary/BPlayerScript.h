#pragma once
#include "../BlueSource/BScript.h"

namespace blue
{
	class PlayerScript :public Script
	{
	public:
		enum class eState
		{
			SitDown,
			Walk,
			Sleep,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		void sitDown();
		void move();

	private:
		eState mState;
		class Animator* mAnimator;
	};
}

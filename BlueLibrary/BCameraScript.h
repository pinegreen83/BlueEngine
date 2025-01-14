#pragma once
#include "../BlueSource/BScript.h"
#include "../BlueSource/BTransform.h"

namespace blue
{
	class CameraScript :public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}
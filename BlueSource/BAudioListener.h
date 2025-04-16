#pragma once
#include "BComponent.h"

namespace blue
{
	class AudioListener : public Component
	{
	public:
		AudioListener();
		~AudioListener();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:

	};
}

#pragma once
#include "../BlueSource/BResources.h"
#include "../BlueSource/BTexture.h"

namespace blue
{
	void LoadResources()
	{
		Resources::Load <graphics::Texture>(L"BG", L"../Resources/CygnusGarden.png");
	}
}
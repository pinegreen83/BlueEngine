#pragma once
#include "../BlueSource/BResources.h"
#include "../BlueSource/BTexture.h"

namespace blue
{
	void LoadResources()
	{
		Resources::Load <graphics::Texture>(L"Cat", L"../Resources/ChickenAlpha.bmp");
		Resources::Load <graphics::Texture>(L"Player", L"../Resources/Player.bmp");
	}
}
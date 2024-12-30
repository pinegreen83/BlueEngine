#pragma once
#include "../BlueSource/BResources.h"
#include "../BlueSource/BTexture.h"

namespace blue
{
	void LoadResources()
	{
		Resources::Load <graphics::Texture>(L"Map", L"../Resources/img/map/map_pure.png");
		Resources::Load <graphics::Texture>(L"PackMan", L"../Resources/img/pacman/0.png");
		Resources::Load <graphics::Texture>(L"Chichken", L"../Resources/chicken.bmp");
		Resources::Load <graphics::Texture>(L"Cat", L"../Resources/ChickenAlpha.bmp");
	}
}
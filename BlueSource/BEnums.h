#pragma once

namespace blue::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		//Tree,
		//Character,
		Player,
		Max = 16,
	};

	enum class eResourceType
	{	
		Texture,
		//Mesh,
		//Shader,
		AudioClip,
		Prefab,
		End,
	};
}
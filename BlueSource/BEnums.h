#pragma once

namespace blue::enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Script,
		Camera,
		End,
	};

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
		AudioClip,
		Prefab,
		End,
	};
}
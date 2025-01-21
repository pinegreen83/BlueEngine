#pragma once
#include "BFmod.h"
#include "BResource.h"

namespace blue
{
	class AudioClip : public Resource
	{
	public:
		AudioClip();
		virtual ~AudioClip();

		virtual HRESULT Load(const std::wstring& path) override;

	private:
		FMOD::Sound* mSound;
		FMOD::Channel* mChannel;

	};
}

#include "BAudioListener.h"
#include "BTransform.h"
#include "BGameObject.h"
#include "BFmod.h"

namespace blue
{
	AudioListener::AudioListener()
		: Component(enums::eComponentType::AudioListener)
	{

	}

	AudioListener::~AudioListener()
	{

	}

	void AudioListener::Initialize()
	{

	}

	void AudioListener::Update()
	{

	}

	void AudioListener::LateUpdate()
	{
		Transform* tr = nullptr;
		tr = GetOwner()->GetComponent<Transform>();

		Vector3 pos;
		Fmod::Set3DListenerAttributes(pos);
	}

	void AudioListener::Render()
	{

	}
}
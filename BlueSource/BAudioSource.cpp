#include "BAudioSource.h"
#include "BTransform.h"
#include "BGameObject.h"
#include "BFmod.h"

namespace blue
{
	AudioSource::AudioSource()
		: Component(enums::eComponentType::AudioSource)
		, mAudioClip(nullptr)
	{

	}

	AudioSource::~AudioSource()
	{

	}

	void AudioSource::Initialize()
	{

	}

	void AudioSource::Update()
	{

	}

	void AudioSource::LateUpdate()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		//mAudioClip->Set3DAttributes(pos);
	}

	void AudioSource::Render()
	{

	}

	void AudioSource::Play()
	{
		mAudioClip->Play();
	}

	void AudioSource::Stop()
	{
		mAudioClip->Stop();
	}

	void AudioSource::SetLoop(bool loop)
	{
		mAudioClip->SetLoop(loop);
	}
}
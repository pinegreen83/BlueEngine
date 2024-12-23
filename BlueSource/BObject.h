#pragma once
#include "BComponent.h"
#include "BGameObject.h"
#include "BLayer.h"
#include "BScene.h"
#include "BSceneManager.h"
#include "BTransform.h"


namespace blue::object
{
	template<typename T>
	static T* Instantiate(blue::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template<typename T>
	static T* Instantiate(blue::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}
}
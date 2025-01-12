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
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template<typename T>
	static T* Instantiate(blue::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		// 현재 씬에서 게임 오브젝트를 DontDestroy 씬으로 넣어줌.
		activeScene->EraseGameObject(gameObject);

		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyOnLoad();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}
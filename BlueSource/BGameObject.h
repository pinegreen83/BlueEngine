#pragma once
#include "CommonInclude.h"
#include "BComponent.h"
//#include "BObject.h"

namespace blue
{
	class GameObject
	{
	public:
		//friend void object::Destroy(GameObject* obj);

		enum class eState
		{
			Active,
			Paused,
			Dead,
			End
		};

		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);

			mComponents[(UINT)comp->GetType()] = comp;

			return comp;
		}
		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;

			}
			return component;
		}

		eState GetActive() { return mState; }
		void SetActive(bool power)
		{
			if (power == true) mState = eState::Active;
			if (power == false) mState = eState::Paused;
		}
		bool IsActive() { return mState == eState::Active; }

		void Death() { mState = eState::Dead; }

	private:
		void initializeTransform();

	private:
		eState mState;
		std::vector<Component*> mComponents;
	};
}


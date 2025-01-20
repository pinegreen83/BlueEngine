#pragma once
#include "BEntity.h"

namespace blue
{
	using namespace enums;
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();
		
		void Initialize();
		void Active();
		void InActive();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnLateUpdate();
		virtual void OnRender(HDC hdc);
		virtual void OnClear();

		eUIType GetType() { return mType; }
		void SetType(eUIType type) { mType = type; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }

		Vector2 GetPos() { return mPosition; }
		void SetPos(Vector2 position) { mPosition = position; }
		Vector2 GetSize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }

	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnabled;

		Vector2 mPosition;
		Vector2 mSize;
	};
}

#pragma once
#include "BEntity.h"

namespace blue
{
	class Resource : public Entity // 추상 클래스 메모리 할당이 안된다.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // pure virtual function 실제 메모리 할당이 불가능함.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}

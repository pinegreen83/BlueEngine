#pragma once
#include "BEntity.h"

namespace blue
{
	class Resource : public Entity // �߻� Ŭ���� �޸� �Ҵ��� �ȵȴ�.
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // pure virtual function ���� �޸� �Ҵ��� �Ұ�����.

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}

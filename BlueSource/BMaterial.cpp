#include "BMaterial.h"

namespace blue
{
	Material::Material()
		: Resource(enums::eResourceType::Material)
		, mMode(graphics::eRenderingMode::Opaque)
		, mAlbedoTexture(nullptr)
		, mShader(nullptr)
	{

	}

	Material::~Material()
	{
	}

	HRESULT Material::Save(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	HRESULT Material::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Material::Bind()
	{
		if(mShader)
			mShader->Bind();

		if (mAlbedoTexture)
			mAlbedoTexture->Bind(graphics::eShaderStage::PS, (UINT)graphics::eTextureType::Albedo);
	}

	void Material::BindShader()
	{
		if (mShader)
			mShader->Bind();
	}
	void Material::BindTextures()
	{
		if (mAlbedoTexture)
			mAlbedoTexture->Bind(graphics::eShaderStage::PS, (UINT)graphics::eTextureType::Albedo);
	}
}
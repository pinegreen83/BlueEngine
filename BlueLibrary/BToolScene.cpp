#include "BToolScene.h"
#include "BObject.h"
#include "BTile.h"
#include "BTileMapRenderer.h"
#include "BResources.h"
#include "BTexture.h"
#include "BCamera.h"
#include "BRenderer.h"
#include "BInput.h"
#include "BCameraScript.h"

namespace blue
{
	ToolScene::ToolScene()
	{

	}

	ToolScene::~ToolScene()
	{

	}

	void ToolScene::Initialize()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		camera->AddComponent<CameraScript>();

		renderer::mainCamera = cameraComp;

		Scene::Initialize();
	}

	void ToolScene::Update()
	{
		Scene::Update();
	}

	void ToolScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::LButton))
		{
			createTileObject();
		}

		if (Input::GetKeyDown(eKeyCode::S))
		{
			Save();
		}
		if (Input::GetKeyDown(eKeyCode::L))
		{
			Load();
		}
	}

	void ToolScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		renderGreed(hdc);
	}

	void ToolScene::OnEnter()
	{
		Scene::OnEnter();
	}

	void ToolScene::OnExit()
	{
		Scene::OnExit();
	}

	void ToolScene::Save()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"Tile\0*.tile\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
		
		if (false == GetSaveFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"wb");

		for (Tile* tile : mTiles)
		{
			TileMapRenderer* tmr = tile->GetComponent<TileMapRenderer>();
			Transform* tr = tile->GetComponent<Transform>();
			
			Vector2 sourceIndex = tmr->GetIndex();
			Vector2 position = tr->GetPosition();
			
			int x = sourceIndex.x;
			fwrite(&x, sizeof(int), 1, pFile);
			int y = sourceIndex.y;
			fwrite(&y, sizeof(int), 1, pFile);

			x = position.x;
			fwrite(&x, sizeof(int), 1, pFile);
			y = position.y;
			fwrite(&y, sizeof(int), 1, pFile);
		}

		fclose(pFile);
	}

	void ToolScene::Load()
	{
		OPENFILENAME ofn = {};

		wchar_t szFilePath[256] = {};

		ZeroMemory(&ofn, sizeof(ofn));
		ofn.lStructSize = sizeof(ofn);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = szFilePath;
		ofn.lpstrFile[0] = '\0';
		ofn.nMaxFile = 256;
		ofn.lpstrFilter = L"All\0*.*\0Text\0*.TXT\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (false == GetOpenFileName(&ofn))
			return;

		FILE* pFile = nullptr;
		_wfopen_s(&pFile, szFilePath, L"rb");

		while (true)
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;

			if (fread(&idxX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&idxY, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posX, sizeof(int), 1, pFile) == NULL)
				break;
			if (fread(&posY, sizeof(int), 1, pFile) == NULL)
				break;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile, Vector2(posX, posY));
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(Vector2(idxX, idxY));

			mTiles.push_back(tile);
		}

		fclose(pFile);
	}

	void ToolScene::renderGreed(HDC hdc)
	{
		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = renderer::mainCamera->CalculatePosition
			(
				Vector2(TileMapRenderer::TileSize.x * i, 0.0f)
			);

			MoveToEx(hdc, pos.x, 0, NULL);
			LineTo(hdc, pos.x, 1000);
		}

		for (size_t i = 0; i < 50; i++)
		{
			Vector2 pos = renderer::mainCamera->CalculatePosition
			(
				Vector2(0.0f, TileMapRenderer::TileSize.y * i)
			);

			MoveToEx(hdc, 0, pos.y, NULL);
			LineTo(hdc, 1000, pos.y);
		}
	}

	void ToolScene::createTileObject()
	{
		Vector2 pos = Input::GetMousePosition();
		pos = renderer::mainCamera->CalculateTilePosition(pos);

		if (pos.x >= 0.0f && pos.y >= 0.0f)
		{
			int idxX = pos.x / TileMapRenderer::TileSize.x;
			int idxY = pos.y / TileMapRenderer::TileSize.y;

			Tile* tile = object::Instantiate<Tile>(eLayerType::Tile);
			TileMapRenderer* tmr = tile->AddComponent<TileMapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"SpringFloor"));
			tmr->SetIndex(TileMapRenderer::SelectedIndex);

			tile->SetIndexPosition(idxX, idxY);
			mTiles.push_back(tile);
		}
	}
}

LRESULT CALLBACK WndTileProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		POINT mousePos = {};
		GetCursorPos(&mousePos);
		ScreenToClient(hWnd, &mousePos);

		blue::math::Vector2 mousePosition;
		mousePosition.x = mousePos.x;
		mousePosition.y = mousePos.y;

		int idxX = mousePosition.x / blue::TileMapRenderer::OriginTileSize.x;
		int idxY = mousePosition.y / blue::TileMapRenderer::OriginTileSize.y;

		blue::TileMapRenderer::SelectedIndex = Vector2(idxX, idxY);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		blue::graphics::Texture* texture
			= blue::Resources::Find<blue::graphics::Texture>(L"SpringFloor");

		TransparentBlt(hdc
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, texture->GetHdc()
			, 0, 0
			, texture->GetWidth()
			, texture->GetHeight()
			, RGB(255, 0, 255));

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
#include "BBoxCollider2D.h"
#include "BTransform.h"
#include "BGameObject.h"
#include "BRenderer.h"
#include "BCamera.h"

namespace blue
{
	BoxCollider2D::BoxCollider2D()
		: Collider(enums::eColliderType::Rect2D)
	{

	}

	BoxCollider2D::~BoxCollider2D()
	{

	}

	void BoxCollider2D::Initialize()
	{

	}

	void BoxCollider2D::Update()
	{

	}

	void BoxCollider2D::LateUpdate()
	{

	}

	void BoxCollider2D::Render()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
	}
}
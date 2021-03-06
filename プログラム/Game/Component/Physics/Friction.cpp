#include "../../pch.h"
#include "Friction.h"
#include "../../DebugString.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Friction::Friction()
	:
	m_normal(Vector3::Up),
	m_isHit(false)
{
}

Friction::~Friction()
{
}

void Friction::LateUpdate(float elapsedTime)
{
	float friction = 0.9f;

	Vector3 vel = m_gameObject->GetTransform().WorldVel() * friction;
	m_gameObject->GetTransform().WorldVel(vel);

	// 加速度に摩擦を加える
	Vector3 accel = m_gameObject->GetTransform().WorldAccel() * friction;
	m_gameObject->GetTransform().WorldAccel(accel);
}

// 衝突時の処理
void Friction::OnCollision(GameObject & obj, MyCollisionObject::CollisionObject & collisionObject, DirectX::SimpleMath::Vector3 & hitPos)
{
	
}

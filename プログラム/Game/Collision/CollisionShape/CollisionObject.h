#pragma once

namespace MyCollisionObject
{
	class Sphere;
	class Segment;
	class Plane;
	class Triangle;
	class Mesh;

	/// <summary>
	/// 形状
	/// </summary>
	enum SHAPE_TYPE
	{
		SHAPE_TYPE_NONE = -1,
		SHAPE_TYPE_SPHERE,
		SHAPE_TYPE_SEGMENT,
		SHAPE_TYPE_PLANE,
		SHAPE_TYPE_TRIANGLE,
		SHAPE_TYPE_MESH,

		SHAPE_TYPE_MAX
	};

	/// <summary>
	/// 形状データの共用体
	/// </summary>
	union Shape
	{
		Sphere* sphere;
		Segment* segment;
		Plane* plane;
		Triangle* triangle;
		Mesh* mesh;
	};

	/// <summary>
	/// 衝突時のデータの構造体
	/// </summary>
	class CollisionData
	{
	public:
		// コンストラクタ
		CollisionData();

		// 衝突したかどうか
		bool isHit;
		// 衝突相手の形状
		SHAPE_TYPE type;
		// 衝突相手の形状データ
		Shape shape;
		// 衝突場所
		DirectX::SimpleMath::Vector3 hitPos;
	};

	/// <summary>
	/// 当たり判定のオブジェクト
	/// </summary>
	class CollisionObject
	{
	public:
		// コンストラクタ
		CollisionObject(SHAPE_TYPE _type);
		// デストラクタ
		virtual ~CollisionObject() {}

		// 当たり判定の形状での処理
		virtual bool CollisionShape(CollisionObject& col) = 0;

	public:
		// 自身の形状がなにか
		SHAPE_TYPE type;
		// 衝突時のデータ
		CollisionData collisionData;
		// 自身の形状のデータ
		Shape shape;
	};
}
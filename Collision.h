#pragma once
#include "Vec2.h"

class PlayerNew;
class DrawMapStage2;
class Collision
{
public:
	Collision();
	~Collision();

	void Init();
	void Update();
	void Draw();

//当たり判定
public:
	bool HitObject();//地面との当たり判定
	bool HItLadder();//梯子との当たり判定

//渡し
public:
	bool GetGravity() { return m_isGravity; }

	float GetPos() { return m_posY; }
private:
	bool m_isGravity;

	float m_posY;

	float m_landingPos;//着地位置

	PlayerNew* m_pPlayer;
	DrawMapStage2* m_pMap;
};


#pragma once

class PlayerNew;
class DrawMapStage2;
class Collision
{
public:
	Collision();
	~Collision();

	void Init();
	void Update();
	bool HitObject();//オブジェクトとの当たり判定
	void Draw();
public:
	bool GetGravity() { return m_isGravity; }
private:
	bool m_isGravity;
	PlayerNew* m_pPlayer;
	DrawMapStage2* m_pMap;
};


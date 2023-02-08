#pragma once
#include "Vec2.h"

class Enemy
{
public:
	Enemy();
	virtual~Enemy();

	virtual void Init();
	virtual void End();
	virtual void Update();
	virtual void Draw();

	void SetHandle(int handle);

	Vec2 GetSize() { return m_size; }
	Vec2 GetSizeBottom() { return m_sizeBottom; }

	Vec2 GetSizeHit() { return m_sizeHit; }
	Vec2 GetSizeBottomHit() { return m_sizeBottomHit; }

private:
	//敵アイ
	void EyeEnemy();
	//敵射撃
	void ShotEnemy();
	void ShotEnemyDraw();
	//状態
	void Condition();


private:
	//グラフィックハンドル
	int m_handle;
	int m_eyeImagePos;
	//アニメーションフレームカウント
	int m_frameCount;
	//エネミーの見ている方向
	bool m_direction;
	//動いているか
	bool m_isRunMove;
	//エネミーの位置
	Vec2 m_pos;
	Vec2 m_vec;
	//エネミーのサイズ
	Vec2 m_size;
	Vec2 m_sizeBottom;
	//エネミー攻撃受け範囲
	Vec2 m_sizeHit;
	Vec2 m_sizeBottomHit;
	//ショットエネミー位置
	Vec2 m_shotEnemyPos;
	Vec2 m_shotEnemyBottomPos;

};


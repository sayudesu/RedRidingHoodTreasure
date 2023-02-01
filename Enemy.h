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

private:
	//グラフィックハンドル
	int m_handle;

	//エネミーの位置
	Vec2 m_pos;
	Vec2 m_vec;
	//エネミーのサイズ
	Vec2 m_size;
	Vec2 m_sizeBottom;
};


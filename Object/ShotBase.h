#pragma once
#include "Vec2.h"
//ショットの基底クラス
class ShotBase
{
public:
	ShotBase ();
	~ShotBase();

	virtual void Init  ();
	virtual void Update();
	virtual void Draw  ();

	//virtual void SetHandle(int handle) {};
	virtual void Start    (Vec2 pos);
	virtual void SetRad(float rad) { m_rad = rad; }
	// 情報取得
	Vec2 getPos ()const { return m_pos; }
	Vec2 getSize()const { return m_size; }

	bool isExist()const { return m_isExist; }

public:
	void OutSide();

protected:
	bool m_isExist;

	float m_rad;

	Vec2 m_posSave;

	Vec2 m_pos;

	Vec2 m_vec;

	Vec2 m_size;
};


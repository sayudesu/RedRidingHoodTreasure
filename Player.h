#pragma once
#include "Vec2.h"

class Player
{
public:
	Player();
	virtual ~Player();


	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

	bool FieldJudgement();

	void SetHandle(int handle) { m_hPlayer = handle; }

private:

	void UpdateMove();

private:

	//グラフィックハンドル
	int m_hPlayer;
	//プレイヤーグラフィックサイズ
	Vec2 m_playerSize;
	//キャラクターの位置
	Vec2 m_pos;
	Vec2 m_underPos;
	//方向
	Vec2 m_vec;

	void (Player::* m_func)();
};


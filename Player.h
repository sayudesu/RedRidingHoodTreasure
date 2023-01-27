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

public:

	//画像
	void SetHandle(int handle) { m_hPlayer = handle; }

private:

	//操作
	void Operation();
	//地面判定
	int FieldJudgement();
	//梯子判定
	int CheckHit();

private:

	void UpdateMove();

	void MenuStop();

private:

	//グラフィックハンドル
	int m_hPlayer;
	//重力
	float m_gravity;
	//階段判定
	bool m_isFloorOne;
	//梯子判定
	bool m_isLadder;
	//プレイヤーグラフィックサイズ
	Vec2 m_playerSize;
	//キャラクターの位置
	Vec2 m_pos;
	Vec2 m_underPos;
	//方向
	Vec2 m_vec;
	
	void (Player::* m_func)();
};


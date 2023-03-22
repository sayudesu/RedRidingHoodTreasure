#pragma once
#include "game.h"
#include "Vec2.h"
class DeadDirection
{
public:
	DeadDirection();
	~DeadDirection();

	void Update();
	void DrawPlayerDead();
	void Draw();
private:
	int m_hPlayer;//プレイヤーの画像チップ
	int m_hPlayerDead;//プレイヤーが死んでいる画像だけ
	int m_hEffectScreen;//画面ハンドル
	int m_snowCount;//雪が落ちるタイミング
	int m_snowDrop;//雪が落ちる数

	//画像位置

	Vec2 m_snowPos[Dead::kSnowNum];//雪の位置
};


#pragma once
#include "Vec2.h"

class Enemy;
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
	void SetHandleIdle(int handle) { m_hPlayerIdle = handle; }
	void SetHandleLighting(int handle) { m_hPlayerLighting = handle; }

private:

	//操作
	void Operation();
	//状態
	void Condition();
	//地面判定
	int FieldJudgement();
	//梯子判定
	int CheckHit();
	//アイテムボックス判定
	void BoxJudgement();
	//落下判定
	void CheckFall();
	//敵との当たり判定
	bool EnemyHit();
	//HP管理
	void HealthControl();

private:

	void UpdateMove();

	void MenuStop();

private:

	//グラフィックハンドル
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	//キャラクター画像位置
	int m_charaImagePos;
	int m_charaImageIdlePos;
	int m_charaImageAttackPos;
	int m_charaImageDamagePos;
	//アイテムボックスサイズ位置
	int m_boxPosX;
	int m_boxPosY;
	int m_boxPosBottomX;
	int m_boxPosBottomY;
	//プレイヤー体力
	int m_playerHealthBer;
	int m_playerHealthBerCount;
	//アイテムボックスドロップ
	int m_boxDropCount;
	//フレームカウント
	int m_frameCount;
	//現在何階にいるか
	int m_hierarchy;
	//重力
	float m_gravity;
	//アニメーション
	bool m_isRunMoveLeft;
	bool m_isRunMoveRight;
	bool m_isIdleMove;
	bool m_isAttackMove;
	bool m_isDamageMove;
	//アイテム武器
	bool m_isGetSword;
	//階段判定
	bool m_isFloorOne;
	//梯子判定
	bool m_isLadder;
	//下に移動できない
	bool m_isInvaliDown;
	//キャラクターの向き
	bool m_isCharaDirection;
	bool m_isCharaIdleDirection;
	//プレイヤーグラフィックサイズ
	Vec2 m_playerSize;
	//キャラクターの位置
	Vec2 m_pos;
	//画像用キャラクター位置調整
	Vec2 m_imagePos;
	Vec2 m_imageBalancePos;
	Vec2 m_underPos;
	//方向
	Vec2 m_vec;
	
	void (Player::* m_func)();
	Enemy* m_pEnemy;
};


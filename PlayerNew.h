#pragma once
#include "Vec2.h"

class PlayerNew
{
public:
	PlayerNew();
	virtual ~PlayerNew();

	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

public:

	void SetHandle         (int handle) { m_hPlayer         = handle; }
	void SetHandleIdle     (int handle) { m_hPlayerIdle     = handle; }
	void SetHandleLighting (int handle) { m_hPlayerLighting = handle; }
	void SetHandleHealthBer(int handle) { m_hHealthBer      = handle; }

	float GetPlayerLeft  () { return static_cast<float>(m_playerLeft  ); }
	float GetPlayerTop   () { return static_cast<float>(m_playerTop   ); }
	float GetPlayerRight () { return static_cast<float>(m_playerRight ); }
	float GetPlayerBottom() { return static_cast<float>(m_playerBottom); }

	//Vec2 GetPos() { return m_pos; }

	//void GetGravity (bool gravity)   { m_isGravity = gravity;   }//地面にいるかどうか
	void GetPos     (float pos)      { m_getPos    = pos;       }//地面にいる場合の座標.y
	void GetLadder  (bool ladderHit) { m_isLadder  = ladderHit; }//梯子に当たっているかどうか
	void GetScaffold(bool fall)      { m_isFall    = fall;      }//地面にいるかどうか

private:
	//操作
	void Operation();
private:

	//更新画面
	void UpdateMove();

private:

	//グラフィックハンドル
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hHealthBer;
	//マップ用グラフィックハンドル
	int m_hMapFirst;
	int m_hMapSecond;
	int m_hMapThird;
	int m_hMapFourth;
	int m_hMapFifth;
	int m_hMapChip;
	int m_hMapChipSecond;
	//プレイヤー判定用
	int m_playerLeft;
	int m_playerTop;
	int m_playerRight;
	int m_playerBottom;
	//キャラクター画像位置
	int m_charaImagePos;
	int m_charaImageIdlePos;
	int m_charaImageAttackPos;
	int m_charaImageDamagePos;
	int m_charaImageJumpPos;
	int m_charaImageCrouching;
	//はしご
	int m_count;
	//アイテムボックスサイズ位置
	int m_boxPosX;
	int m_boxPosY;
	int m_boxPosBottomX;
	int m_boxPosBottomY;
	//アイテムボックスの演出
	int m_stagingBoxX;
	int m_stagingBoxY;
	int m_stagingBoxBottomX;
	int m_stagingBoxBottomY;
	//プレイヤー体力
	int m_playerHealthBer;
	int m_playerHealthBerCount;
	int m_playerHealthSizeX;
	int m_playerHealthSizeY;
	//アイテムボックスドロップ
	int m_boxDropCount;
	//フレームカウント
	int m_frameCount;
	//現在何階にいるか
	int m_hierarchy;
	//説明用
	int m_tip;
	//重力
	float m_gravity;
	//アニメーション
	bool m_isRunMoveLeft;
	bool m_isRunMoveRight;
	bool m_isIdleMove;
	bool m_isAttackMove;
	bool m_isDamageMove;
	bool m_isJumpMove;
	bool m_isCrouchingMove;
	//HP
	bool m_isHealthBer;
	bool m_isDead;
	//死んだ場合
	bool m_isReset;
	bool m_isTitle;
	//アイテム武器
	bool m_isGetSword;
	bool m_isItemDrop;
	//攻撃判定
	bool m_isAttack;
	bool m_isEnemyDead;
	//ストップ
	bool m_isStopMove;
	//階段判定
	bool m_isFloorOne;
	//梯子判定
	bool m_isLadder;
	//下に移動できない
	bool m_isInvaliDown;
	//キャラクターの向き
	bool m_isCharaDirection;
	bool m_isCharaIdleDirection;
	//ステージクリア判定
	bool m_isStageClear;
	bool m_isMenu;
	//ゲームヒント
	bool m_isItemTip;
	bool m_isItemDropTip;
	bool m_isUpTip;

	bool m_isGravity;
	bool m_isFall;
	//プレイヤーグラフィックサイズ
	Vec2 m_playerSize;
	//キャラクターの位置
	Vec2 m_pos;
	//画像用キャラクター位置調整
	Vec2 m_imagePos;
	Vec2 m_imageBalancePos;
	Vec2 m_underPos;
	//プレイヤー攻撃範囲
	Vec2 m_attackPos;
	Vec2 m_attackBottomPos;
	//方向
	Vec2 m_vec;

	float m_getPos;

	void (PlayerNew::* m_func)();

};

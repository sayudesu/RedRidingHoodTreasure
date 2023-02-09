#pragma once
#include "Vec2.h"

class SceneResult;
class SceneMain;
class Enemy;

class PlayerMapMove
{
public:
	PlayerMapMove();
	virtual ~PlayerMapMove();

	virtual void Init();
	virtual void End();

	virtual void Update();
	virtual void Draw();

public:
	bool IsDead      () { return m_isReset;     }
	bool IsTitle     () { return m_isTitle;     }
	bool GetLifeEnemy() { return m_isEnemyDead; }

	int GetPlayerLeft  () { return m_playerLeft;   }
	int GetPlayerRight () { return m_playerRight;  }
	int GetPlayerTop   () { return m_playerTop;    }
	int GetPlayerBottom() { return m_playerBottom; }

	bool GetStageClear() { return m_isStageClear; }
public:

	//画像
	void SetHandle         (int handle) { m_hPlayer         = handle; }
	void SetHandleIdle     (int handle) { m_hPlayerIdle     = handle; }
	void SetHandleLighting (int handle) { m_hPlayerLighting = handle; }
	void SetHandleHealthBer(int handle) { m_hHealthBer      = handle; }

	void SetHandleMapFirst (int handle) { m_hMapFirst = handle;  }
	void SetHandleMapSecond(int handle) { m_hMapSecond = handle; }
	void SetHandleMapThird (int handle) { m_hMapThird = handle;  }
	void SetHandleMapFourth(int handle) { m_hMapFourth = handle; }
	void SetHandleMapFifth (int handle)  { m_hMapFifth = handle; }

	void SetHnadleMapChip(int handle) { m_hMapChip = handle; }
	void SetHnadleMapChipSecond(int handle){ m_hMapChipSecond = handle; }

	

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
	//敵との当たり判定
	bool EnemyHit();
	//敵との攻撃当たり判定
	bool AttackHit();
	//ゴール判定
	bool CheckGoal();
	//HP管理
	void HealthControl();

	//マップを表示
	void DrawMap();

private:

	//更新画面
	void UpdateMove();
	//ポーズ画面
	void MenuStop();
	//死んだ場合
	void DeathMenu();
	//ステージクリア
	void Goal();

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
	
	void (PlayerMapMove::* m_func)();
	Enemy* m_pEnemy;
};


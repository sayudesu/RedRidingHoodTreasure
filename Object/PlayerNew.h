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

	//画像
	void SetHandle         (int handle) { m_hPlayer = handle;         }
	void SetHandleIdle     (int handle) { m_hPlayerIdle = handle;     }
	void SetHandleLighting (int handle) { m_hPlayerLighting = handle; }
	void SetHandleHealthBer(int handle) { m_hHealthBer = handle;      }

	//プレイヤーの座標
	float GetPlayerLeft  () { return static_cast<float>(m_playerLeft);   }
	float GetPlayerTop   () { return static_cast<float>(m_playerTop);    }
	float GetPlayerRight () { return static_cast<float>(m_playerRight);  }
	float GetPlayerBottom() { return static_cast<float>(m_playerBottom); }
	//プレイヤーのスコア判定座標
	float GetScoreLeft  () { return static_cast<float>(m_scoreLeft);   }
	float GetScoreTop   () { return static_cast<float>(m_scoreTop);    }
	float GetScoreRight () { return static_cast<float>(m_scoreRight);  }
	float GetScoreBottom() { return static_cast<float>(m_scoreBottom); }

	//プレイヤーの座標
	float GetAttackPlayerLeft  () { return static_cast<float>(m_attackPlayerLeft  ); }
	float GeAttacktPlayerTop   () { return static_cast<float>(m_attackPlayerTop   ); }
	float GetAttackPlayerRight () { return static_cast<float>(m_attackPlayerRight ); }
	float GetAttackPlayerBottom() { return static_cast<float>(m_attackPlayerBottom); }

	bool GetGameClear() { return m_isStageClearChangeScene; }//ゲームクリアフラグ
	bool GetGameOver () { return m_isDead;                  }//ゲームオーバーフラグ

	//Vec2でのプレイヤー座標
	Vec2 GetkPlayerPos() { return m_pos; }

	//プレイヤーの状態
	void GetPos			   (float pos     ) { m_getPos         = pos;       }//地面にいる場合の座標.y
	void GetLadder		   (bool ladderHit) { m_isLadder       = ladderHit; }//梯子に当たっているかどうか
	void GetScaffold	   (bool fall     ) { m_isFall         = fall;      }//地面にいるかどうか
	void GetGoal		   (bool goal     ) { m_isStageClear   = goal;      }//ステージクリア
	void GetEnemyHit	   (bool hit      ) { m_isDamage       = hit;       }//敵に当たる
	void GetEnemyFallenHit (bool hit      ) { m_isDamageFallen = hit;       }//敵に当たる
	void GetPlayerHit	   (bool attack   ) { m_isAttackHit    = attack;    }//敵に攻撃を与える
	void GetEnemyChageHit  (bool attack   ) { m_isDamageCharge = attack;    }//チャージエネミーから攻撃を受ける
	void GetEnemyChageBlink(bool blink    ) { m_isRushBlink    = blink;     }//チャージエネミーから攻撃を受ける

	void GetScore(int score) { m_score = score; }//スコア判定
private:
	void Animation();//アニメーション再生
private:
	//プレイヤー位置補正
	void PlayerPosSet();
	//操作
	void Operation        ();//操作全体
	void OperationStandard();//基本操作
	void OperationAttack  ();//攻撃操作
	void OperationJump    ();//ジャンプ
	void OperationLadder  ();//梯子での操作

	void Score();//スコア計算
private:

	//更新画面
	void UpdateMove();
	//死亡処理
	void UpdateDead();

private:

	//グラフィックハンドル
	int m_hPlayer;
	int m_hPlayerIdle;//何もしていない状態
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
	//サウンドハンドル
	int m_hFxJump;
	int m_hRun;
	int m_hLadder;
	int m_hAttack;
	int m_hDead;
	//カウント
	int m_CountLadderSound;//梯子を上る音を再生するフレームカウント
	int m_CountRunSound;//足音を再生するフレームカウント
	//操作用
	int m_padInput;
	//プレイヤー判定用
	int m_playerLeft;
	int m_playerTop;
	int m_playerRight;
	int m_playerBottom;
	//プレイヤースコア判定
	int m_scoreLeft;
	int m_scoreTop;
	int m_scoreRight;
	int m_scoreBottom;
	int m_score;//スコア計算
	//プレイヤー攻撃範囲判定用
	int m_attackPlayerLeft;
	int m_attackPlayerTop;
	int m_attackPlayerRight;
	int m_attackPlayerBottom;
	//キャラクター画像位置
	int m_charaImagePos;
	int m_charaImageIdlePos;
	int m_charaImageAttackPos;
	int m_charaImageDamagePos;
	int m_charaImageJumpPos;
	int m_charaImageCrouching;
	//プレイヤー画像での位置
	int m_charaImageLeft;
	int m_charaImageTop;
	int m_charaImageRigth;
	int m_charaImageBottom;
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
	int m_frameCount1;
	int m_frameCount2;
	int m_frameCount3;
	//現在何階にいるか
	int m_hierarchy;
	//説明用
	int m_tip;
	//重力
	float m_gravity;
	//アニメーション
	bool m_isRunMove;
	bool m_isStopMove;
	bool m_isIdleMove;
	bool m_isAttackMove;
	bool m_isDamageMove;
	bool m_isJumpMove;
	bool m_isCrouchingMove;
	//アニメーション再生画像位置
	bool m_isRunImagePos;//走っている
	bool m_isJumpImagePos;//ジャンプしている
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
	bool m_isLadderNow;//今梯子に触っているか
	//下に移動できない
	bool m_isInvaliDown;
	//キャラクターの向き
	bool m_isCharaDirection;
	bool m_isCharaIdleDirection;
	//ステージクリア判定
	bool m_isStageClear;
	
	//ゲームクリアシーン切り替え条件 true = クリア/false = 未クリア
	bool m_isStageClearChangeScene;

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

	bool m_isDamage;
	bool m_isDamageFallen;
	bool m_isAttackHit;
	bool m_isDamageCharge;
	bool m_isRushBlink;

	void (PlayerNew::* m_func)();

};

#include "SceneMain.h"
#include "SceneResult.h"
#include "Player.h"
#include "Enemy.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"

namespace
{
	//プレイヤーの初期座標
	constexpr float kPosX = 100.0f;//20.0f;
	constexpr float kPosY = 0.0f;//700.0f;
	//動く速さ
	constexpr float kMoveSpeed = 7.0f;
	// ジャンプ力
	constexpr float kJump = -15.0f;
	// 重力
	constexpr float kGravity = 1.0f;

	//地面の高さY軸
	constexpr int kGround = 700;

	constexpr int kCharaImageLeftPos = -112; //左移動
	constexpr int kCharaImageRightPos = 112; //右移動

	//アニメーションフレーム数
	constexpr int kAnimationFrame = 3;

	////////////////////
	///*地面　２座標*///
	////////////////////
	constexpr int kGroundSecondX = Game::kScreenWidth / 2;
	constexpr int kGroundSecondY = 520;
	constexpr int kGroundSecondBottomX = Game::kScreenWidth;
	constexpr int kGroundSecondBottomY = kGroundSecondY + 20;

	///////////////////////
	///*2階から落下判定*///
	///////////////////////
	constexpr int kFallBoxX = 0;
	constexpr int kFallBoxY = 450;
	constexpr int kFallBoxBottomX = Game::kScreenWidth / 2 - 40;
	constexpr int kFallBoxBottomY = kFallBoxY + 80;


	////////////////////
	///*はしご１座標*///
	////////////////////
	constexpr int kLadderX = Game::kScreenWidth - 120;
	constexpr int kLadderY = 500;
	constexpr int kLadderXBottom = Game::kScreenWidth - 90;
	constexpr int kLadderYBottom = Game::kScreenHeight - 70;

	///////////////////////
	///*アイテムボックス*///
	///////////////////////

	constexpr int kBoxPosX = 200;
	constexpr int kBoxPosY = 550;
	constexpr int kBoxPosBottomX = 200 + 50;
	constexpr int kBoxPosBottomY = 550 + 50;

}
Player::Player() :
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hHealthBer(-1),
	m_charaImagePos(0),
	m_charaImageIdlePos(0),
	m_charaImageAttackPos(0),
	m_charaImageDamagePos(0),
	m_charaImageJumpPos(0),
	m_charaImageCrouching(0),
	m_boxPosX(0),
	m_boxPosY(0),
	m_boxPosBottomX(0),
	m_boxPosBottomY(0),
	m_stagingBoxX(0),
	m_stagingBoxY(0),
	m_stagingBoxBottomX(0),
	m_stagingBoxBottomY(0),
	m_playerHealthBer(0),
	m_playerHealthBerCount(0),
	m_playerHealthSizeX(0),
	m_playerHealthSizeY(0),
	m_boxDropCount(0),
	m_frameCount(0),
	m_hierarchy(0),
	m_gravity(0.0f),
	m_isRunMoveLeft(false),
	m_isRunMoveRight(false),
	m_isIdleMove(false),
	m_isAttackMove(false),
	m_isDamageMove(false),
	m_isJumpMove(false),
	m_isCrouchingMove(false),
	m_isHealthBer(false),
	m_isGetSword(false),
	m_isItemDrop(false),
	m_isFloorOne(false),
	m_isLadder(false),
	m_isInvaliDown(false),
	m_isCharaDirection(false),
	m_isCharaIdleDirection(false),
	m_playerSize(0.0f, 0.0f),
	m_pos(0.0, 0.0),
	m_imagePos(0.0, 0.0),
	m_imageBalancePos(0.0, 0.0),
	m_underPos(0.0, 0.0),
	m_vec(0.0, 0.0),
	m_pEnemy(nullptr),
	m_pSceneResult(nullptr)
{
	m_charaImagePos = (1344 - kCharaImageRightPos);
	m_func = &Player::UpdateMove;
	m_pEnemy = new Enemy;
}
Player::~Player()
{
	delete m_pEnemy;
	delete m_pSceneResult;
}
//初期化
void Player::Init()
{
	m_hierarchy = 1;
	m_playerHealthBer = 100;

	m_boxDropCount = 120;

	m_boxPosX = kBoxPosX;
	m_boxPosY = kBoxPosY;
	m_boxPosBottomX = kBoxPosBottomX;
	m_boxPosBottomY = kBoxPosBottomY;

	m_pos.x = kPosX;
	m_pos.y = kPosY;

	m_underPos.x = m_pos.x + 50;
	m_underPos.y = m_pos.y + 100;

	m_gravity = kGravity;

	GetGraphSizeF(m_hPlayer, &m_playerSize.x, &m_playerSize.y);
}
void Player::End()
{

}
//アップデート処理
void Player::Update()
{
	m_pEnemy->Update();

	(this->*m_func)();
}
//描画
void Player::Draw()
{
	//////////////////////////////////////
	//*地面は下から順番に数えていきます*//
	//////////////////////////////////////
	
	//地面2
	DrawBox(kGroundSecondX, kGroundSecondY,
		kGroundSecondBottomX, kGroundSecondBottomY, 0x00ff00,false);

	//梯子1
	DrawBox(kLadderX, kLadderY, kLadderXBottom, kLadderYBottom, 0xff0000, true);
	//     　 left,  　　top,  　　 right,   　　　bottom,
	//地面１
	DrawBox(0, 700, Game::kScreenWidth + 1, kGround + 20 + 1, 0x00ff00, false);
	
	
	if(!m_isGetSword)
	{
		if (m_boxDropCount < 120)
		{
			m_stagingBoxX = GetRand(10), m_stagingBoxY = GetRand(10);
			m_stagingBoxBottomX = GetRand(10), m_stagingBoxBottomY = GetRand(10);
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, GetRand(255));
		}
		else
		{
			m_stagingBoxX = 0;
			m_stagingBoxY = 0;
			m_stagingBoxBottomX = 0;
			m_stagingBoxBottomY = 0;
		}
		DrawBox(m_boxPosX + m_stagingBoxX, m_boxPosY + m_stagingBoxY, m_boxPosBottomX + m_stagingBoxBottomX, m_boxPosBottomY + m_stagingBoxBottomY, 0x00ff00, true);//アイテムボックス
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	DrawLine(Game::kScreenWidth / 2, 520, Game::kScreenWidth, 520, 0xffffff);//2
	DrawLine(0, kGround, Game::kScreenWidth, kGround, 0xffffff);//1

	//体力の量表示
	if(!m_isHealthBer)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 230);
		DrawBox(m_pos.x - 35, m_pos.y - 30, m_pos.x - 35 + 75, m_pos.y - 30 + 10, 0xff0000, true);
		DrawExtendGraph(m_pos.x - 35, m_pos.y - 30, m_playerHealthSizeX + m_pos.x - 35 + 75, m_playerHealthSizeY + m_pos.y - 30 + 10,m_hHealthBer,true);
		DrawBox(m_pos.x - 35, m_pos.y - 30, m_pos.x - 35 + 75, m_pos.y - 30 + 10, 0xffffff, false);
		//DrawExtendGraph(m_pos.x - 35, m_pos.y - 30,0 + m_pos.x - 35 + 75, m_playerHealthSizeY + m_pos.y - 30 + 10, m_hHealthBer, false);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	//DrawExtendGraph(100, 100, 100 + 130 * 200, 480 * 200, m_hHealthBer, false);
	
	//DrawRotaGraph(m_pos.x -100000000, m_pos.y + 20 + GetRand(5), 30000, 0, m_playerHealthBer, true, false);

	//キャラクター
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	for (int i = 0; i < 4; i++)
	{
		DrawRotaGraph(m_pos.x - 3 + GetRand(5), m_pos.y + 20 + GetRand(5), 3, 0, m_hPlayerLighting, true, false);
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	if (m_isIdleMove && !m_isAttackMove && !m_isDamageMove && !m_isJumpMove && !m_isCrouchingMove)//何もしない
	{

		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + static_cast<int>(m_imageBalancePos.x),
			static_cast<int>(m_imagePos.y) + static_cast<int>(m_imageBalancePos.y),
			m_charaImageIdlePos, 0, 80, 80, 2, 0, m_hPlayerIdle, true, m_isCharaIdleDirection);

	}
	else if (m_isRunMoveRight && !m_isAttackMove || m_isRunMoveLeft && !m_isAttackMove && !m_isDamageMove && !m_isJumpMove && !m_isCrouchingMove)//走る
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x), static_cast<int>(m_imagePos.y),
			m_charaImagePos, 133, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//剣攻撃
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageAttackPos, 1197, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isDamageMove && !m_isCrouchingMove)//攻撃を受けたら
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageDamagePos, 1330, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}
	if (m_isJumpMove && !m_isCrouchingMove)//ジャンプをしたら
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageJumpPos, 399, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}

	if(m_isCrouchingMove)
	{
		DrawRectRotaGraph(static_cast<int>(m_imagePos.x) + 0,
			static_cast<int>(m_imagePos.y) + 0,
			m_charaImageCrouching, 532, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);
	}


	if (m_isDead)
	{
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		DrawBox(350, 200, 300 + 600, 200 + 300, 0x0000ff, true);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		DrawBox(350,200,300 + 600,200 + 300,0xffffff,false);
		DrawString(Game::kScreenWidth / 2 - 100, Game::kScreenHeight / 2 - 100, "あなたは死にました", 0xff0000);
		DrawString(Game::kScreenWidth / 2 - 200, Game::kScreenHeight / 2  - 30, "受け入れる", 0xffffff);
		DrawString(Game::kScreenWidth / 2 + 50, Game::kScreenHeight / 2 - 30, "受け入れない", 0xffffff);
	}


	DrawString(0, 0, "ゲームプレイ", 0xffffff);


	////////////////////
	///*判定の確認用*///
	////////////////////
#if false	
	//キャラクター
	DrawBox(m_pos.x - 25, m_pos.y - 10, m_pos.x + 25, m_pos.y + 60, 0xff0000, false);

	//２階から落ちる範囲
	DrawBox(kFallBoxX, kFallBoxY, kFallBoxBottomX, kFallBoxBottomY, 0xf000f0, false);
	//printfDx("%f\n", m_pos.y);
	printfDx("%d\n", m_playerHealthBer);

#endif
}
//操作
void Player::Operation()
{
	//入力判定
	Pad::update();

	m_isCrouchingMove = false;
	m_isRunMoveRight = false;//右に動いているかどうか
	m_isRunMoveLeft = false;//左に動いているかどうか
	m_isIdleMove = true;//動いているかどうか

	//移動
	if (CheckHitKey(KEY_INPUT_RIGHT) && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//右
	{
		m_pos.x += kMoveSpeed;
		m_underPos.x += kMoveSpeed;
		m_isCharaDirection = true;//画像反転
		m_isRunMoveRight = true;
		m_isIdleMove = false;
		m_isCharaIdleDirection = false;
	}
	if (CheckHitKey(KEY_INPUT_LEFT) && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//左
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
		m_isCharaDirection = false;//画像反転
		m_isRunMoveLeft = true;
		m_isIdleMove = false;
		m_isCharaIdleDirection = true;
	}

	//アップダウン
	if (CheckHitKey(KEY_INPUT_UP) && CheckHit() == 1 && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)//梯子上り
	{
		m_vec.y = 0.0f;
		m_pos.y -= kMoveSpeed;
		m_isIdleMove = false;
	
	} 
	if(!m_isInvaliDown && !m_isAttackMove && !m_isDamageMove && !m_isCrouchingMove)
	{
		if (CheckHitKey(KEY_INPUT_DOWN) && CheckHit() == 1)//梯子下り
		{
			m_vec.y = 0.0f;
			m_pos.y += kMoveSpeed;
			m_isIdleMove = false;
		}
	}

	//ジャンプ
	if (Pad::isTrigger(KEY_INPUT_UP) && CheckHit() == 0 && !m_isAttackMove && !m_isDamageMove)//上
	{
		if (FieldJudgement() == 1 ||
			FieldJudgement() == 2)//地面にいる状態の場合
		{
			//printfDx("ジャンプ\n");
			m_vec.y = kJump;//ジャンプ開始
			m_isJumpMove = true;
			//m_isIdleMove = false;
		}
	}

	if (CheckHitKey(KEY_INPUT_DOWN))
	{
		m_isCrouchingMove = true;
	}

	//攻撃
	if(m_isGetSword && !m_isDamageMove && !m_isCrouchingMove)
	{
		if(CheckHitKey(KEY_INPUT_V))
		{
			m_isAttackMove = true;
		}
	}

	//ポーズメニュー
	if (CheckHitKey(KEY_INPUT_P))
	{
		m_func = &Player::MenuStop;
	}
		
}
//アニメーション
void Player::Condition()
{	

	if (m_isCharaIdleDirection)
	{
		m_imageBalancePos.x = -20;
		m_imageBalancePos.y = 20;
	}
	else
	{
		m_imageBalancePos.x = 20;
		m_imageBalancePos.y = 20;
	}

	//アイドル状態
	if(m_isIdleMove)
	{
		m_frameCount++;
		if(m_frameCount >= kAnimationFrame)
		{
			m_charaImageIdlePos += 80;
			m_frameCount = 0;
		}
		if (m_charaImageIdlePos == 1440)
		{
			m_charaImageIdlePos = 0;
		}
	}
	
	//右に移動アニメーション
	if(m_isRunMoveRight)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImagePos -= kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 0)
		{
			m_charaImagePos = (1344 - kCharaImageRightPos);
		}
	}

	//左に移動アニメーション
	if(m_isRunMoveLeft)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImagePos -= kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 0)
		{
			m_charaImagePos = (1344 - kCharaImageRightPos);
		}
	}

	//攻撃を受けた場合
	if (m_isDamageMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageDamagePos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if(m_charaImageDamagePos == kCharaImageRightPos * 7)
		{
			m_charaImageDamagePos = 0;
	
			m_isDamageMove = false;

		}
	}

	//ジャンプした場合
	if (m_isJumpMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageJumpPos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImageJumpPos == kCharaImageRightPos * 12)
		{
			m_charaImageJumpPos = 0;

			if (FieldJudgement() == 1 || FieldJudgement() == 2)
			{
				m_isJumpMove = false;
			}
		}
	}

	if (m_isCrouchingMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageCrouching += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImageCrouching >= kCharaImageRightPos)
		{
			m_charaImageCrouching = kCharaImageRightPos;
	
		}
	}
	else
	{
		m_isCrouchingMove = false;
	}

	//攻撃アニメーション（剣）
	if (m_isAttackMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImageAttackPos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImageAttackPos >= 1344)
		{
			m_charaImageAttackPos = 0;
			m_isAttackMove = false;//攻撃をしているかどうか
		}
	}
	else
	{
		m_charaImageAttackPos = 0;
	}

}
//地面との判定
int Player::FieldJudgement()
{
	m_isInvaliDown = false;

	if (CheckHit() == 1)//梯子の判定
	{
		return 0;
	}

	if(m_hierarchy == 1)
	{
		if(m_pos.y >= kGround - 60 - m_playerSize.y)//地面に着地
		{
			m_pos.y = kGround - 60 - m_playerSize.y;
			m_isInvaliDown = true;//地面にいる場合ジャンプ可能

			return 1;
		}
	}
	
	//２階に来たら作動する	
	if (m_hierarchy == 2)
	{
		if (m_pos.y >= 520 - 60 - m_playerSize.y)//地面2
		{
			m_pos.y = 520 - 60 - m_playerSize.y;
			return 2;
		}
	}

	return 0;
}
//キャラクターとはしごの判定
int Player::CheckHit()
{

	if ((kLadderXBottom > m_pos.x - 25) &&
		(kLadderX < m_pos.x + 25))
	{
		if ((kLadderYBottom > m_pos.y - 10) &&
			(kLadderY < m_pos.y + 60))
		{
			m_isFloorOne = true;

			if (static_cast<int>(m_pos.y) <= 680)
			{
				m_hierarchy = 1;
			}
			if (static_cast<int>(m_pos.y) <= 580)
			{
				m_hierarchy = 2;
			}

			return 1;
		}
	}
	m_isFloorOne = false;
	return 0;
}
//アイテムボックスの判定
void Player::BoxJudgement()
{
	if ((m_boxPosBottomX > m_pos.x - 25) &&
		((m_boxPosX < m_pos.x + 25)))
	{
		if ((m_boxPosBottomY > m_pos.y - 10) &&
			(m_boxPosY < m_pos.y + 60))
		{
			//printfDx("ボックス判定\n");
			m_isItemDrop = true;
			if (m_boxDropCount >= 120)
			{
				m_isGetSword = true;//アイテムボックス非表示
				m_boxDropCount = 0;

			}

		}
	}

}
//下に落ちる判定
void Player::CheckFall()
{
	if ((kFallBoxBottomX > m_pos.x - 25) &&
		(kFallBoxX < m_pos.x + 25))
	{
		if ((kFallBoxBottomY > m_pos.y - 10) &&
			(kFallBoxY < m_pos.y + 60))
		{
			m_hierarchy = 1;
		}
	}
}
//敵とプレイヤーの判定
bool Player::EnemyHit()
{
	if ((m_pEnemy->GetSizeBottom().x > m_pos.x - 25) &&
		(m_pEnemy->GetSize().x < m_pos.x + 25))
	{
		if ((m_pEnemy->GetSizeBottom().y > m_pos.y - 10) &&
			(m_pEnemy->GetSize().y < m_pos.y + 60))
		{
			if (m_isGetSword)
			{

				m_boxPosX = m_pos.x;
				m_boxPosY = m_pos.y - 80;
				m_boxPosBottomX = m_boxPosX + 50;
				m_boxPosBottomY = m_boxPosY + 50;

				m_isGetSword = false;//アイテムボックスドロップ
			}

			m_isDamageMove = true;//ダメージアニメーション再生
			return true;
		}
	}
	return false;
}
//プレイヤーの体力を管理
void Player::HealthControl()
{
	m_playerHealthBerCount += 1;
	if (m_playerHealthBerCount == 1)
	{
		m_playerHealthBer -= 20;
		m_playerHealthSizeX -= 20;
	}

	if (m_playerHealthBer <= 0)
	{
		m_playerHealthBer = 1;
		printfDx("死亡\n");
		m_playerHealthSizeX = 0;
		m_isHealthBer = true;
		//ポーズメニュー

		m_func = &Player::DeathMenu;
		
	}
	
}
//アップデート処理
void Player::UpdateMove()
{	
	//printfDx("%f\n", m_pEnemy->GetSize().x);
	if(CheckHit() == 0)
	{
		//重力
		m_vec.y += m_gravity;	
	}

	//プレイヤー位置
	m_imagePos = m_pos;
	m_pos += m_vec;
	m_underPos += m_vec;

	////////////////////
	////*当たり判定*////
	///////////////////
	//はしご
	CheckHit();
	////地面
	FieldJudgement();
	//アイテム
	BoxJudgement();
	if (!m_isGetSword)
	{
		m_boxDropCount++;
	}
	if (m_boxDropCount >= 120)
	{
		m_boxDropCount = 120;
	}
	//敵との当たり判定
	EnemyHit();
	if(!m_isHealthBer)
	{
		if(EnemyHit())
		{
			//m_boxDropCount++;
			HealthControl();
		}
		else
		{
			m_playerHealthBerCount = 0;
		}
	}

	//落ち
	CheckFall();
	//操作
	Operation();
	//状態（動き）
	Condition();
}
//ポーズ画面
void Player::MenuStop()
{
	printfDx("ポーズ中\n");
	if (CheckHitKey(KEY_INPUT_O))
	{
		m_func = &Player::UpdateMove;
	}
}
//死んだ場合のMenu
void Player::DeathMenu()
{
	m_isDead = true;
}



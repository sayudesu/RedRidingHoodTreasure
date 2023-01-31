#include "SceneMain.h"
#include "Player.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"

namespace
{
	//プレイヤーの初期座標
	constexpr float kPosX = 20.0f;
	constexpr float kPosY = 700.0f;
	//動く速さ
	constexpr float kMoveSpeed = 7.0f;
	// ジャンプ力
	constexpr float kJump = -15.0f;
	// 重力
	constexpr float kGravity = 1.5f;

	//地面の高さY軸
	constexpr int kGround = 750;

	constexpr int kCharaImageLeftPos = -112; //左移動

	constexpr int kCharaImageRightPos = 112; //右移動

	//constexpr int 

	////////////////////
	///*地面　２座標*///
	////////////////////
	constexpr int kGroundSecondX = Game::kScreenWidth / 2;
	constexpr int kGroundSecondY = 600;
	constexpr int kGroundSecondBottomX = Game::kScreenWidth;
	constexpr int kGroundSecondBottomY = 600 + 20;

	////////////////////
	///*はしご１座標*///
	////////////////////
	constexpr int kLadderX = Game::kScreenWidth - 120;
	constexpr int kLadderY = 580;
	constexpr int kLadderXBottom = Game::kScreenWidth - 90;
	constexpr int kLadderYBottom = Game::kScreenHeight - 70;
}

Player::Player() :
	m_hPlayer(-1),
	m_charaImagePos(0),
	m_frameCount(0),
	m_hierarchy(0),
	m_gravity(0.0f),
	m_isFloorOne(false),
	m_isLadder(false),
	m_isInvaliDown(false),
	m_isCharaDirection(false),
	m_playerSize(0.0f, 0.0f),
	m_pos(0.0, 0.0),
	m_underPos(0.0, 0.0),
	m_vec(0.0, 0.0)
{
	m_charaImagePos = (1344 - kCharaImageRightPos);
	m_func = &Player::UpdateMove;
}

Player::~Player()
{

}

void Player::Init()
{
	m_hierarchy = 1;

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

void Player::Update()
{
	(this->*m_func)();
}

void Player::Draw()
{

	//キャラクター
	DrawRectRotaGraph(m_pos.x, m_pos.y,m_charaImagePos, 133, 112, 133, 2, 0, m_hPlayer, true, m_isCharaDirection);

	//////////////////////////////////////
	//*地面は下から順番に数えていきます*//
	//////////////////////////////////////
	
	//地面2
	DrawBox(kGroundSecondX, kGroundSecondY, kGroundSecondBottomX, kGroundSecondBottomY, 0x00ff00,false);
	DrawLine(Game::kScreenWidth / 2, 600, Game::kScreenWidth, 600, 0xffffff);
	//梯子1
	DrawBox(kLadderX, kLadderY, kLadderXBottom, kLadderYBottom, 0xff0000, true);
	//     　 left,  　　top,  　　 right,   　　　bottom,
	//地面１
	DrawBox(0,kGround, Game::kScreenWidth + 1, kGround + 20 + 1, 0x00ff00, false);
	DrawLine(0, kGround, Game::kScreenWidth, kGround, 0xffffff);
	DrawPixel(Game::kScreenWidth / 2 - 150, 500, 0xffffff);

	DrawString(0, 0, "ゲームプレイ", 0xffffff);
}

void Player::Operation()
{
	//入力判定
	Pad::update();

	//移動
	if (CheckHitKey(KEY_INPUT_RIGHT))//右
	{
		m_pos.x += kMoveSpeed;
		m_underPos.x += kMoveSpeed;
		m_isCharaDirection = true;//画像反転
	}
	if (CheckHitKey(KEY_INPUT_LEFT))//左
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
		m_isCharaDirection = false;//画像反転
	}

	//アップダウン
	if (CheckHitKey(KEY_INPUT_UP) && CheckHit() == 1)//梯子上り
	{
		m_vec.y = 0.0f;
		m_pos.y -= kMoveSpeed;
	
	} 

	if(!m_isInvaliDown)
	{
		if (CheckHitKey(KEY_INPUT_DOWN) && CheckHit() == 1)//梯子下り
		{
			m_vec.y = 0.0f;
			m_pos.y += kMoveSpeed;
		
		}
	}

	//ジャンプ
	if (Pad::isTrigger(KEY_INPUT_UP) && CheckHit() == 0)//上
	{
		if (FieldJudgement() == 1 || FieldJudgement() == 2)//地面にいる状態の場合
		{
			//printfDx("ジャンプ\n");
			m_vec.y = kJump;//ジャンプ開始
		}
	}

	//ポーズメニュー
	if (CheckHitKey(KEY_INPUT_P))
	{
		m_func = &Player::MenuStop;
	}
		
}

void Player::Condition()
{
	//右に移動アニメーション
	if(m_isCharaDirection)
	{
		m_frameCount++;
		if (m_frameCount == 3)
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
	if(!m_isCharaDirection)
	{
		m_frameCount++;
		if (m_frameCount == 3)
		{
			m_charaImagePos -= kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 0)
		{
			m_charaImagePos = (1344 - kCharaImageRightPos);
		}
	}
}

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
			if(!m_isFloorOne)
			{
				m_pos.y = kGround - 60 - m_playerSize.y;
				m_isInvaliDown = true;//地面にいる場合ジャンプ可能

			}
			return 1;
		}
	}
	
	//２階に来たら作動する	
	if (m_hierarchy == 2)
	{
		if (m_pos.y >= 600 - 60 - m_playerSize.y)//地面2
		{
			m_pos.y = 600 - 60 - m_playerSize.y;
			return 2;
		}
	}
}

//キャラクターとはしごの判定
int Player::CheckHit()
{

	/// /////////////////////////////////////////////////////////////
	//ここ修正点//////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////
	if ((kLadderXBottom > m_pos.x - 25) &&
		(kLadderX < m_pos.x + 25))
	{
		if ((kLadderYBottom > m_pos.y - 10) &&
			(kLadderY < m_pos.y + 60))
		{
			m_isFloorOne = true;
			printfDx("梯子");
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

void Player::UpdateMove()
{	
	if(!m_isFloorOne)
	{
		//重力
		m_vec.y += m_gravity;	
	}
	//プレイヤー位置
	m_pos += m_vec;
	m_underPos += m_vec;
	
	////////////////////
	////*当たり判定*////
	///////////////////
	
	//はしご
	CheckHit();
	////地面
	FieldJudgement();

	//操作
	Operation();



	//////////////////////////
	/////*判定の確認用*///////
	//////////////////////////
#if true	

	if (CheckHit())
	{
		//printfDx("梯子1\n");
	}
	else if (true)
	{
		//printfDx("梯子0\n");
	}
	//キャラの中心
	DrawPixel(m_pos.x, m_pos.y, 0xffff00);
	//キャラクター
	DrawBox(m_pos.x - 25, m_pos.y - 10, m_pos.x + 25, m_pos.y + 60, 0xff0000, false);
	printfDx("%f\n", m_pos.y);
	
#endif
}

void Player::MenuStop()
{
	printfDx("ポーズ中\n");
	if (CheckHitKey(KEY_INPUT_O))
	{
		m_func = &Player::UpdateMove;
	}
}



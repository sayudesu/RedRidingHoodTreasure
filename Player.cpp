#include "SceneMain.h"
#include "Player.h"
#include <DxLib.h>
#include "Pad.h"
#include "game.h"

namespace
{
	//プレイヤーの初期座標
	constexpr float kPosX = 20.0f;
	constexpr float kPosY = 720.0f;
	//動く速さ
	constexpr float kMoveSpeed = 7.0f;
	// ジャンプ力
	constexpr float kJump = -15.0f;
	// 重力
	constexpr float kGravity = 1.5f;

	//地面の高さY軸
	constexpr int kGround = 750;

	//はしご１座標
	constexpr int kLadderX = Game::kScreenWidth - 120;
	constexpr int kLadderY = 500;
	constexpr int kLadderXBottom = Game::kScreenWidth - 80;
	constexpr int kLadderYBottom = Game::kScreenHeight - 50;
}

Player::Player() :
	m_hPlayer(-1),
	m_gravity(0.0f),
	m_isFloorOne(false),
	m_isLadder(false),
	m_playerSize(0.0f, 0.0f),
	m_pos(0.0, 0.0),
	m_underPos(0.0, 0.0),
	m_vec(0.0, 0.0)
{
	m_func = &Player::UpdateMove;
}

Player::~Player()
{

}

void Player::Init()
{
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
	DrawString(0, 0, "ゲームプレイ", 0xffffff);
	//キャラクター
	//DrawRotaGraphF(m_pos.x,m_pos.y, 0.2, DX_PI / 2, m_hPlayer, true);

	//////////////////////////////////////
	//*地面は下から順番に数えていきます*//
	//////////////////////////////////////
	
	//地面2
	DrawBox(Game::kScreenWidth / 2, 500, Game::kScreenWidth, 500 + 20, 0x00ff00,false);
	DrawLine(Game::kScreenWidth / 2, 500, Game::kScreenWidth, 500, 0xffffff);
	//はしご
	DrawBox(kLadderX, kLadderY, kLadderXBottom, kLadderYBottom, 0xff0000, true);
	//     　 left,  　　top,  　　 right,   　　　bottom,
	//地面１
	DrawBox(0,kGround, Game::kScreenWidth + 1, kGround + 20 + 1, 0x00ff00, false);
	DrawLine(0, kGround, Game::kScreenWidth, kGround, 0xffffff);
	DrawPixel(Game::kScreenWidth / 2 - 150, 500, 0xffffff);
	
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
	}
	if (CheckHitKey(KEY_INPUT_LEFT))//左
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
	}

	//アップダウン
	if (CheckHitKey(KEY_INPUT_UP) && CheckHit() == 1)//梯子上り
	{
		m_vec.y = 0.0f;
		m_pos.y -= kMoveSpeed;
	
	} 
	else if (CheckHitKey(KEY_INPUT_DOWN) && CheckHit() == 1)//梯子下り
	{
		m_vec.y = 0.0f;
		m_pos.y += kMoveSpeed;
		
	}

	//ジャンプ
	if (Pad::isTrigger(KEY_INPUT_UP) && CheckHit() == 0)//上
	{
		if (FieldJudgement() >= 1)//地面にいる状態の場合
		{
			printfDx("ジャンプ\n");
			m_vec.y = kJump;//ジャンプ開始
		}
	}


	//ポーズメニュー
	if (CheckHitKey(KEY_INPUT_P))
	{
		m_func = &Player::MenuStop;
	}
		
}
int Player::FieldJudgement()
{
	if (CheckHit() == 1)//梯子の判定
	{
		return 0;
	}

	if(m_pos.y >= kGround - m_playerSize.y - 30)//地面に着地
	{
		if(!m_isFloorOne)
		{
			m_pos.y = kGround - 30 - m_playerSize.y;
		}

		printfDx("地面1\n");
		return 1;
	}
	
	if (m_pos.y >= 500 - m_playerSize.y)//地面2
	{
		m_pos.y = 500 - 30 - m_playerSize.y;
		printfDx("地面2\n");
		return 2;
	}
	
	return 4;

	/*
	//地面1との当たり判定
	if ((Game::kScreenWidth + 1 > m_pos.x - 25.0f) &&
	    (0.0f < m_pos.x + 25.0f))
	{
		if ((kGround + 20 + 1 > m_pos.y - 25.0f) &&
			(kGround < m_pos.y + 25.0f))
		{
			
			printfDx("地面\n");

			//地面に固定
			m_pos.y = kGround - 30 - m_playerSize.y;
			//m_pos.y = kGround - 28 - m_playerSize.y;

			return 1;
		}
	}
	*/
}

//キャラクターとはしごの判定
int Player::CheckHit()
{
	if ((kLadderXBottom > m_pos.x - 25) &&
		(kLadderX < m_pos.x + 25))
	{
		if ((kLadderYBottom > m_pos.y - 25) &&
			(kLadderY < m_pos.y + 25))
		{
			m_isFloorOne = true;
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
	DrawBox(m_pos.x - 25, m_pos.y - 25, m_pos.x + 25, m_pos.y + 25, 0xff0000, false);
	
#endif
}

void Player::MenuStop()
{
	printfDx("ポーズ中\n");
}



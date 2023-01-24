#include "SceneMain.h"
#include "Player.h"
#include <DxLib.h>
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

}

Player::Player() :
	m_hPlayer(-1),
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
	DrawRotaGraphF(m_pos.x,m_pos.y, 0.2, DX_PI / 2, m_hPlayer, true);

	//////////////////////////////////////
	//*地面は下から順番に数えていきます*//
	//////////////////////////////////////
	
	//地面2
	DrawLine(Game::kScreenWidth / 2, 500, Game::kScreenWidth, 500, 0xffffff);
	//梯子１から２
	DrawLine(Game::kScreenWidth - 100, kGround, Game::kScreenWidth - 100, 500, 0xffffff);
	//地面1
	DrawLine(0, kGround, Game::kScreenWidth, kGround, 0xffffff);
}
int Player::FieldJudgement()
{
	//地面との当たり判定
	//bool isField = false;
	//地面１
	if (m_pos.y >= kGround - 30 - m_playerSize.y)
	{
		m_pos.y = kGround - 30 - m_playerSize.y;
		isField = true;
		return 1;
	}

	if (m_pos.x >= Game::kScreenWidth - 125 &&
		m_pos.x <= Game::kScreenWidth - 75 )
	{
		printfDx("判定\n");
		isField = false;
	}
	else
	{
		clsDx();
	}

	//return isField;
}

void Player::UpdateMove()
{
	//プレイヤー位置
	m_pos += m_vec;
	m_underPos += m_vec;

	//重力
	m_vec.y += kGravity;

	FieldJudgement();

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_pos.x += kMoveSpeed;
		m_underPos.x += kMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
	}

	if (CheckHitKey(KEY_INPUT_UP))
	{
		if (FieldJudgement())//地面にいる状態の場合
		{
			m_vec.y = kJump;//ジャンプ開始
		}
		else
		{
			m_pos.y = 500 - 30;
		}
	}
}

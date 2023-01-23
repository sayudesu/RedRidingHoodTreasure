#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include <DxLib.h>
#include "game.h"

namespace
{
	constexpr float kPosX = 20.0f;
	constexpr float kPosY = 650.0f;
	//動く速さ
	constexpr float kMoveSpeed = 7.0f;
	// ジャンプ力
	constexpr float kJump = -30.0f;
	// 重力
	constexpr float kGravity = 1.5f;
}

SceneMain::SceneMain():
	m_pos(0.0,0.0),
	m_underPos(0.0, 0.0),
	m_vec(0.0,0.0)
{
	m_func = &SceneMain::UpdateMove;
}

SceneMain::~SceneMain()
{

}

void SceneMain::init()
{
	m_pos.x = kPosX;
	m_pos.y = kPosY;

	m_underPos.x = m_pos.x + 50;
	m_underPos.y = m_pos.y + 100;
}
void SceneMain::end()
{

}

SceneBase* SceneMain::update()
{
	(this->*m_func)();
	return this;
}

void SceneMain::draw()
{
	DrawString(0, 0, "ゲームプレイ", 0xffffff);

	//キャラクター
	DrawBox(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		static_cast<int>(m_underPos.x), static_cast<int>(m_underPos.y),0xffffff,true);

	//地面
	DrawLine(0, 750,Game::kScreenWidth / 2, 750,0xffffff);
}

void SceneMain::UpdateMove()
{
	m_pos += m_vec;
	m_underPos += m_vec;

#if true	
	//地面との当たり判定
	bool isField = false;
	if (m_underPos.y == 750)
	{
		m_pos.y = 650.0f;
		//m_pos.y = 750 - m_underPos.y;
		isField = true;
	}
#endif

	if (CheckHitKey(KEY_INPUT_RIGHT))
	{
		m_pos.x +=kMoveSpeed;
		m_underPos.x += kMoveSpeed;
	}
	if (CheckHitKey(KEY_INPUT_LEFT))
	{
		m_pos.x -= kMoveSpeed;
		m_underPos.x -= kMoveSpeed;
	}

#if true		
	if (CheckHitKey(KEY_INPUT_UP))
	{
		if (isField)//地面にいる状態の場合
		{
			m_vec.y = kJump;	// ジャンプ開始
		}
	}

	//重力
	//m_vec.y += kGravity;
#endif
}

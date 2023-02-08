#include "Enemy.h"

#include "game.h"
#include <Dxlib.h>

namespace
{
	//アニメーションフレーム
	constexpr int kAnimationFrame = 3;

	//エネミー移動速度
	constexpr float kEnemySpeed = 6.9f;
}

Enemy::Enemy():
	m_handle(-1),
	m_eyeImagePos(0),
	m_frameCount(0),
	m_direction(false),
	m_isRunMove(false),
	m_pos(0.0f,0.0f),
	m_vec(0.0f, 0.0f),
	m_size(0.0f, 0.0f),
	m_sizeBottom(0.0f, 0.0f),
	m_sizeHit(0.0f, 0.0f),
	m_sizeBottomHit(0.0f, 0.0f),
	m_shotEnemyPos(0.0f, 0.0f),
	m_shotEnemyBottomPos(0.0f, 0.0f)
{
	m_eyeImagePos = 336;
	m_direction = false;

	m_pos.x = static_cast<float>(Game::kScreenWidth) - 150.0f;
	m_pos.y = static_cast<float>(Game::kScreenHeight) - 360.0f;

	m_shotEnemyPos.x =  20;
	m_shotEnemyPos.y = Game::kScreenHeight - 230.0f;
	m_shotEnemyBottomPos.x = m_shotEnemyPos.x + 20;
	m_shotEnemyBottomPos.y = m_shotEnemyPos.y + 20;

}

Enemy::~Enemy()
{

}

void Enemy::Init()
{
}

void Enemy::End()
{

}

void Enemy::Update()
{
	EyeEnemy();
	
}

void Enemy::Draw()
{
	//エネミー
	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		0, m_eyeImagePos, 128, 82/2, 3, 0, m_handle, true, m_direction);

	ShotEnemyDraw();
#if true	

	//エネミーの当たり判定
	DrawBox(static_cast<int>(m_size.x), static_cast<int>(m_size.y)
		, static_cast<int>(m_sizeBottom.x), static_cast<int>(m_sizeBottom.y),0xff0000, false);

	//攻撃受け範囲判定
	DrawBox(m_sizeHit.x, m_sizeHit.y
		, m_sizeBottomHit.x, m_sizeBottomHit.y, 0x0000ff, false);

#endif
}

void Enemy::SetHandle(int handle)
{
	m_handle = handle;
	//GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

void Enemy::EyeEnemy()
{
	m_pos += m_vec;

	if (m_pos.x >= Game::kScreenWidth - 150)//左に移動時の判定
	{
		m_direction = true;
		m_isRunMove = true;

		m_vec.x = -kEnemySpeed;
	}
	if (m_direction)//左に移動時の判定
	{
		m_size.x = m_pos.x + 80 + 10;
		m_size.y = m_pos.y;

		m_sizeBottom.x = m_size.x + 45 - 20;
		m_sizeBottom.y = m_size.y + 25.0f;
	}

	if (m_pos.x <= 0.0f)//右に移動
	{
		m_direction = false;
		m_isRunMove = true;

		m_vec.x = kEnemySpeed;
	}
	if (!m_direction)//右に移動時の判定
	{
		m_size.x = m_pos.x + 80 + 10 - 200;
		m_size.y = m_pos.y;

		m_sizeBottom.x = m_size.x + 45 - 20;
		m_sizeBottom.y = m_size.y + 25.0f;
	}

	m_sizeHit.x = m_size.x - 15.0f;
	m_sizeHit.y = m_size.y - 15.0f;
	m_sizeBottomHit.x = m_sizeBottom.x + 15;
	m_sizeBottomHit.y = m_sizeBottom.y + 15;

	//アニメーション
	Condition();
}

void Enemy::ShotEnemy()
{

}

void Enemy::ShotEnemyDraw()
{

	DrawBox(m_shotEnemyPos.x, m_shotEnemyPos.y, m_shotEnemyBottomPos.x, m_shotEnemyBottomPos.y, 0xffffff, true);
}

void Enemy::Condition()
{
	//右に移動アニメーション
	if (m_isRunMove)
	{
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_eyeImagePos += 48;
			m_frameCount = 0;
		}
		if (m_eyeImagePos >= 48 * 14 )
		{
			m_eyeImagePos = 336;
		}
	}

}


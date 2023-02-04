#include "Enemy.h"
#include "game.h"
#include "Dxlib.h"
#include <Dxlib.h>

namespace
{
	//アニメーションフレーム
	constexpr int kAnimationFrame = 3;

	//エネミー移動速度
	constexpr float kEnemySpeed = 6.5f;
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
	m_sizeBottom(0.0f, 0.0f)
{

}

Enemy::~Enemy()
{

}

void Enemy::Init()
{
	m_eyeImagePos = 336;
	m_direction = false;

	m_pos.x = Game::kScreenWidth;
	m_pos.y = Game::kScreenHeight - 70;
}

void Enemy::End()
{
}

void Enemy::Update()
{

	//m_size.x = 500;
	//m_size.y = 400;
	//m_sizeBottom.x = 600;
	//m_sizeBottom.y = 500;

	//m_size.x = m_pos.x + 500;
	//m_size.y = m_pos.y + 400;
	//m_sizeBottom.x = m_size.x - 100;
	//m_sizeBottom.y = m_size.y - 100;


	/*m_size.x = m_pos.x - 15.0f;
	m_size.y = m_pos.y;
	m_sizeBottom.x = m_size.x + 10.0f;
	m_sizeBottom.y = m_size.y + 60.0f;*/


	m_size.x = m_pos.x - 25.0f;
	m_size.y = m_pos.y + 10.0f;
	m_sizeBottom.x = m_pos.x + 25.0f;
	m_sizeBottom.y = m_pos.y + 60.0f;
	
	printfDx("\nenemy%f\n", m_size.x);
	printfDx("enemyY%f\n", m_size.y);

	m_pos += m_vec;
	
	if (m_pos.x >= Game::kScreenWidth)
	{
		//m_direction = true;
		m_isRunMove = true;
		m_vec.x = -kEnemySpeed;
	}
	else if (m_pos.x <= 0.0f)
	{
		//m_direction = false;
		m_isRunMove = true;
		m_vec.x = kEnemySpeed;
	}

	
	//アニメーション
	Condition();
	
}

void Enemy::Draw()
{
	//エネミー
	DrawRectRotaGraph(m_pos.x,m_pos.y,
		0, m_eyeImagePos, 128, 82, 3, 0, m_handle, true, m_direction);
#if true	
	//エネミーの当たり判定
	DrawBox(m_size.x, m_size.y,m_sizeBottom.x, m_sizeBottom.y,0xffffff, false);
	//DrawBox(m_pos.x - 25, m_pos.y + 10, m_pos.x + 25, m_pos.y + 60, 0xff0000, false);

#endif
}

void Enemy::SetHandle(int handle)
{
	m_handle = handle;
	//GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
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

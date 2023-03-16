#include "Enemy.h"

#include "game.h"
#include <Dxlib.h>

namespace
{
	//�A�j���[�V�����t���[��
	constexpr int kAnimationFrame = 3;

	//�G�l�~�[�ړ����x
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
	//�G�l�~�[
	DrawRectRotaGraph(static_cast<int>(m_pos.x), static_cast<int>(m_pos.y),
		0, m_eyeImagePos, 128, 82/2, 3, 0, m_handle, true, m_direction);

	ShotEnemyDraw();
#if true	

	//�G�l�~�[�̓����蔻��
	DrawBox(static_cast<int>(m_size.x), static_cast<int>(m_size.y)
		, static_cast<int>(m_sizeBottom.x), static_cast<int>(m_sizeBottom.y),0xff0000, false);

	//�U���󂯔͈͔���
	DrawBox(static_cast<int>(m_sizeHit.x), static_cast<int>(m_sizeHit.y)
		, static_cast<int>(m_sizeBottomHit.x), static_cast<int>(m_sizeBottomHit.y), 0x0000ff, false);

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

	if (m_pos.x >= Game::kScreenWidth - 150)//���Ɉړ����̔���
	{
		m_direction = true;
		m_isRunMove = true;

		m_vec.x = -kEnemySpeed;
	}
	if (m_direction)//���Ɉړ����̔���
	{
		m_size.x = m_pos.x + 80 + 10;
		m_size.y = m_pos.y;

		m_sizeBottom.x = m_size.x + 45 - 20;
		m_sizeBottom.y = m_size.y + 25.0f;
	}

	if (m_pos.x <= 0.0f)//�E�Ɉړ�
	{
		m_direction = false;
		m_isRunMove = true;

		m_vec.x = kEnemySpeed;
	}
	if (!m_direction)//�E�Ɉړ����̔���
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

	//�A�j���[�V����
	Condition();
}

void Enemy::ShotEnemy()
{

}

void Enemy::ShotEnemyDraw()
{

	DrawBox(static_cast<float>(m_shotEnemyPos.x), static_cast<int>(m_shotEnemyPos.y),
		static_cast<float>(m_shotEnemyBottomPos.x), static_cast<float>(m_shotEnemyBottomPos.y), 0xffffff, true);
}

void Enemy::Condition()
{
	//�E�Ɉړ��A�j���[�V����
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


#include "EnemyStage1.h"
#include "SceneMain2.h"
#include "game.h"
#include <DxLib.h>

namespace Enemy
{
	constexpr int kBossPosLeft = Game::kScreenWidth - 300;
	constexpr int kBossPosTop = 200;
	constexpr int kBossPosRight = kBossPosLeft + 100;
	constexpr int kBossPosBottom = kBossPosTop + 100;
}

EnemyStage1::EnemyStage1():
	m_posLeft(0),
	m_posTop(0),
	m_posRight(0),
	m_posBottom(0),
	m_barrelLeft(0),
	m_barrelTop(0),
	m_barrelRight(0),
	m_barrelBottom(0),
	m_getPos(0),
	m_firstMove(false),
	m_isFall(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(0.0f,0.0f),//樽
	m_vec(0.0f,0.0f)
{
	m_firstMove = true;//初動動作

	m_pos.x = Game::kScreenWidth - 600;
	m_pos.y = Game::kScreenHeight - 300;

	m_barrelPos.x = Enemy::kBossPosLeft;
	m_barrelPos.y = Enemy::kBossPosTop;

}

EnemyStage1::~EnemyStage1()
{

}

void EnemyStage1::Init()
{
}

void EnemyStage1::End()
{
}

void EnemyStage1::Update()
{
	BarrelMove();
	m_barrelPos += m_vec;
	if (m_isFall)//地面に当たっていたら
	{
		m_vec.y = 0.0f;
		m_barrelPos.y = static_cast<float>(m_getPos);//プレイヤーの位置座標
	}
	else
	{
		m_vec.y++;
	}

	//printfDx("%d\n", m_getPos);

	m_posLeft   = m_pos.x - 10;
	m_posTop    = m_pos.y - 10;
	m_posRight = m_posLeft + 10;
	m_posBottom = m_posTop + 10;

	//樽
	m_barrelLeft = m_barrelPos.x;
	m_barrelTop = m_barrelPos.y;
	m_barrelRight = m_barrelLeft  + 50;
	m_barrelBottom = m_barrelTop + 50;



}

void EnemyStage1::Draw()
{
	//エネミー
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xffffff, false);
	//ボス
	DrawBox(Enemy::kBossPosLeft, Enemy::kBossPosTop,
		Enemy::kBossPosRight, Enemy::kBossPosBottom, 0xffff00, false);
	//樽の移動
	DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, false);
}

void EnemyStage1::BarrelMove()
{

	if (m_firstMove)
	{
		m_barrelPos.x -= 15.0f;
		m_barrelPos.y -= 15.0f;

		if (m_barrelPos.y < 50.0f)
		{
			m_firstMove = false;
		}
	}
	
}

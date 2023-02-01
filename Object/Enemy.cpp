#include "Enemy.h"
#include "game.h"
#include "Dxlib.h"
#include <Dxlib.h>

Enemy::Enemy():
	m_handle(-1),
	m_pos(0.0f,0.0f),
	m_vec(0.0f, 0.0f),
	m_size(0.0f, 0.0f),
	m_sizeBottom(0.0f, 0.0f)
{
	m_pos.x = Game::kScreenWidth;
	m_pos.y = Game::kScreenHeight - 70;

	//m_vec.x = -5.0f;
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
	m_size.x = m_pos.x -15.0f;
	m_size.y = m_pos.y;
	m_sizeBottom.x = m_size.x + 10.0f;
	m_sizeBottom.y = m_size.y + 60.0f;

	m_pos += m_vec;
	if (m_pos.x == Game::kScreenWidth)
	{
		m_vec.x = -5.0f;
	}
	else if (m_pos.x == 0.0f)
	{
		m_vec.x = 5.0f;
	}

	/*
	Vec2 GetSize();
	Vec2 GetSizeBottom();
	*/
	//printfDx("%f",m_size.x);
	//printfDx("%f", GetSize().x);
}

void Enemy::Draw()
{
	//DrawRectRotaGraph(0,0,0, 0, 0, 0, 0, 0, m_handle,false,false);
	//DrawGraph(0, 0, m_handle, false);
	DrawRectRotaGraph(m_pos.x,m_pos.y,
		1344 - 112, 133, 112, 133, 2, 0, m_handle, true,false);
#if true	
	
	DrawBox(m_size.x, m_size.y, m_sizeBottom.x, m_sizeBottom.y,0xffffff, false);

#endif
}

void Enemy::SetHandle(int handle)
{
	m_handle = handle;
	GetGraphSizeF(m_handle, &m_size.x, &m_size.y);
}

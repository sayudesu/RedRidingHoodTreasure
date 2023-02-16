#include "EnemyStage1.h"
#include "SceneMain2.h"
#include "game.h"
#include <DxLib.h>

EnemyStage1::EnemyStage1():
	m_posLeft(0),
	m_posTop(0),
	m_posRight(0),
	m_posBottom(0)
{
	m_pos.x = Game::kScreenWidth;
	m_pos.y = Game::kScreenHeight - 150;
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
	m_pos.x -= 5;

	m_posLeft   = m_pos.x;
	m_posTop    = m_pos.y;
	m_posRight  = m_posLeft + 100;
	m_posBottom = m_posTop + 100;
}

void EnemyStage1::Draw()
{
	DrawBox(m_posLeft, m_posTop , m_posRight, m_posBottom, 0xffffff, false);
}

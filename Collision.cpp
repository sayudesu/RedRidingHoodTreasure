#include "Collision.h"
#include "PlayerNew.h"
#include "DrawMapStage2.h"
#include "game.h"
#include <Dxlib.h>

namespace
{
	constexpr float kGravity = 1.0f;
	constexpr float kGravityZero = 0.0f;
}

Collision::Collision():
	m_isGravity(false),
	m_pPlayer(nullptr),
	m_pMap(nullptr)
{
	m_pPlayer = new PlayerNew;
	m_pMap = new DrawMapStage2;
}

Collision::~Collision()
{
	delete m_pPlayer;
	delete m_pMap;
}

void Collision::Init()
{
	m_pPlayer->Init();
}

void Collision::Update()
{
	m_pPlayer->Update();
	//m_pMap->Update();
	HitObject();
	DrawFormatString(100, 0, 0xffffff, "重力%f", m_isGravity);
	DrawFormatString(100, 50, 0xffffff, "プレイヤー位置%f,%f", m_pPlayer->GetPlayerLeft(),m_pPlayer->GetPlayerTop());
	DrawFormatString(100, 100, 0xffffff, "プレイヤー位置%f,%f", m_pPlayer->GetPos().x,m_pPlayer->GetPos().y);

	
}

bool Collision::HitObject()
{
	//1階の判定
#if true	
	if ((Stage2::BoxBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box1Y < m_pPlayer->GetPlayerBottom()))
		{
			m_isGravity = true;
			
			return true;
		}
	}
#else
	if ((Stage2::BoxBottom1X > 100) &&
		(Stage2::Box1X < 300))
	{
		if ((Stage2::BoxBottom1Y > 100) &&
			(Stage2::Box1Y < 300))
		{
			m_gravity = kGravityZero;

			return true;
		}
	}
#endif
	m_isGravity = false;
	return false;
}

void Collision::Draw()
{
	DrawBox(Stage2::Box1X, Stage2::Box1Y, Stage2::BoxBottom1X, Stage2::BoxBottom1Y, 0x0000ff, true);
	DrawBox(m_pPlayer->GetPlayerLeft(), m_pPlayer->GetPlayerTop(),
		m_pPlayer->GetPlayerRight(), m_pPlayer->GetPlayerBottom(), 0xff00ff, true);
}

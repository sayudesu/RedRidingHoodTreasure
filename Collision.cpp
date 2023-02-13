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
	m_posY(0.0f),
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
	//m_pPlayer->Init();
}

void Collision::Update()
{
	m_pPlayer->Update();

	m_pPlayer->GetGravity(GetGravity());//重力.y
	m_pPlayer->GetPos(GetPos());//位置.y

	if(m_isGravity)
	{
		//ここを段差ずつ作っていく
		m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - 80.0f;
	}

	HitObject();
	m_pPlayer->GetScaffold(HitObject());

	DrawFormatString(100, 0, 0xffffff, "重力%f", m_isGravity);
	DrawFormatString(100, 50, 0xffffff, "プレイヤー位置%f,%f", m_pPlayer->GetPlayerLeft(),m_pPlayer->GetPlayerTop());
//	DrawFormatString(100, 100, 0xffffff, "プレイヤー位置%f,%f", m_pPlayer->GetPos().x,m_pPlayer->GetPos().y);

	
}

bool Collision::HitObject()
{
	//1階の判定
	if ((Stage2::BoxBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box1Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//1段差
	if ((Stage2::BoxBottom2X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box2X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom2Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box2Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//2段差
	if ((Stage2::BoxBottom3X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box3X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom3Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box3Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//3段差
	if ((Stage2::BoxBottom4X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box4X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom4Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box4Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//4段差
	if ((Stage2::BoxBottom5X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box5X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom5Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box5Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//5段差
	if ((Stage2::BoxBottom6X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box6X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom6Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box6Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//6段差
	if ((Stage2::BoxBottom7X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box7X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom7Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box7Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//7段差
	if ((Stage2::BoxBottom8X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box8X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom8Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box8Y < m_pPlayer->GetPlayerBottom()))
		{
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}

	printfDx("NotObject\n");
	m_isGravity = false;
	return false;
}

void Collision::Draw()
{
	DrawBox(Stage2::Box1X, Stage2::Box1Y, Stage2::BoxBottom1X, Stage2::BoxBottom1Y, 0x0000ff, false);
	DrawFormatString(1000, 0, 0xffffff, "位置Left%f", m_pPlayer->GetPlayerLeft());
	DrawFormatString(1000, 100, 0xffffff, "位置Top%f", m_pPlayer->GetPlayerTop());
	DrawPixel(100, 700 - 50, GetColor(GetRand(255), GetRand(255), GetRand(255)));
	/*DrawBox(m_pPlayer->GetPlayerLeft(), m_pPlayer->GetPlayerTop(),
		    m_pPlayer->GetPlayerRight(), m_pPlayer->GetPlayerBottom(), 0xff00ff, true);*/
}

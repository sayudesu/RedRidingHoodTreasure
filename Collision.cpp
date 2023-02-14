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
	m_landingPos(0.0f),
	m_pPlayer(nullptr),
	m_pMap(nullptr)
{
	m_pPlayer = new PlayerNew;
	m_pMap = new DrawMapStage2;

	m_landingPos = 70.0f;
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
	HitObject();
	m_pPlayer->Update();

//	m_pPlayer->GetGravity(m_isGravity);//重力.y
	m_pPlayer->GetScaffold(HitObject()); //重力.y
	m_pPlayer->GetLadder(HItLadder());//位置.y.z
	m_pPlayer->GetPos(m_posY);//位置.y
	/*
	if(m_isGravity)
	{
		//ここを段差ずつ作っていく
		m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - 80.0f;
	}
	*/

}
void Collision::Draw()
{

	DrawFormatString(100, 0, 0xffffff, "重力%f", m_isGravity);
	DrawFormatString(100, 150, 0xffffff, "プレイヤー位置%f,マップ位置%d", m_pPlayer->GetPlayerBottom(), Stage2::Box1Y);
	DrawBox(Stage2::Box1X, Stage2::Box1Y, Stage2::BoxBottom1X, Stage2::BoxBottom1Y, 0x0000ff, false);
	DrawFormatString(1000, 0, 0xffffff, "位置Left%f", m_pPlayer->GetPlayerLeft());
	DrawFormatString(1000, 100, 0xffffff, "位置Top%f", m_pPlayer->GetPlayerTop());
	DrawPixel(100, 700 - 50, GetColor(GetRand(255), GetRand(255), GetRand(255)));
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos;

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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos - Stage2::BoxStep;
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos - Stage2::BoxStep
				- Stage2::BoxStep;
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos - Stage2::BoxStep
				- Stage2::BoxStep - Stage2::BoxStep;
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos + Stage2::BoxStep
				- Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep;
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos - Stage2::BoxStep
				- Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep;
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos - Stage2::BoxStep
				- Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep;
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
			m_posY = static_cast<float>(Game::kScreenHeight) - 40.0f - m_landingPos - Stage2::BoxStep
				- Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep - Stage2::BoxStep;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}


	//2階の判定
	if ((Stage2::BoxBottom1Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box1Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom1Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box1Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//1段差
	if ((Stage2::BoxBottom2Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box2Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom2Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box2Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2;;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//2段差
	if ((Stage2::BoxBottom2Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box2Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom2Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box2Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//3段差
	if ((Stage2::BoxBottom3Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box3Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom3Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box3Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2
				- Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//4段差
	if ((Stage2::BoxBottom4Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box4Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom4Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box4Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box4Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2
				- Stage2::BoxStep2 - Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//5段差
	if ((Stage2::BoxBottom5Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box5Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom5Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box5Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2
				- Stage2::BoxStep2 - Stage2::BoxStep2 - Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//6段差
	if ((Stage2::BoxBottom6Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box6Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom6Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box8Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2
				- Stage2::BoxStep2 - Stage2::BoxStep2 - Stage2::BoxStep2 - Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//7段差
	if ((Stage2::BoxBottom7Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box7Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom7Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box7Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2
				- Stage2::BoxStep2 - Stage2::BoxStep2 - Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	//8段差
	if ((Stage2::BoxBottom8Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Box8Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::BoxBottom8Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Box8Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::Box1Ys + 20.0f - m_landingPos - Stage2::BoxStep2 - Stage2::BoxStep2
				- Stage2::BoxStep2 - Stage2::BoxStep2 - Stage2::BoxStep2 - Stage2::BoxStep2;
			printfDx("HitObject\n");
			m_isGravity = true;
			return true;
		}
	}
	printfDx("NotObject\n");
	m_isGravity = false;
	return false;
}

bool Collision::HItLadder()
{
	//1階の判定
	if ((Stage2::LadderBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::Ladder1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::LadderBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::Ladder1Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	return false;
}



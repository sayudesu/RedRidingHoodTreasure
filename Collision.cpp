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
	DrawFormatString(100, 150, 0xffffff, "プレイヤー位置%f,マップ位置%d", m_pPlayer->GetPlayerBottom(), Stage2::kBox1Y);
	DrawBox(Stage2::kBox1X, Stage2::kBox1Y, Stage2::kBoxBottom1X, Stage2::kBoxBottom1Y, 0x0000ff, false);
	DrawFormatString(1000, 0, 0xffffff, "位置Left%f", m_pPlayer->GetPlayerLeft());
	DrawFormatString(1000, 100, 0xffffff, "位置Top%f", m_pPlayer->GetPlayerTop());
	DrawPixel(100, 700 - 50, GetColor(GetRand(255), GetRand(255), GetRand(255)));

}
bool Collision::HitObject()
{

	//1階の判定
	if ((Stage2::kBoxBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Y - 50.0f;

			return true;
		}
	}
	//1段差
	if ((Stage2::kBoxBottom2X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Y - 50.0f;
			return true;
		}
	}
	//2段差
	if ((Stage2::kBoxBottom3X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Y - 50.0f;
				- Stage2::kBoxStep;
			return true;
		}
	}
	//3段差
	if ((Stage2::kBoxBottom4X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Y - 50.0f;
				- Stage2::kBoxStep - Stage2::kBoxStep;
			return true;
		}
	}
	//4段差
	if ((Stage2::kBoxBottom5X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Y - 50.0f;
			return true;
		}
	}
	//5段差
	if ((Stage2::kBoxBottom6X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Y - 50.0f;
			return true;
		}
	}
	//6段差
	if ((Stage2::kBoxBottom7X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Y - 50.0f;
			return true;
		}
	}
	//7段差
	if ((Stage2::kBoxBottom8X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Y - 50.0f;
			return true;
		}
	}


	//2階の判定
	if ((Stage2::kBoxBottom1Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::koxBottom1Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Ys - 50.0f;
			return true;
		}
	}
	//1段差
	if ((Stage2::kBoxBottom2Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Ys - 50.0f;
			return true;
		}
	}
	//2段差
	if ((Stage2::kBoxBottom3Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Ys - 50.0f;
			return true;
		}
	}
	//3段差
	if ((Stage2::kBoxBottom4Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Ys - 50.0f;
			return true;
		}
	}
	//4段差
	if ((Stage2::kBoxBottom5Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Ys - 50.0f;
			return true;
		}
	}
	//5段差
	if ((Stage2::kBoxBottom6Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Ys - 50.0f;
			return true;
		}
	}
	//6段差
	if ((Stage2::kBoxBottom7Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Ys - 50.0f;
			return true;
		}
	}
	//7段差
	if ((Stage2::kBoxBottom8Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Ys - 50.0f;
			return true;
		}
	}

	//3階の判定
	if ((Stage2::kBoxBottom1Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Yt - 50.0f;
			return true;
		}
	}
	//1段差
	if ((Stage2::kBoxBottom2Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Yt - 50.0f;
			return true;
		}
	}
	//2段差
	if ((Stage2::kBoxBottom3Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Yt - 50.0f;
			return true;
		}
	}
	//3段差
	if ((Stage2::kBoxBottom4Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Yt - 50.0f;
			return true;
		}
	}
	//4段差
	if ((Stage2::kBoxBottom5Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Yt - 50.0f;
			return true;
		}
	}
	//5段差
	if ((Stage2::kBoxBottom6Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Yt - 50.0f;
			return true;
		}
	}
	//6段差
	if ((Stage2::kBoxBottom7Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Yt - 50.0f;
			return true;
		}
	}
	//7段差
	if ((Stage2::kBoxBottom8Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Yt - 50.0f;
			return true;
		}
	}
	DrawBox(m_pPlayer->GetPlayerLeft(), m_pPlayer->GetPlayerTop(), m_pPlayer->GetPlayerRight(), m_pPlayer->GetPlayerBottom(), 0x00ff00, true);
	return false;
}

//梯子の判定
bool Collision::HItLadder()
{
	//一階の判定
	if ((Stage2::kLadderBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder1Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	//二階の判定
	if ((Stage2::kLadderBottom2X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder2X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom2Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder2Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	return false;
}



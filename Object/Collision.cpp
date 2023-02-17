#include "Collision.h"
#include "PlayerNew.h"
#include "DrawMapStage2.h"
#include "EnemyStage1.h"
#include "game.h"
#include <Dxlib.h>

namespace
{
	constexpr float kGravity = 1.0f;
	constexpr float kGravityZero = 0.0f;
	constexpr float kPlayerPosY = 50.0f;
	constexpr float kPlayerPosPulsY = 1.0f;
}

Collision::Collision():
	m_posY(0.0f),
	m_enemyPosY(0),
	m_landingPos(0.0f),
	m_pPlayer(nullptr),
	m_pMap(nullptr),
	m_pEnemy(nullptr)
{
	m_pPlayer = new PlayerNew;
	m_pMap = new DrawMapStage2;
	m_pEnemy = new EnemyStage1;
	m_landingPos = 70.0f;
}

Collision::~Collision()
{
	delete m_pPlayer;
	delete m_pMap;
	delete m_pEnemy;
}

void Collision::Init()
{
	//m_pPlayer->Init();
}

void Collision::Update()
{
	m_pPlayer->Update();

	m_pEnemy->Update();

	m_pPlayer->GetScaffold(HitObject()); //重力.y
	m_pPlayer->GetLadder(HItLadder());   //位置.y.z
	m_pPlayer->GetPos(m_posY);           //位置.y
	m_pPlayer->GetGoal(HitGoal());       //ゴールしたかどうか
	m_pPlayer->GetEnemyHit(HitEnemy());  //エネミーがプレイヤーを攻撃する
	m_pPlayer->GetPlayerHit(HitPlayer());//プレイヤーがエネミーを攻撃したかどうか

	m_pEnemy->GetHitFall(HitEnemyObject()); //重力.y
	m_pEnemy->GetPos(m_enemyPosY);           //位置.y
}
void Collision::Draw()
{

}
//地面の判定
bool Collision::HitObject()
{
	//1階の判定///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Y < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Y - kPlayerPosY + kPlayerPosPulsY;

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
			m_posY = Stage2::kBox2Y - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox3Y - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox4Y - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox5Y - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox6Y - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox7Y - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox8Y - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//2階の判定///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xs > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xs < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::koxBottom1Ys > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Ys < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox2Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox3Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox4Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox5Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox6Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox7Ys - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox8Ys - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//3階の判定///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xt > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xt < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Yt > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Yt < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Yt - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox2Yt - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox3Yt - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox4Yt - kPlayerPosY + kPlayerPosPulsY;
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
			m_posY = Stage2::kBox5Yt - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	////5段差
	//if ((Stage2::kBoxBottom6Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox6Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom6Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox6Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox6Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////6段差
	//if ((Stage2::kBoxBottom7Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	//4階の判定///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//1段差
	if ((Stage2::kBoxBottom2Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//2段差
	if ((Stage2::kBoxBottom3Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//3段差
	if ((Stage2::kBoxBottom4Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//4段差
	if ((Stage2::kBoxBottom5Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//5段差
	if ((Stage2::kBoxBottom6Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//6段差
	if ((Stage2::kBoxBottom7Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox7Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom7Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox7Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox7Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//7段差
	if ((Stage2::kBoxBottom8Xf > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox8Xf < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom8Yf > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox8Yf < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox8Yf - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}

	//5階の判定///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox1XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom1YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox1YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox1YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//1段差
	if ((Stage2::kBoxBottom2XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox2XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom2YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox2YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox2YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//2段差
	if ((Stage2::kBoxBottom3XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox3XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom3YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox3YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox3YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//3段差
	if ((Stage2::kBoxBottom4XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox4XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom4YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox4YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox4YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//4段差
	if ((Stage2::kBoxBottom5XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox5XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom5YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox5YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox5YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	//5段差
	if ((Stage2::kBoxBottom6XFi > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kBox6XFi < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kBoxBottom6YFi > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kBox6YFi < m_pPlayer->GetPlayerBottom()))
		{
			m_posY = Stage2::kBox6YFi - kPlayerPosY + kPlayerPosPulsY;
			return true;
		}
	}
	////6段差
	//if ((Stage2::kBoxBottom7XFi > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7XFi < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7YFi > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7YFi < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7YFi - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8XFi > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8XFi < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8YFi > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8YFi < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8YFi - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	DrawBox(static_cast<int>(m_pPlayer->GetPlayerLeft()), static_cast<int>(m_pPlayer->GetPlayerTop()),
		static_cast<int>(m_pPlayer->GetPlayerRight()), static_cast<int>(m_pPlayer->GetPlayerBottom()), 0x00ff00, true);
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

	//三階の判定
	if ((Stage2::kLadderBottom3X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder3X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom3Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder3Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	//三階の判定
	if ((Stage2::kLadderBottom4X > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kLadder4X < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kLadderBottom4Y > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kLadder4Y < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}

	return false;
}
//ゴール判定
bool Collision::HitGoal()
{
	if ((Stage2::kGoalBottomX > m_pPlayer->GetPlayerLeft()) &&
		(Stage2::kGoalX < m_pPlayer->GetPlayerRight()))
	{
		if ((Stage2::kGoalBottomY > m_pPlayer->GetPlayerTop()) &&
			(Stage2::kGoalY < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}
	return false;
}
//プレイヤーとエネミーの当たり判定::エネミーがプレイヤーを攻撃
bool Collision::HitEnemy()
{
	if ((m_pEnemy->GetRight() > m_pPlayer->GetPlayerLeft()) &&
		(m_pEnemy->GetLeft() < m_pPlayer->GetPlayerRight()))
	{
		if ((m_pEnemy->GetBottom() > m_pPlayer->GetPlayerTop()) &&
			(m_pEnemy->GetTop() < m_pPlayer->GetPlayerBottom()))
		{
			return true;
		}
	}
	return false;
}

//プレイヤーとエネミーの当たり判定::プレイヤーがエネミーを攻撃
bool Collision::HitPlayer()
{
	if ((m_pEnemy->GetRight() > m_pPlayer->GetAttackPlayerLeft()) &&
		(m_pEnemy->GetLeft() < m_pPlayer->GetAttackPlayerRight()))
	{
		if ((m_pEnemy->GetBottom() > m_pPlayer->GeAttacktPlayerTop()) &&
			(m_pEnemy->GetTop() < m_pPlayer->GetAttackPlayerBottom()))
		{
			return true;
		}
	}
	return false;
}
//地面の判定
bool Collision::HitEnemyObject()
{
	////1階の判定///////////////////////////////////////////////////////////////////////////////////////////
	//if ((Stage2::kBoxBottom1X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox1X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom1Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox1Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox1Y - kPlayerPosY + kPlayerPosPulsY;

	//		return true;
	//	}
	//}
	////1段差
	//if ((Stage2::kBoxBottom2X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox2X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom2Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox2Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox2Y - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////2段差
	//if ((Stage2::kBoxBottom3X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox3X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom3Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox3Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox3Y - kPlayerPosY + kPlayerPosPulsY;
	//		-Stage2::kBoxStep;
	//		return true;
	//	}
	//}
	////3段差
	//if ((Stage2::kBoxBottom4X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox4X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom4Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox4Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox4Y - kPlayerPosY + kPlayerPosPulsY;
	//		-Stage2::kBoxStep - Stage2::kBoxStep;
	//		return true;
	//	}
	//}
	////4段差
	//if ((Stage2::kBoxBottom5X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox5X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom5Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox5Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox5Y - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////5段差
	//if ((Stage2::kBoxBottom6X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox6X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom6Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox6Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox6Y - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////6段差
	//if ((Stage2::kBoxBottom7X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7Y - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8X > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8X < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8Y > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8Y < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8Y - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	////2階の判定///////////////////////////////////////////////////////////////////////////////////////////
	//if ((Stage2::kBoxBottom1Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox1Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::koxBottom1Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox1Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox1Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////1段差
	//if ((Stage2::kBoxBottom2Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox2Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom2Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox2Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox2Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////2段差
	//if ((Stage2::kBoxBottom3Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox3Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom3Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox3Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox3Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////3段差
	//if ((Stage2::kBoxBottom4Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox4Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom4Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox4Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox4Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////4段差
	//if ((Stage2::kBoxBottom5Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox5Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom5Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox5Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox5Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////5段差
	//if ((Stage2::kBoxBottom6Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox6Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom6Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox6Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox6Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////6段差
	//if ((Stage2::kBoxBottom7Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8Xs > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8Xs < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8Ys > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8Ys < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8Ys - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	////3階の判定///////////////////////////////////////////////////////////////////////////////////////////
	//if ((Stage2::kBoxBottom1Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox1Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom1Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox1Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox1Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////1段差
	//if ((Stage2::kBoxBottom2Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox2Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom2Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox2Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox2Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////2段差
	//if ((Stage2::kBoxBottom3Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox3Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom3Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox3Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox3Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////3段差
	//if ((Stage2::kBoxBottom4Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox4Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom4Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox4Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox4Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////4段差
	//if ((Stage2::kBoxBottom5Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox5Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom5Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox5Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox5Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////5段差
	//if ((Stage2::kBoxBottom6Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox6Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom6Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox6Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox6Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////6段差
	//if ((Stage2::kBoxBottom7Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8Xt > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8Xt < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8Yt > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8Yt < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8Yt - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	////4階の判定///////////////////////////////////////////////////////////////////////////////////////////
	//if ((Stage2::kBoxBottom1Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox1Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom1Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox1Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox1Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////1段差
	//if ((Stage2::kBoxBottom2Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox2Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom2Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox2Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox2Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////2段差
	//if ((Stage2::kBoxBottom3Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox3Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom3Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox3Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox3Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////3段差
	//if ((Stage2::kBoxBottom4Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox4Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom4Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox4Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox4Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////4段差
	//if ((Stage2::kBoxBottom5Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox5Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom5Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox5Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox5Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////5段差
	//if ((Stage2::kBoxBottom6Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox6Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom6Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox6Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox6Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////6段差
	//if ((Stage2::kBoxBottom7Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8Xf > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8Xf < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8Yf > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8Yf < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8Yf - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	//5階の判定///////////////////////////////////////////////////////////////////////////////////////////
	if ((Stage2::kBoxBottom1XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox1XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom1YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox1YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY =100;
			printfDx("5階\n");
			return true;
		}
	}
	//1段差
	if ((Stage2::kBoxBottom2XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox2XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom2YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox2YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3YFi - 100;
			printfDx("5階1\n");
			return true;
		}
	}
	//2段差
	if ((Stage2::kBoxBottom3XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox3XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom3YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox3YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3YFi - 100;
			printfDx("5階2\n");
			return true;
		}
	}
	//3段差
	if ((Stage2::kBoxBottom4XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox4XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom4YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox4YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3YFi - 100;
			printfDx("5階3\n");
			return true;
		}
	}
	//4段差
	if ((Stage2::kBoxBottom5XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox5XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom5YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox5YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3YFi - 100;
			printfDx("5階4\n");
			return true;
		}
	}
	//5段差
	if ((Stage2::kBoxBottom6XFi > m_pEnemy->GetBarrelLeft()) &&
		(Stage2::kBox6XFi < m_pEnemy->GetBarrelRight()))
	{
		if ((Stage2::kBoxBottom6YFi > m_pEnemy->GetBarrelTop()) &&
			(Stage2::kBox6YFi < m_pEnemy->GetBarrelBottom()))
		{
			m_enemyPosY = Stage2::kBox3YFi - 100;
			printfDx("5階5\n");
			return true;
		}
	}
	////6段差
	//if ((Stage2::kBoxBottom7XFi > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox7XFi < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom7YFi > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox7YFi < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox7YFi - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}
	////7段差
	//if ((Stage2::kBoxBottom8XFi > m_pPlayer->GetPlayerLeft()) &&
	//	(Stage2::kBox8XFi < m_pPlayer->GetPlayerRight()))
	//{
	//	if ((Stage2::kBoxBottom8YFi > m_pPlayer->GetPlayerTop()) &&
	//		(Stage2::kBox8YFi < m_pPlayer->GetPlayerBottom()))
	//	{
	//		m_posY = Stage2::kBox8YFi - kPlayerPosY + kPlayerPosPulsY;
	//		return true;
	//	}
	//}

	return false;
}


#include "Collision.h"
#include "PlayerMapMove.h"
#include "Enemy.h"
#include <Dxlib.h>

Collision::Collision():
	m_pPlayer(nullptr),
	m_pEnemy(nullptr)
{
	m_pPlayer = new PlayerMapMove;
	m_pEnemy = new Enemy;
}

Collision::~Collision()
{
	delete m_pPlayer;
	delete m_pEnemy;
}

void Collision::Init()
{
	
}

void Collision::End()
{

}

void Collision::Update()
{
	m_pPlayer->Update();
	m_pEnemy->Update();

	//敵とプレイヤーの通常ヒット判定
	PlayerEnemyHit(m_pEnemy->GetSizeHit().x, m_pEnemy->GetSizeHit().y, m_pEnemy->GetSizeBottomHit().x, m_pEnemy->GetSizeBottomHit().y,
		m_pPlayer->GetPlayerLeft(), m_pPlayer->GetPlayerTop(), m_pPlayer->GetPlayerRight(), m_pPlayer->GetPlayerBottom());
	printfDx("%f", m_pEnemy->GetSizeHit().x);
	printfDx("\n%f", m_pPlayer->GetPlayerLeft());

}

void Collision::Draw()
{
}

//敵とプレイヤーの通常ヒット判定
bool Collision::PlayerEnemyHit(int firstLeft, int firstTop, int firstRight, int firstBottom, 
							   int SecondLeft, int SecondTop, int SecondRight, int SecondBottom)
{
	if ((firstRight > SecondLeft) &&
		(firstLeft < SecondRight))
	{
		if ((firstBottom > SecondTop) &&
			(firstTop < SecondBottom))
		{
			printfDx("判定有効");
			return true;
		}
	}
	return false;
}

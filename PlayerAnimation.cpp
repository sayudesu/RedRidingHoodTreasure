#include "PlayerAnimation.h"
#include <Dxlib.h>

PlayerAnimation::PlayerAnimation():
	m_hPlayer(-1),//プレイヤー画像
	m_hPlayerIdle(-1),//プレイヤー画像（アイドル状態）
	m_posY(0),
	m_pos(0.0f, 0.0f)
{
}

PlayerAnimation::~PlayerAnimation()
{
}

void PlayerAnimation::Update()
{
	//printfDx("%f\n", m_pos.x);
	printfDx("%d\n", m_posY);
	m_pos.y = m_posY;


}

void PlayerAnimation::Draw()
{
	//何もしていない状態
	DrawRectRotaGraph(m_pos.x, m_pos.y,
		0, 0, 112, 133,
		1.5, 0, m_hPlayerIdle, true, true);

	//横112
	//縦133
}

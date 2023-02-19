#include "EnemyStage1.h"
#include "SceneMain2.h"
#include "game.h"
#include <DxLib.h>

namespace Enemy
{

	//ボスの位置
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
	m_fall(0),
	m_ladderNum(0),
	m_getPos(0.0f),
	m_isFirstMove(false),
	m_isCourse(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(0.0f,0.0f),//樽
	m_vec(0.0f,0.0f)
{
	m_isFirstMove = true;//初動動作

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
	m_barrelPos.y += m_vec.y;//重力のベクトル用
	m_vec.y += 1.0f;//重力

	BarrelMove();//樽の動き
	fireBallMove();//ファイアボールの動き
	npcPos();//敵のサイズ取得
}

void EnemyStage1::Draw()
{
	//エネミー
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xffffff, true);
	//ボス
	DrawBox(Enemy::kBossPosLeft, Enemy::kBossPosTop,
		Enemy::kBossPosRight, Enemy::kBossPosBottom, 0xffff00, true);
	//樽の移動
	DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, true);
}

void EnemyStage1::BarrelMove()
{
	if (m_fall == 5)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= 5.0f;//とりあえず右に移動

	}

	if (m_ladderNum == 4)//梯子を降りる
	{
		m_barrelPos.y += 10;
	}
	else if (m_fall == 4)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += 5.0f;//左に移動

	}

	if (m_fall == 3)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= 5.0f;//とりあえず右に移動

	}

	if (m_fall == 2)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += 5.0f;//左に移動

	}

	if (m_fall == 1)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= 5.0f;//とりあえず右に移動

	}

	if (m_barrelRight < 0)//樽が画面左に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy::kBossPosLeft;
		m_barrelPos.y = Enemy::kBossPosTop;
	}

	if (m_fall == 0 && !m_isCourse)//樽が右に移動する場合
	{
		m_barrelPos.x -= 1.0f;
	}

	if (m_fall == 0 && m_isCourse)//樽が左に移動する場合
	{
		m_barrelPos.x += 1.0f;
	}
}

void EnemyStage1::fireBallMove()
{

}

void EnemyStage1::npcPos()
{
	//enemyの座標
	m_posLeft = m_pos.x - 10;
	m_posTop = m_pos.y - 10;
	m_posRight = m_posLeft + 10;
	m_posBottom = m_posTop + 10;

	//樽
	m_barrelLeft = m_barrelPos.x;
	m_barrelTop = m_barrelPos.y;
	m_barrelRight = m_barrelLeft + 40;
	m_barrelBottom = m_barrelTop + 40;
}

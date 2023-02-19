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

	constexpr float kBarrelSpeed = 8.0f;


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
	m_fallenLeft(0),
	m_fallenTop(0),
	m_fallenRight(0),
	m_fallenBottom(0),
	m_fallenRangeLeft(0),
	m_fallenRangeTop(0),
	m_fallenRangeRight(0),
	m_fallenRangeBottom(0),
	m_fall(0),
	m_fallFireBall(0),
	m_ladderNum(0),
	m_getPos(0.0f),
	m_getFireBallPos(0),
	m_isFirstMove(false),
	m_isCourse(false),
	m_isFireBallCourse(false),
	m_pos(0.0f, 0.0f),
	m_barrelPos(0.0f,0.0f),//樽
	m_fallenPos(0.0f, 0.0f),//ドッスン的な奴
	m_vec(0.0f,0.0f)
{
	m_isFirstMove = true;//初動動作

	//ファイアボール初期位置
	m_pos.x = Game::kScreenWidth - 400;
	m_pos.y = Game::kScreenHeight - 400;
	//樽初期位置
	m_barrelPos.x = Enemy::kBossPosLeft;
	m_barrelPos.y = Enemy::kBossPosTop;
	//どっすん
	m_fallenPos.x = Stage2::kBox2Xt;
	m_fallenPos.y = Stage2::kBoxBottom8Yf;

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
	BarrelMove();//樽の動き
	fireBallMove();//ファイアボールの動き
	falleMove();//ドッスン動き
	npcPos();//敵のサイズ取得
}
//描画
void EnemyStage1::Draw()
{
	//エネミー
	DrawBox(m_posLeft, m_posTop, m_posRight, m_posBottom, 0xff0000, true);
	//ボス
	DrawBox(Enemy::kBossPosLeft, Enemy::kBossPosTop,
		Enemy::kBossPosRight, Enemy::kBossPosBottom, 0xffff00, true);
	//樽
	DrawBox(m_barrelLeft, m_barrelTop, m_barrelRight, m_barrelBottom, 0xffff00, true);
	//どっすん
	DrawBox(m_fallenLeft, m_fallenTop, m_fallenRight, m_fallenBottom, 0xffff00, true);
	//範囲
	DrawBox(m_fallenRangeLeft, m_fallenRangeTop, m_fallenRangeRight, m_fallenRangeBottom, 0xffff00, false);
}
//樽の動き
void EnemyStage1::BarrelMove()
{
	m_barrelPos.y += m_vec.y;//重力のベクトル用

	m_vec.y += 3.0f;//重力

	if (m_fall == 5)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy::kBarrelSpeed;//とりあえず右に移動

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
		m_barrelPos.x += Enemy::kBarrelSpeed;//左に移動

	}

	if (m_fall == 3)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy::kBarrelSpeed;//とりあえず右に移動

	}

	if (m_fall == 2)//地面に当たったら
	{
		m_isCourse = true;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x += Enemy::kBarrelSpeed;//左に移動

	}

	if (m_fall == 1)//地面に当たったら
	{
		m_isCourse = false;
		m_vec.y = 0.0f;//下に落ちないように
		m_barrelPos.y = m_getPos;//プレイヤーの位置座標
		m_barrelPos.x -= Enemy::kBarrelSpeed;//とりあえず右に移動

	}

	if (m_barrelRight < 0)//樽が画面左に消えると最初の位置に戻っていく
	{
		m_barrelPos.x = Enemy::kBossPosLeft;
		m_barrelPos.y = Enemy::kBossPosTop;
	}

	if (m_fall == 0 && !m_isCourse)//樽が右に移動する場合
	{
		m_barrelPos.x -= Enemy::kBarrelSpeed;
	}

	if (m_fall == 0 && m_isCourse)//樽が左に移動する場合
	{
		m_barrelPos.x += Enemy::kBarrelSpeed;
	}
}
//炎球の動き
void EnemyStage1::fireBallMove()
{
	m_pos.y += 3.0f;//重力

	if (!m_isFireBallCourse)//右動き
	{
		m_pos.x -= 3.0f;
		if (m_pos.x < Stage2::kBox1Xs)//向きを変更する
		{
			m_isFireBallCourse = true;
		}
	}
	else//左動き
	{
		m_pos.x += 3.0f;
		if (m_pos.x > Stage2::kBoxBottom8Xs - 30)//向きを変更する
		{
			m_isFireBallCourse = false;
		}
	}

	if (m_fallFireBall== 2)//地面に当たったら
	{
		//m_vec.y = 0.0f;//下に落ちないように
		m_pos.y = static_cast<float>(m_getFireBallPos) + 10;//プレイヤーの位置座標
	}
}
//どっすん動き
void EnemyStage1::falleMove()
{
	
}
//敵のキャラ座標取得
void EnemyStage1::npcPos()
{
	//enemyの座標
	m_posLeft = m_pos.x;
	m_posTop = m_pos.y;
	m_posRight = m_posLeft + 30;
	m_posBottom = m_posTop + 30;

	//樽
	m_barrelLeft = m_barrelPos.x;
	m_barrelTop = m_barrelPos.y;
	m_barrelRight = m_barrelLeft + 40;
	m_barrelBottom = m_barrelTop + 40;

	//ドッスン
	m_fallenLeft = m_fallenPos.x;
	m_fallenTop = m_fallenPos.y;
	m_fallenRight = m_fallenLeft  + Stage2::kBoxWidth;
	m_fallenBottom = m_fallenTop  +10;

	m_fallenRangeLeft = m_fallenLeft - 50;
	m_fallenRangeTop = m_fallenTop + 30;
	m_fallenRangeRight = m_fallenRight + 50;
	m_fallenRangeBottom = m_fallenRangeTop + 100;
}

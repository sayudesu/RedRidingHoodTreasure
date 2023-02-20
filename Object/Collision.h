#pragma once
#include "Vec2.h"

class PlayerNew;
class DrawMapStage2;
class EnemyStage1;
class Collision
{
public:
	Collision();
	~Collision();

	void Init();
	void Update();
	void Draw();

//当たり判定
public:
	bool HitObject();//地面との当たり判定
	bool HItLadder();//梯子との当たり判定
	bool HitPlayer();//プレイヤーと敵の当たり判定
	bool HitGoal();//ゴールとの判定

    int HitEnemyObject();//敵と地面との当たり判定
	int HItEnemyLadder();//梯子とエネミーの当たり判定

	int HitEnemyFireBall();//炎球と地面の当たり判定
	bool HitEnemy();//プレイヤーと敵の当たり判定

	int HitFallenRange();//落ちる敵の範囲
	bool HitFallen();//落ちるやつとプレイヤーの判定

	bool HitCharge();//追跡する敵とプレイヤーの判定
//渡し
public:
	float GetPos () { return m_posY; }
	void GetGoal(bool stageClear) { m_isStageClear = stageClear; }
	bool m_isStageClear;
	//void  GetGoal2() { m_pPlayer->GetGameClear(); }
private:

	float m_posY;//プレイヤーのY座標
	float m_enemyPosY;//プレイヤーのY座標
	int m_enemyFireBallPosY;//プレイヤーのY座標

	float m_landingPos;//着地位置

	bool m_isPlayerPos;


	PlayerNew* m_pPlayer;
	DrawMapStage2* m_pMap;
	EnemyStage1* m_pEnemy;
};


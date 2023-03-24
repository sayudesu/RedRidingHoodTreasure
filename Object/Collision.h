#pragma once
#include "Vec2.h"

namespace Object
{
	constexpr int kNum = 16;
}

class PlayerNew;
class DrawMapStage1;
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

	int HitScore();//スコア判定

	int HitFallenRange();//落ちる敵の範囲
	bool HitFallen();//落ちるやつとプレイヤーの判定

	bool HitCharge();//追跡する敵とプレイヤーの判定
//渡し
public:
	bool m_isStageClear;
	float GetPos () { return m_posY; }
	void GetGoal(bool stageClear) { m_isStageClear = stageClear; }
	void GetDead(bool dead) { m_isGameOver = dead; }
	bool SetDead() { return m_isGameOver; }

	bool m_isDeadSceneChange;//死んだ用シーン切り替え
    void GetDeadChangeScene(bool deadSceneChange) { m_isDeadSceneChange = deadSceneChange; }//死んだらシーンを切り替え

	float m_posY;//プレイヤーのY座標

private:

	int m_floorLeftPos[Object::kNum];//地面位置
	int m_floorTopPos[Object::kNum];//地面位置
	int m_floorRightPos[Object::kNum];//地面位置
	int m_floorBottomPos[Object::kNum];//地面位置

	int m_playerYposMove[Object::kNum];//プレイヤーの位置を調整
	int m_playerYPulsNum[Object::kNum];

	bool m_isGameOver;
	float m_enemyPosY;//プレイヤーのY座標
	int m_enemyFireBallPosY;//プレイヤーのY座標

	float m_landingPos;//着地位置

	bool m_isPlayerPos;


	PlayerNew* m_pPlayer;
	DrawMapStage1* m_pMap;
	EnemyStage1* m_pEnemy;
};


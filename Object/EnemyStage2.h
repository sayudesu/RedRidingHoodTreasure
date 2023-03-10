#pragma once
#include "Vec2.h"
#include "EnemyStage1.h"

class EnemyStage2 : public EnemyStage1
{
public:
	EnemyStage2();
	virtual~EnemyStage2();

	virtual void Init();
	virtual void End();
	virtual void Update();
	virtual void Draw();

private:

	void BarrelMove();//樽の動き

	void fireBallMove();//樽の動き

	void falleMove();//どっすん動き

	void ChargeMove();//チャージする敵動き

	void UpDownMove();//上下運動する罠

	void npcPos();//敵のキャラ座標取得

public:
	//画像
	//ファイアボールの画像
	void SetHandleFireBall(int handle) { m_hFireBall = handle; }

	//ファイアーボール
	int  GetLeft  () { return m_posLeft; }
	int  GetTop   () { return m_posTop; }
	int  GetRight () { return m_posRight; }
	int  GetBottom() { return m_posBottom; }
	//樽
	int  GetBarrelLeft  () { return m_barrelLeft; }
	int  GetBarrelTop   () { return m_barrelTop; }
	int  GetBarrelRight () { return m_barrelRight; }
	int  GetBarrelBottom() { return m_barrelBottom; }
	//樽スピード
	void  GetBarrelSpeed(int speed) { m_barrelSpeed = speed; }
	//どっすん
	int  GetFallenLeft  () { return m_fallenLeft; }
	int  GetFallenTop   () { return m_fallenTop; }
	int  GetFallenRight () { return m_fallenRight; }
	int  GetFallenBottom() { return m_fallenBottom; }
	//どっすん範囲
	int  GetFallenRangeLeft  () { return m_fallenRangeLeft; }
	int  GetFallenRangeTop   () { return m_fallenRangeTop; }
	int  GetFallenRangeRight () { return m_fallenRangeRight; }
	int  GetFallenRangeBottom() { return m_fallenRangeBottom; }
	//どっすん2
	int  GetFallen2Left  () { return m_fallen2Left; }
	int  GetFallen2Top   () { return m_fallen2Top; }
	int  GetFallen2Right () { return m_fallen2Right; }
	int  GetFallen2Bottom() { return m_fallen2Bottom; }
	//どっすん2範囲
	int  GetFallenRange2Left  () { return m_fallenRange2Left; }
	int  GetFallenRange2Top   () { return m_fallenRange2Top; }
	int  GetFallenRange2Right () { return m_fallenRange2Right; }
	int  GetFallenRange2Bottom() { return m_fallenRange2Bottom; }

	//チャージエネミー
	int  GetChargeLeft  () { return m_chargeLeft; }
	int  GetChargeTop   () { return m_chargeTop; }
	int  GetChargeRight () { return m_chargeRight; }
	int  GetChargeBottom() { return m_chargeBottom; }

	//上下運動
	int  GetUpDownLeft  () { return m_upDownLeft; }
	int  GetUpDownTop   () { return m_upDownTop; }
	int  GetUpDownRight () { return m_upDownRight; }
	int  GetUpDownBottom() { return m_upDownBottom; }

	bool GetRushBlink() { return m_isRushBlink; }//チャージエネミーに当たると死ぬかどうか

public:

	void GetHitFall    (int fall)   { m_fall = fall; }
	void GetPos        (float posY) { m_getPos = posY; }
	void GetEnemyLadder(int num)    { m_ladderNum = num; }

	void GetHitFireBallFall(int fall)   { m_fallFireBall = fall; }
	void GetFireBallPos    (float posY) { m_getFireBallPos = posY; }

	void GetFallenRange(int range)  { m_fallenRange = range; }
	void GetFallenRange2(int range) { m_fallenRange2 = range; }

	void GetPlayerPos(Vec2 pos)  { m_playerPos = pos; }//プレイヤーの座標
	void GetRush     (bool rush) { m_isRush = rush; }

private:
	//エネミー画像
	int m_hFireBall;
	int m_hBarre;
	int m_hEnemyImage;
	int m_hNeedle;//地面用
	int m_hTiles;//画像チップ
	int m_hCave;//洞窟画像
	int m_hUpDown;//上下運動の罠画像
	//炎の玉のサイズ
	int m_posLeft;
	int m_posTop;
	int m_posRight;
	int m_posBottom;
	//樽のサイズ
	int m_barrelLeft;
	int m_barrelTop;
	int m_barrelRight;
	int m_barrelBottom;
	//樽サイズプラス
	int m_barrelSizePulsX;
	//ドッスンのサイズ
	int m_fallenLeft;
	int m_fallenTop;
	int m_fallenRight;
	int m_fallenBottom;
	//ドッスン２のサイズ
	int m_fallen2Left;
	int m_fallen2Top;
	int m_fallen2Right;
	int m_fallen2Bottom;
	//ドッスンの当たり判定のサイズ
	int m_fallenRangeLeft;
	int m_fallenRangeTop;
	int m_fallenRangeRight;
	int m_fallenRangeBottom;
	//ドッスン２の当たり判定のサイズ
	int m_fallenRange2Left;
	int m_fallenRange2Top;
	int m_fallenRange2Right;
	int m_fallenRange2Bottom;
	//尾行する敵のサイズ
	int m_chargeLeft;
	int m_chargeTop;
	int m_chargeRight;
	int m_chargeBottom;
	//上下運動する罠
	int m_upDownLeft;
	int m_upDownTop;
	int m_upDownRight;
	int m_upDownBottom;

	//ファイアボールの画像位置
	int m_fireBallImagePosX;
	int m_fireBallImagePosY;
	bool m_fireImageDirection;//画像の方向
	//樽（イノシシ）の画像位置
	int m_barreImagePosX;
	bool m_barreImageDirection;//画像の方向

	//罠の画像位置
	int m_upDownLeftImageX;
	int m_upDownLeftImageY;
	int m_upDownRad;//角度

	int m_barrelSpeed;//樽の速度

	int m_fall;//地面との判定
	int m_fallFireBall;//地面との判定

	int m_fallenRange;//落ちもの敵の範囲判定
	int m_fallenRange2;//落ちもの敵の範囲判定

	//フレームカウント類
	int m_fallenCount;
	int m_fallenCount2;
	int m_frameCountFireImage;
	int m_frameCountBarreImage;

	int m_ladderNum;
	int m_getFireBallPos;//y軸固定座標

	int m_fireRad;//角度ラジアン

	float m_fallenUpSpeed;//
	float m_fallenUpSpeed2;//

	float m_getPos;//y軸固定座標
	float m_chargeSpeed;
	float m_length;
	int   m_rushCount;

	bool m_isFirstMove;//初動動作

	bool m_isCourse;//動く向き
	bool m_isFireBallCourse;//動く向き

	bool m_isFallenDrop;
	bool m_isCanFallen;

	bool m_isFallenDrop2;
	bool m_isCanFallen2;
	bool m_isFallenUp;
	bool m_isFallenUp2;

	bool m_isUpDown;//上下どちらにいるか

	bool m_isRush;//突進する敵が動けるかどうか
	bool m_isRushBlink;//突進する敵が見えているか


	Vec2 m_pos;//ファイアーボール
	Vec2 m_barrelPos;//樽
	Vec2 m_fallenPos;//ドッスン的なやつ
	Vec2 m_fallen2Pos;//ドッスン的なやつ
	Vec2 m_chargePos;//チャージする敵
	Vec2 m_upDownPos;//上下運動する罠
	Vec2 m_vec;

	Vec2 m_playerPos;
	Vec2 m_playerSavePos;


};




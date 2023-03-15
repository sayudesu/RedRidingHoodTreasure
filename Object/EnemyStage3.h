#pragma once
#include "Vec2.h"
#include "EnemyStage1.h"

class EnemyStage3 : public EnemyStage1
{
public:
	EnemyStage3();
	virtual~EnemyStage3();

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
	int  GetBarrelLeft  () { return m_barrelLeft[0]; }
	int  GetBarrelTop   () { return m_barrelTop[0]; }
	int  GetBarrelRight () { return m_barrelRight[0]; }
	int  GetBarrelBottom() { return m_barrelBottom[0]; }
	int  GetBarrel2Left() { return m_barrelLeft[1]; }
	int  GetBarrel2Top() { return m_barrelTop[1]; }
	int  GetBarrel2Right() { return m_barrelRight[1]; }
	int  GetBarrel2Bottom() { return m_barrelBottom[1]; }
	int  GetBarrel3Left() { return m_barrelLeft[2]; }
	int  GetBarrel3Top() { return m_barrelTop[2]; }
	int  GetBarrel3Right() { return m_barrelRight[2]; }
	int  GetBarrel3Bottom() { return m_barrelBottom[2]; }
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
	//どっすん3
	int  GetFallen3Left() { return m_fallen3Left; }
	int  GetFallen3Top() { return m_fallen3Top; }
	int  GetFallen3Right() { return m_fallen3Right; }
	int  GetFallen3Bottom() { return m_fallen3Bottom; }
	//どっすん3範囲
	int  GetFallenRange3Left() { return m_fallenRange3Left; }
	int  GetFallenRange3Top() { return m_fallenRange3Top; }
	int  GetFallenRange3Right() { return m_fallenRange3Right; }
	int  GetFallenRange3Bottom() { return m_fallenRange3Bottom; }
	//どっすん4
	int  GetFallen4Left() { return m_fallen4Left; }
	int  GetFallen4Top() { return m_fallen4Top; }
	int  GetFallen4Right() { return m_fallen4Right; }
	int  GetFallen4Bottom() { return m_fallen4Bottom; }
	//どっすん4範囲
	int  GetFallenRange4Left() { return m_fallenRange4Left; }
	int  GetFallenRange4Top() { return m_fallenRange4Top; }
	int  GetFallenRange4Right() { return m_fallenRange4Right; }
	int  GetFallenRange4Bottom() { return m_fallenRange4Bottom; }

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

	int  GetUpDown2Left() { return m_upDown2Left; }
	int  GetUpDown2Top() { return m_upDown2Top; }
	int  GetUpDown2Right() { return m_upDown2Right; }
	int  GetUpDown2Bottom() { return m_upDown2Bottom; }

	int  GetUpDown3Left() { return m_upDown3Left; }
	int  GetUpDown3Top() { return m_upDown3Top; }
	int  GetUpDown3Right() { return m_upDown3Right; }
	int  GetUpDown3Bottom() { return m_upDown3Bottom; }

	bool GetRushBlink() { return m_isRushBlink; }//チャージエネミーに当たると死ぬかどうか

public:

	void GetHitFall    (int fall)   { m_fall[0] = fall; }
	void GetHitFall2(int fall) { m_fall[1] = fall; }
	void GetHitFall3(int fall) { m_fall[2] = fall; }
	void GetPos        (float posY) { m_getPos[0] = posY; }
	void GetPos2	   (float posY) { m_getPos[1] = posY; }
	void GetPos3	   (float posY) { m_getPos[2] = posY; }
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
	int m_hBarre[3];
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
	int m_barrelLeft[3];
	int m_barrelTop[3];
	int m_barrelRight[3];
	int m_barrelBottom[3];
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
	//ドッスン3のサイズ
	int m_fallen3Left;
	int m_fallen3Top;
	int m_fallen3Right;
	int m_fallen3Bottom;
	//ドッスン4のサイズ
	int m_fallen4Left;
	int m_fallen4Top;
	int m_fallen4Right;
	int m_fallen4Bottom;
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
	//ドッスン3の当たり判定のサイズ
	int m_fallenRange3Left;
	int m_fallenRange3Top;
	int m_fallenRange3Right;
	int m_fallenRange3Bottom;
	//ドッスン4の当たり判定のサイズ
	int m_fallenRange4Left;
	int m_fallenRange4Top;
	int m_fallenRange4Right;
	int m_fallenRange4Bottom;
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
	int m_upDown2Left;
	int m_upDown2Top;
	int m_upDown2Right;
	int m_upDown2Bottom;
	int m_upDown3Left;
	int m_upDown3Top;
	int m_upDown3Right;
	int m_upDown3Bottom;

	//ファイアボールの画像位置
	int m_fireBallImagePosX;
	int m_fireBallImagePosY;
	bool m_fireImageDirection;//画像の方向
	//樽（イノシシ）の画像位置
	int m_barreImagePosX[3];
	bool m_barreImageDirection[3];//画像の方向

	//罠の画像位置
	int m_upDownLeftImageX;
	int m_upDownLeftImageY;
	int m_upDownLeft2ImageX;
	int m_upDownLeft2ImageY;
	int m_upDownLeft3ImageX;
	int m_upDownLeft3ImageY;
	int m_upDownRad;//角度

	int m_barrelSpeed;//樽の速度

	int m_fall[3];//地面との判定
	int m_fallFireBall;//地面との判定

	int m_fallenRange;//落ちもの敵の範囲判定
	int m_fallenRange2;//落ちもの敵の範囲判定
	int m_fallenRange3;//落ちもの敵の範囲判定
	int m_fallenRange4;//落ちもの敵の範囲判定

	//フレームカウント類
	int m_fallenCount;
	int m_fallenCount2;
	int m_fallenCount3;
	int m_fallenCount4;
	int m_frameCountFireImage;
	int m_frameCountBarreImage[3];

	int m_ladderNum;
	int m_getFireBallPos;//y軸固定座標

	int m_fireRad;//角度ラジアン

	float m_fallenUpSpeed;//
	float m_fallenUpSpeed2;//
	float m_fallenUpSpeed3;//
	float m_fallenUpSpeed4;//

	float m_getPos[3];//y軸固定座標
	float m_chargeSpeed;
	float m_length;
	int   m_rushCount;

	bool m_isFirstMove;//初動動作

	bool m_isCourse[3];//動く向き
	bool m_isFireBallCourse;//動く向き

	bool m_isFallenDrop;
	bool m_isCanFallen;
	bool m_isFallenDrop2;
	bool m_isCanFallen2;
	bool m_isFallenDrop3;
	bool m_isCanFallen3;
	bool m_isFallenDrop4;
	bool m_isCanFallen4;

	bool m_isFallenUp;
	bool m_isFallenUp2;
	bool m_isFallenUp3;
	bool m_isFallenUp4;

	bool m_isBarreMove;//2体の敵が動くかどうか

	bool m_isUpDown;//上下どちらにいるか
	bool m_isUpDown2;//上下どちらにいるか
	bool m_isUpDown3;//上下どちらにいるか

	bool m_isRush;//突進する敵が動けるかどうか
	bool m_isRushBlink;//突進する敵が見えているか


	Vec2 m_pos;//ファイアーボール
	Vec2 m_barrelPos[3];//樽
	Vec2 m_fallenPos;//ドッスン的なやつ
	Vec2 m_fallen2Pos;//ドッスン的なやつ
	Vec2 m_fallen3Pos;//ドッスン的なやつ
	Vec2 m_fallen4Pos;//ドッスン的なやつ
	Vec2 m_chargePos;//チャージする敵
	Vec2 m_upDownPos;//上下運動する罠
	Vec2 m_upDown2Pos;//上下運動する罠
	Vec2 m_upDown3Pos;//上下運動する罠
	Vec2 m_vec[3];

	Vec2 m_playerPos;
	Vec2 m_playerSavePos;


};




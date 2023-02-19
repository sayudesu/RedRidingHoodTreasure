#pragma once
#include "Vec2.h"

class EnemyStage1
{
public:
	EnemyStage1();
	~EnemyStage1();

	void Init();
	void End();
	void Update();
	void Draw();

private:
	
	void BarrelMove();//樽の動き

	void fireBallMove();//樽の動き

	void falleMove();//どっすん動き

	void npcPos();//敵のキャラ座標取得

public:

	//ファイアーボール
	int  GetLeft()   { return m_posLeft;   }
	int  GetTop()    { return m_posTop;    }
	int  GetRight()  { return m_posRight;  }
	int  GetBottom() { return m_posBottom; }
	//樽
	int  GetBarrelLeft  () { return m_barrelLeft;   }
	int  GetBarrelTop   () { return m_barrelTop;    }
	int  GetBarrelRight () { return m_barrelRight;  }
	int  GetBarrelBottom() { return m_barrelBottom; }
	//どっすん
	int  GetFallenLeft  () { return m_fallenLeft;   }
	int  GetFallenTop   () { return m_fallenTop;    }
	int  GetFallenRight () { return m_fallenRight;  }
	int  GetFallenBottom() { return m_fallenBottom; }
	//どっすん範囲
	int  GetFallenRangeLeft  () { return m_fallenRangeLeft;   }
	int  GetFallenRangeTop   () { return m_fallenRangeTop;    }
	int  GetFallenRangeRight () { return m_fallenRangeRight;  }
	int  GetFallenRangeBottom() { return m_fallenRangeBottom; }
	
public:

	void GetHitFall(int fall  ) { m_fall = fall; }
	void GetPos    (float posY) { m_getPos = posY; }

	void GetHitFireBallFall(int fall  ) { m_fallFireBall = fall; }
	void GetFireBallPos    (float posY) { m_getFireBallPos = posY; }

	void GetEnemyLadder(int num) { m_ladderNum = num; }

private:

	int m_posLeft;
	int m_posTop;
	int m_posRight;
	int m_posBottom;

	int m_barrelLeft;
	int m_barrelTop;
	int m_barrelRight;
	int m_barrelBottom;

	int m_fallenLeft;
	int m_fallenTop;
	int m_fallenRight;
	int m_fallenBottom;

	int m_fallenRangeLeft;
	int m_fallenRangeTop;
	int m_fallenRangeRight;
	int m_fallenRangeBottom;

	int m_fall;//地面との判定
	int m_fallFireBall;//地面との判定

	int m_ladderNum;
	float m_getPos;//y軸固定座標
	int m_getFireBallPos;//y軸固定座標

	bool m_isFirstMove;//初動動作

	bool m_isCourse;//動く向き
	bool m_isFireBallCourse;//動く向き

	Vec2 m_pos;//ファイアーボール
	Vec2 m_barrelPos;//樽
	Vec2 m_fallenPos;//ドッスン的なやつ
	Vec2 m_vec;


};


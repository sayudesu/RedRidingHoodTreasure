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

	void BarrelMove();

public:

	int  GetLeft()   { return m_posLeft;   }
	int  GetTop()    { return m_posTop;    }
	int  GetRight()  { return m_posRight;  }
	int  GetBottom() { return m_posBottom; }
	//’M
	int  GetBarrelLeft  () { return m_barrelLeft;   }
	int  GetBarrelTop   () { return m_barrelTop;    }
	int  GetBarrelRight () { return m_barrelRight;  }
	int  GetBarrelBottom() { return m_barrelBottom; }

public:

	void GetHitFall(int fall) { m_isFall = fall; }
	void GetPos(int posY) { m_getPos = posY; }

private:
	int m_posLeft;
	int m_posTop;
	int m_posRight;
	int m_posBottom;

	int m_barrelLeft;
	int m_barrelTop;
	int m_barrelRight;
	int m_barrelBottom;

	int m_getPos;//y²ŒÅ’èÀ•W

	bool m_firstMove;//‰“®“®ì
	bool m_isFall;//’n–Ê‚Æ‚Ì”»’è

	Vec2 m_pos;
	Vec2 m_barrelPos;//’M
	Vec2 m_vec;


};


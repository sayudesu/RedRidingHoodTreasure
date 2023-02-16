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
public:

	int  GetLeft()   { return m_posLeft;   }
	int  GetTop()    { return m_posTop;    }
	int  GetRight()  { return m_posRight;  }
	int  GetBottom() { return m_posBottom; }

private:
	int m_posLeft;
	int m_posTop;
	int m_posRight;
	int m_posBottom;

	Vec2 m_pos;


};


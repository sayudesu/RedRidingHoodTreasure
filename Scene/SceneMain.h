#pragma once
#include "SceneBase.h"
#include "Vec2.h"


class Player;

class SceneMain : public SceneBase
{
public:
	SceneMain();
	virtual ~SceneMain();


	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:

	int m_hPlayer;
	int m_hPlayerIdle;
	Player* m_pPlayer;
};

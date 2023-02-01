#pragma once
#include "SceneBase.h"
#include "Vec2.h"


class Player;
class Enemy;

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
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;
	int m_hEnemy;

	Player* m_pPlayer;
	Enemy* m_pEnemy;
};

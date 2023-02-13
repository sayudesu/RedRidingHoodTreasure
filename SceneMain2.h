#pragma once
#include "SceneBase.h"

class DrawMapStage2;
class PlayerNew;
class Collision;
class SceneMain2 : public SceneBase
{
public:
	SceneMain2();
	virtual~SceneMain2();

	virtual void Init();
	virtual void End();
	virtual SceneBase* Update() override;
	virtual void Draw();
private:

	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;

	DrawMapStage2* m_pStage;
	PlayerNew* m_pPlayer;
	Collision* m_pCollision;
};




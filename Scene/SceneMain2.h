#pragma once
#include "SceneBase.h"

class DrawMapStage1;
class PlayerNew;
class Collision;
class SelectMenu;
class TitleCursorGame;
class GameSceneCollision;

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
	void GameClear();//ゲームをクリアした場合
private:
	//プレイヤー画像
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;

	int Color1;//選択画面の色
	int Color2;
	int Color3;

	int m_hMusicBgm1;

	bool m_isGameClear;

	DrawMapStage1* m_pStage;
	PlayerNew* m_pPlayer;
	Collision* m_pCollision;
	SelectMenu* m_pMenu;
	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
};




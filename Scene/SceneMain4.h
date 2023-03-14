#pragma once
#include "SceneBase.h"

class DrawMapStage2;
class PlayerNew;
class Collision3;
class SelectMenu;

class SceneMain4 : public SceneBase
{
public:
	SceneMain4();
	virtual~SceneMain4();

	virtual void Init();
	virtual void End();
	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	void FadeIn();//フェイドイン
	void FadeOut();//フェイドアウト
private:
	//プレイヤー画像
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;
	//エネミー画像
	int m_hEnemyFireBall;

	int m_hMusicBgm;

	float m_fadeValue;//画面の明るさ調整

	bool m_isFadeIn;//フェイドインしたかどうか
	bool m_isFadeOut;//フェイドアウトしたかどうか

	bool m_isSceneResult;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneRetry;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneTitle;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneDead;//画面が暗くなった後にシーンの切り替え
	bool m_isGameClear;

	DrawMapStage2* m_pStage;
	PlayerNew* m_pPlayer;
	Collision3* m_pCollision;
	SelectMenu* m_pMenu;
};




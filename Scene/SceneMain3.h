#pragma once
#include "SceneBase.h"

class DrawMapStage2;
class PlayerNew;
class Collision2;
class SelectMenu;
class SlideSelect;
class Fireworks;
class Chest;


class SceneMain3 : public SceneBase
{
public:
	SceneMain3();
	virtual~SceneMain3();

	virtual void Init();
	virtual void End();
	virtual SceneBase* Update() override;
	virtual void Draw();
public:
	//ゲームクリア後の選択を受け取る
	void GetSceneStage(bool scene) { m_isSceneResult = scene; }
	void GetSceneRetry(bool scene) { m_isSceneRetry = scene; }
	void GetSceneTitle(bool scene) { m_isSceneTitle = scene; }
	void GetSceneDead(bool scene) { m_isSceneDead = scene; }

	void GetMenuRetry(bool scene) { m_isSceneRetry = scene; }
	void GetMenuTitle(bool scene) { m_isSceneTitle = scene; }

private:
	void GameClear();//ゲームをクリアした場合
private:
	void FadeIn();//フェイドイン
	void FadeOut();//フェイドアウト
private:
	//プレイヤー画像
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;
	int m_hFadeImage;
	int m_hCopy;

	int m_hMusicBgm;

	int m_stageCount;//ステージが始まるまでのカウント
	int m_stageCountSeconds;

	float m_fadeValue;//画面の明るさ調整

	bool m_isStageCount;

	bool m_isFadeIn;//フェイドインしたかどうか
	bool m_isFadeOut;//フェイドアウトしたかどうか

	bool m_isSceneResult;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneRetry;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneTitle;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneDead;//画面が暗くなった後にシーンの切り替え
	bool m_isGameClear;

	DrawMapStage2* m_pStage;
	PlayerNew* m_pPlayer;
	Collision2* m_pCollision;
	SelectMenu* m_pMenu;
	SlideSelect* m_pSlidSelect;
	Fireworks* m_pFireworks;
	Chest* m_pChest;
};




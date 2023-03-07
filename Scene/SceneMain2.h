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
	void FadeIn();//フェイドイン
	void FadeOut();//フェイドアウト
private:

	//プレイヤー画像
	int m_hPlayer;
	int m_hPlayerIdle;
	int m_hPlayerLighting;
	int m_hPlayerHealthBer;
	//サウンドハンドル
	int m_hSoundSelect;//ボタンをおした場合のサウンド
	int m_hSoundSelect2;
	int m_soundCount;//サウンド再生までのカウント
	int m_soundCount2;
	int m_soundCount3;
	int m_color1;//選択画面の色
	int m_color2;
	int m_color3;

	float m_fadeValue;//画面の明るさ調整

	bool m_isFadeIn;//フェイドインしたかどうか
	bool m_isFadeOut;//フェイドアウトしたかどうか

	bool m_isSceneStage;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneRetry;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneTitle;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneDead;//画面が暗くなった後にシーンの切り替え


	int m_hMusicBgm1;

	bool m_isGameClear;

	DrawMapStage1* m_pStage;
	PlayerNew* m_pPlayer;
	Collision* m_pCollision;
	SelectMenu* m_pMenu;
	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
};




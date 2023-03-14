#pragma once
#include "SceneBase.h"
#include "Vec2.h"

class TitleCursorGame;//カーソルクラス
class GameSceneCollision;//カーソル判定
class Fireworks;//花火

class SceneResult : public SceneBase
{
public:
	SceneResult();

	virtual ~SceneResult();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();
private:
	int m_hSoundSelect;//選択時のサウンド
	int m_hSoundSelect1;//選択時のサウンド
	int m_hSoundSelect2;

	int m_hMusicBgm;//BGM用ハンドル

	int m_soundCount;//サウンド発生までのカウント
	int m_soundCount1;//サウンド発生までのカウント
	int m_soundCount2;


	int m_color1;//選択画面の色
	int m_color2;
	int m_color3;

	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
	Fireworks* m_pFireworks;
};


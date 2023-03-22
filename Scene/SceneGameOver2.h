#pragma once
#include "SceneBase.h"

class TitleCursorGame;//カーソルクラス
class GameSceneCollision;//カーソル当たり判定
class DeadDirection;

class SceneGameOver2 : public SceneBase
{
public:
	SceneGameOver2();
	virtual ~SceneGameOver2();

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

private:
	int m_hSoundSelect;//選択時のサウンド
	int m_hSoundSelect2;

	int m_hMusicBgm;//BGM用ハンドル

	int m_soundCount;//サウンド発生までのカウント
	int m_soundCount2;
	int m_color1;//選択画面の色
	int m_color2;
	int m_color3;

	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
	DeadDirection* m_pDeadDirection;
};

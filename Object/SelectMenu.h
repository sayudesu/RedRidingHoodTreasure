#pragma once

class TitleCursor;
class GameSceneCollision;

class SelectMenu
{
public:
	SelectMenu();
	virtual~SelectMenu();

	void Init();
	void Update();
	void Draw();

	bool m_isMenu;//メニューを開いているかどうか
public:
	//選択した状態を渡す
	bool SetSceneRetry() { return m_isSceneRetry; }
	bool SetSceneTitle() { return m_isSceneTitle; }
private:

	//サウンドハンドル
	int m_hSoundSelect;//ボタンをおした場合のサウンド
	int m_hSoundSelect2;

	int m_frameCount;//メニュー画面を開いた時にディレイを入れる

	int m_backGround_Y;//背景のDrawBox位置縦座標
	int m_SringBox_Y;//文字枠範囲縦座標
	int m_SringBox2_Y;//文字枠範囲縦座標
	int m_SringBox3_Y;//文字枠範囲縦座標

	int m_Sring_Y;//文字縦座標
	int m_Sring2_Y;//文字縦座標
	int m_Sring3_Y;//文字縦座標

	int m_color1;//選択画面の色
	int m_color2;
	int m_color3;

	int m_soundCount2;//サウンド再生までのカウント
	int m_soundCount3;

	bool m_isMoveStop = true;

	bool m_isSceneStage;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneRetry;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneTitle;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneDead;//画面が暗くなった後にシーンの切り替え

	TitleCursor* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
};


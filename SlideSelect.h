#pragma once

class TitleCursorGame;
class GameSceneCollision;

class SlideSelect
{
public:
	SlideSelect();
	virtual ~SlideSelect();

	void Update();//更新処理
	void Draw();//描画処理
	void Slider();//選択画面をスライド処理をする
	void Collsion();//カーソルの判定
public:
	//選択した状態を渡す
	bool SetSceneStage() { return m_isSceneStage; }
	bool SetSceneRetry() { return m_isSceneRetry; }
	bool SetSceneTitle() { return m_isSceneTitle; }
	bool SetSceneDead()  { return m_isSceneDead;  }
private:
	//サウンドハンドル
	int m_hSoundSelect;//ボタンをおした場合のサウンド
	int m_hSoundSelect2;

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

	int m_soundCount;//サウンド再生までのカウント
	int m_soundCount2;
	int m_soundCount3;

	bool m_isMoveStop;//スライド処理を止める

	bool m_isSceneStage;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneRetry;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneTitle;//画面が暗くなった後にシーンの切り替え
	bool m_isSceneDead;//画面が暗くなった後にシーンの切り替え

	TitleCursorGame* m_pCursor;
	GameSceneCollision* m_pCursorCollision;
};


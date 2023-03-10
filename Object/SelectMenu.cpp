#include <Dxlib.h>
#include "game.h"
#include "Image.h"
#include "Pad.h"
#include "SelectMenu.h"
#include "TitleCursor.h"
#include "GameSceneCollision.h"


SelectMenu::SelectMenu():
	m_hSoundSelect(-1),//ボタン押した場合のサウンド
	m_hSoundSelect2(-1),//ボタン押した場合のサウンド
	m_frameCount(0),//メニュー画面を開いた時にディレイを入れる
	m_backGround_Y(0),//背景のDrawBox位置
	m_SringBox_Y(0),//文字枠範囲
	m_SringBox2_Y(0),//文字枠範囲
	m_SringBox3_Y(0),//文字枠範囲
	m_Sring_Y(0),//文字縦座標
	m_Sring2_Y(0),//文字縦座標
	m_Sring3_Y(0),//文字縦座標
	m_color1(0),//選択画面の色
	m_color2(0),
	m_color3(0),
	m_soundCount2(0),//サウンド再生までのカウント
	m_soundCount3(0),
	m_isMenu      (false),//メニューを開いているかどうか
	m_isMoveStop  (false),//スライド処理するかどうか
	m_isSceneStage(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneRetry(false),
	m_isSceneTitle(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneDead (false),//死んだらシーン切り替え
	m_pCursor(nullptr),
	m_pCursorCollision(nullptr)
{
	m_pCursor = new TitleCursor;
	m_pCursorCollision = new GameSceneCollision;

	m_hSoundSelect = LoadSoundMem(Sound::kSelect);//ボタン押した場合のサウンドを読み込み
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);//ボタン押した場合のサウンドを読み込み
}

SelectMenu::~SelectMenu()
{
	delete m_pCursor;
	delete m_pCursorCollision;

	//サウンド削除
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
}

void SelectMenu::Init()
{

}

void SelectMenu::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	m_pCursor->GetMenu(m_isMenu);
	m_pCursor->Update();//カーソル表示
	if (m_isMenu)//メニュー表示している場合
	{
		//上から下にメニューをスライド
		if (m_backGround_Y <= 300) m_backGround_Y += SceneSelect::kSlideSpeed;
		else
		{
			if (m_SringBox_Y <= SceneSelect::kSelectTop - 10) m_SringBox_Y += SceneSelect::kSlideSpeed;
			else
			{
				if (m_SringBox2_Y <= SceneSelect::kSelectTop2 - 10) m_SringBox2_Y += SceneSelect::kSlideSpeed;
				else
				{
					if (m_SringBox3_Y <= SceneSelect::kSelectTop3 - 10) m_SringBox3_Y += SceneSelect::kSlideSpeed;
					if (m_Sring_Y <= SceneSelect::kSelectTop) m_Sring_Y += SceneSelect::kSlideSpeed;
					if (m_Sring2_Y <= SceneSelect::kSelectTop2) m_Sring2_Y += SceneSelect::kSlideSpeed;
					if (m_Sring3_Y <= SceneSelect::kSelectTop3) m_Sring3_Y += SceneSelect::kSlideSpeed;
				}
			}
		}

		m_pCursorCollision->Update();

		//カーソルが当たっていない場合の文字背景の色
		m_color1 = Color::kWhite;
		m_color2 = Color::kWhite;
		m_color3 = Color::kWhite;

		if (m_pCursorCollision->CollsionStage1())//カーソルと選択範囲に当たっていたら
		{
			m_soundCount2++;//サウンド再生までのカウント
			m_color2 = Color::kRed;//カーソルが当たっている場合の文字背景の色
			if (m_soundCount2 == 1)
			{
				PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//押している音を再生
			}
			if (padState & PAD_INPUT_2)//Xボタン
			{
				m_isSceneRetry = true;
			}
		}
		else//カーソルが選択範囲外だったら
		{
			m_soundCount2 = 0;//サウンドカウントをリセット
		}
		if (m_pCursorCollision->CollsionEnd())//カーソルと選択範囲に当たっていたら
		{
			m_soundCount3++;//サウンド再生までのカウント
			m_color3 = Color::kRed;//カーソルが当たっている場合の文字背景の色
			if (m_soundCount3 == 1)
			{
				PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//押している音を再生
			}
			if (padState & PAD_INPUT_2)//Xボタン
			{
				m_isSceneTitle = true;
			}
		}
		else//カーソルが選択範囲外だったら
		{
			m_soundCount3 = 0;//サウンドカウントをリセット
		}

		Pad::update();

		if (Pad::isTrigger(PAD_INPUT_2))//Xボタン
		{
			PlaySoundMem(m_hSoundSelect, DX_PLAYTYPE_BACK);//押している音を再生
		}

		m_frameCount++;
		if (m_frameCount >= 30)
		{
			if (padState & PAD_INPUT_10)//メニューを閉じる
			{
				m_isMoveStop = true;//閉じるスライド開始
			}
		}
	}
	else
	{
		m_frameCount++;
		if (m_frameCount >= 30)
		{
			if (padState & PAD_INPUT_10)//メニューを開く
			{
				m_isMenu = true;
				m_frameCount = 0;
				//初期化メニュー表示位置
				m_backGround_Y = 0;//背景のDrawBox位置縦座標
				m_SringBox_Y = 0;//文字枠範囲縦座標
				m_SringBox2_Y = 0;//文字枠範囲縦座標
				m_SringBox3_Y = 0;//文字枠範囲縦座標
				m_Sring_Y = 0;//文字縦座標
				m_Sring2_Y = 0;//文字縦座標
				m_Sring3_Y = 0;//文字縦座標
			}
		}
	}

	if (m_isMoveStop)//メニューを閉じる前に下にスライドさせる
	{
		if (m_backGround_Y <= Game::kScreenHeight) m_backGround_Y += SceneSelect::kSlideSpeed;
		else
		{
			//初期化
			m_isMenu = false;//メニュー画面を非表示
			m_isMoveStop = false;//スライド完了
			m_frameCount = 0;

		}
		if (m_SringBox_Y <= Game::kScreenHeight) m_SringBox_Y += SceneSelect::kSlideSpeed;
		if (m_SringBox2_Y <= Game::kScreenHeight) m_SringBox2_Y += SceneSelect::kSlideSpeed;
		if (m_SringBox3_Y <= Game::kScreenHeight) m_SringBox3_Y += SceneSelect::kSlideSpeed;
		if (m_Sring_Y <= Game::kScreenHeight) m_Sring_Y += SceneSelect::kSlideSpeed;
		if (m_Sring2_Y <= Game::kScreenHeight) m_Sring2_Y += SceneSelect::kSlideSpeed;
		if (m_Sring3_Y <= Game::kScreenHeight) m_Sring3_Y += SceneSelect::kSlideSpeed;
	}
}

void SelectMenu::Draw()
{
	//背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0x00ffff, true);//中
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0xffffff, false);//枠組み
	//文字背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//色を薄くする
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//色を戻す
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, Color::kThinBlue, false);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, Color::kThinBlue, false);
	
	DrawString(SceneSelect::kSelectLeft2 + 100, m_Sring2_Y - 35, "Retry", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft3 + 75, m_Sring3_Y - 35, "Back to Title", 0x0000ff);

	//m_pCursor->Draw();//カーソル表示
	m_pCursorCollision->Draw();
}
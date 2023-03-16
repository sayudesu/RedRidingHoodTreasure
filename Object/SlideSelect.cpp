#include <Dxlib.h>
#include "game.h"
#include "image.h"
#include "SlideSelect.h"
#include "TitleCursorGame.h"
#include "GameSceneCollision.h"
#include "Pad.h"

SlideSelect::SlideSelect():
	m_hSoundSelect(-1),//ボタン押した場合のサウンド
	m_hSoundSelect2(-1),//ボタン押した場合のサウンド
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
	m_soundCount(0),//サウンド再生までのカウント
	m_soundCount2(0),//サウンド再生までのカウント
	m_soundCount3(0),
	m_isMoveStop(false),//スライド処理するかどうか
	m_isSceneStage(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneRetry(false),
	m_isSceneTitle(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneDead(false),//死んだらシーン切り替え
	m_pCursor(nullptr),
	m_pCursorCollision(nullptr)
{

	m_isMoveStop = true;

	m_hSoundSelect = LoadSoundMem(Sound::kSelect);//ボタン押した場合のサウンドを読み込み
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);//ボタン押した場合のサウンドを読み込み

	m_pCursor = new TitleCursorGame;
	m_pCursorCollision = new GameSceneCollision;
}

SlideSelect::~SlideSelect()
{
	delete m_pCursorCollision;

	//サウンド削除
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
}

void SlideSelect::Update()
{

}

void SlideSelect::Draw()
{
	//DrawBox(SceneSelect::kSelectLeft, SceneSelect::kSelectTop, SceneSelect::kSelectRight, SceneSelect::kSelectBottom, m_color1, true);
	//DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, m_color1, true);
	//DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, m_color1, true);

	//背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0x00ffff, true);//中
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, m_backGround_Y, Game::kScreenWidth - 500, m_backGround_Y + 480, 0xffffff, false);//枠組み
	//文字背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//色を薄くする
	DrawBox(SceneSelect::kSelectLeft,  m_SringBox_Y,  SceneSelect::kSelectRight,  m_SringBox_Y  + 30, m_color1, true);
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//色を戻す
	DrawBox(SceneSelect::kSelectLeft, m_SringBox_Y, SceneSelect::kSelectRight, m_SringBox_Y + 30,	  Color::kThinBlue, false);
	DrawBox(SceneSelect::kSelectLeft2, m_SringBox2_Y, SceneSelect::kSelectRight2, m_SringBox2_Y + 30, Color::kThinBlue, false);
	DrawBox(SceneSelect::kSelectLeft3, m_SringBox3_Y, SceneSelect::kSelectRight3, m_SringBox3_Y + 30, Color::kThinBlue, false);
	//文字
	DrawString(SceneSelect::kSelectLeft + 70,  m_Sring_Y + 5, "次のステージ", 0x0000ff);//+5
	DrawString(SceneSelect::kSelectLeft2 + 85,m_Sring2_Y - 35, "もう一度", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft3 + 60, m_Sring3_Y - 35, "タイトルに戻る", 0x0000ff);



	//ここにスライドポインタ
	m_pCursor->Draw();
}

void SlideSelect::Slider()
{
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
				if (m_Sring_Y     <= SceneSelect::kSelectTop      ) m_Sring_Y     += SceneSelect::kSlideSpeed;
				if (m_Sring2_Y    <= SceneSelect::kSelectTop2     ) m_Sring2_Y    += SceneSelect::kSlideSpeed;
				if (m_Sring3_Y    <= SceneSelect::kSelectTop3     ) m_Sring3_Y    += SceneSelect::kSlideSpeed;
			}
		}
	}
}

void SlideSelect::Collsion()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	m_pCursor->Update();//カーソルの更新処理
	m_pCursorCollision->Update();//カーソルと選択範囲の当たり判定

	//カーソルが当たっていない場合の文字背景の色
	m_color1 = Color::kWhite;
	m_color2 = Color::kWhite;
	m_color3 = Color::kWhite;


	if (m_pCursorCollision->CollsionDemo())//カーソルと選択範囲に当たっていたら
	{
		m_soundCount++;//サウンド再生までのカウント
		if (m_soundCount == 1)
		{
			PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//押している音を再生
		}
		m_color1 = Color::kRed;//カーソルが当たっている場合の文字背景の色
		if (padState & PAD_INPUT_2)//Xボタン
		{
			m_isSceneStage = true;
		}
	}
	else//カーソルが選択範囲外だったら
	{
		m_soundCount = 0;//サウンドカウントをリセット
	}
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

}

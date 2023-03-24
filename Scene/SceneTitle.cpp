#include "SceneTitle.h"
#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneMain4.h"
#include "SceneResult2.h"
#include "SceneGameOver.h"
#include "SceneGameOver2.h"
#include "SceneGameOver3.h"
#include "TitleCursor.h"
#include "TitleCollision.h"
#include <DxLib.h>
#include "game.h"
#include "Image.h"
#include <Pad.h>
#include <cassert>

namespace
{
	constexpr int kAnimationFrame = 3;
	constexpr int kCharaImageRightPos = 112; //右移動

	constexpr int kColorWhite = 0x000000;//白色
	constexpr int kColorRed = 0xff0000;//赤色
}

SceneTitle::SceneTitle() :
	m_hImagePlayer(-1),
	m_hImageMap(-1),
	m_charaImagePos(0),
	m_hMusicBgm(-1),//サウンドBGM
	m_hButtonUi(-1),
	m_hTitleMainImage(-1),
	m_hSoundSelect(-1),
	m_hSoundSelect2(-1),
	m_colorA(0),
	m_colorX(0),
	m_frameCount(0),
	m_soundCount1(0),
	m_soundCount2(0),
	m_soundCount3(0),
	m_sceneChangeCountDemo(0),
	m_sceneChangeCountStage1(0),
	m_sceneChangeCountEnd(0),
	m_buttonALeft(0),
	m_buttonATop(0),
	m_buttonARigth(0),
	m_buttonABottom(0),
	m_buttonXLeft(0),
	m_buttonXTop(0),
	m_buttonXRigth(0),
	m_buttonXBottom(0),
	m_fadeValue(0.0f),
	m_imagePos(0.0f, 0.0f),
	m_isFadeIn(false),//フェイドインしたかどうか
	m_isFadeOut(false),//フェイドアウトしたかどうか
	m_isSceneStage(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneEnd(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneFocus1(false),
	m_isSceneFocus2(false),
	m_isSceneFocus3(false),
	m_pCursor(nullptr),
	m_pCollsion(nullptr),
	m_hSoundSnail (-1)
{
	m_pCursor = new TitleCursor;
	m_pCollsion = new TitleCollision;

	m_hSoundSnail = LoadSoundMem(Sound::kSnail);//かたつむりサウンド
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_hImagePlayer);
	DeleteGraph(m_hImageMap);
	DeleteGraph(m_hButtonUi);
	DeleteGraph(m_hTitleMainImage);

	StopSoundFile();//再生中のサウンドを止める
	DeleteSoundMem(m_hMusicBgm);
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
	DeleteSoundMem(m_hSoundSnail);


}

void SceneTitle::Init()
{

	m_hImagePlayer = LoadGraph(Image::kPlayerImage);
	m_hImageMap    = LoadGraph(Image::kMapFirst);
	m_hButtonUi = LoadGraph(UI::kButton);
	m_hTitleMainImage = LoadGraph(Image::kMapTitleMain);
	m_hMusicBgm = LoadSoundMem(Sound::kBgmTitle);
	m_hSoundSelect = LoadSoundMem(Sound::kSelect);
	m_hSoundSelect2 = LoadSoundMem(Sound::kSelect2);


	assert(m_hImagePlayer > -1);
	//assert(m_hImageMap > -1);
	assert(m_hButtonUi > -1);
	assert(m_hMusicBgm > -1);
	assert(m_hSoundSelect > -1);
	assert(m_hSoundSelect2 > -1);


	m_imagePos.x   = Game::kScreenWidth / 2.0f;
	m_imagePos.y   = Game::kScreenHeight / 2.0f - 250.0f;

	//Aボタン押していない状態（画像）
	m_buttonALeft = 16 + 16 + 16;
	m_buttonATop = 16 + 16;
	m_buttonARigth = 16;
	m_buttonABottom = 16 ;

	//Xボタン押していない状態（画像）
	m_buttonXLeft = 16 + 16 + 16;
	m_buttonXTop = 16 + 16 + 16;
	m_buttonXRigth = 16;
	m_buttonXBottom = 16;

	m_colorA = kColorWhite;
	m_colorX = kColorWhite;

	m_fadeValue = 255.0f;
}
void SceneTitle::End()
{
	delete m_pCollsion;
	delete m_pCursor;
}

SceneBase* SceneTitle::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (!m_isFadeIn)FadeIn();//フェイドイン
	
	if (m_isFadeIn)//画面が最大値明るくなったら
	{
		m_pCursor->Update();
		m_pCollsion->Update();
		Pad::update();
		if (padState & PAD_INPUT_1)//Aボタン押した場合
		{
			if (Pad::isTrigger(PAD_INPUT_1))//Aボタン押した場合
			{
				PlaySoundMem(m_hSoundSelect, DX_PLAYTYPE_BACK);//押している音を再生
				m_buttonXLeft = 16 + 16 + 16 + 16 + 16;//画像表示位置を変更
				m_colorX = kColorRed;//文字の色を変更
			}
		}
		else
		{
			m_buttonXLeft = 16 + 16 + 16;//画像表示位置を変更
			m_colorX = kColorWhite;//文字の色を変更
		}

		if (m_pCollsion->CollsionStage1())//シーン切り替え::ゲームプレイ
		{
			m_sceneChangeCountStage1 = 300;
			m_soundCount2++;
			if (m_soundCount2 == 1)
			{
				PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//押している音を再生
			}
			m_isSceneFocus2 = true;//フォーカスを合わせた場合
			if (padState & PAD_INPUT_1)//Aボタン押した場合
			{
				m_isSceneStage = true;//シーンを切り替え	
			}
		}
		else
		{	
			m_sceneChangeCountStage1 = 0;
			m_soundCount2 = 0;
			m_isSceneFocus2 = false;//フォーカスを外した場合
		}

		if (m_pCollsion->CollsionEnd())//シーン切り替え::デスクトップに戻る
		{
			m_sceneChangeCountEnd = 300;
			m_soundCount3++;
			if (m_soundCount3 == 1)
			{
				PlaySoundMem(m_hSoundSelect2, DX_PLAYTYPE_BACK);//押している音を再生
			}
			m_isSceneFocus3 = true;//フォーカスを合わせた場合
			if (padState & PAD_INPUT_1)
			{
				m_isSceneEnd = true;//シーンを切り替え
			}
		}
		else
		{
			m_sceneChangeCountEnd = 0;
			m_soundCount3 = 0;
			m_isSceneFocus3 = false;//フォーカスを外した場合
		}

		//右に移動アニメーション
		m_frameCount++;
		if (m_frameCount >= kAnimationFrame)
		{
			m_charaImagePos += kCharaImageRightPos;
			m_frameCount = 0;
		}
		if (m_charaImagePos == 1344)
		{
			m_charaImagePos = 0;
		}
		
	}
	ChangeVolumeSoundMem(SoundVolume::Button, m_hSoundSelect);//音量調整
	ChangeVolumeSoundMem(SoundVolume::Select, m_hSoundSelect2);//音量調整
	//サウンド
	if (CheckSoundMem(m_hMusicBgm) == 0)//鳴っていなかったら
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//サウンドを再生
		ChangeVolumeSoundMem(SoundVolume::BGM, m_hMusicBgm);//音量調整
	}

	if (m_isSceneEnd)//選択をしたら
	{
		FadeOut();
		if (m_isFadeOut)
		{
			DxLib_End();//ゲーム終了
		}
	}
	else if (m_isSceneStage)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain2);//1ステージ切り替え
		}
	}

	return this;
}

void SceneTitle::Draw()
{
	//マップを背景に描画
	DrawExtendGraph(0, 0, Game::kScreenWidth,Game::kScreenHeight, m_hTitleMainImage, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 30);//透過
	DrawBox(0 + 100,0 + 100, Game::kScreenWidth  - 100,Game::kScreenHeight  - 100, Color::kWhite, true);//背景
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	DrawRectRotaGraph(static_cast<int>(m_imagePos.x), static_cast<int>(m_imagePos.y),
		m_charaImagePos, 133, 112, 133, 18, 0, m_hImagePlayer, true, true);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//色を薄くする
	
	//ステージ1
	DrawBox(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, TitleMenu::kSelectionBottom2X, TitleMenu::kSelectionBottom2Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, TitleMenu::kSelectionBottom2X + m_sceneChangeCountStage1 - 300
		, TitleMenu::kSelectionBottom2Y, 0xff0000, true);
	//デスクトップに戻る
	DrawBox(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, TitleMenu::kSelectionBottom3X, TitleMenu::kSelectionBottom3Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, TitleMenu::kSelectionBottom3X + m_sceneChangeCountEnd - 300
		, TitleMenu::kSelectionBottom3Y, 0xff0000, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//色を戻す

	//枠組み（青色）
	//DrawBox(TitleMenu::kSelection1X - 1, TitleMenu::kSelection1Y - 1, TitleMenu::kSelectionBottom1X + 1, TitleMenu::kSelectionBottom1Y + 1, 0x0000ff, false);
	DrawBox(TitleMenu::kSelection2X -1, TitleMenu::kSelection2Y - 1, TitleMenu::kSelectionBottom2X + 1, TitleMenu::kSelectionBottom2Y + 1, 0x0000ff, false);
	DrawBox(TitleMenu::kSelection3X - 1, TitleMenu::kSelection3Y - 1, TitleMenu::kSelectionBottom3X + 1, TitleMenu::kSelectionBottom3Y + 1, 0x0000ff, false);

	if (m_isSceneFocus2)
	{

		DrawBox(TitleMenu::kSelection2X - 1, TitleMenu::kSelection2Y - 1, TitleMenu::kSelectionBottom2X + 1, TitleMenu::kSelectionBottom2Y + 1, 0xff00ff, false);
	}
	if (m_isSceneFocus3)
	{
		DrawBox(TitleMenu::kSelection3X - 1, TitleMenu::kSelection3Y - 1, TitleMenu::kSelectionBottom3X + 1, TitleMenu::kSelectionBottom3Y + 1, 0xff00ff, false);
	}

	//文字
	DrawString(TitleMenu::kSelection2X + 85, TitleMenu::kSelection2Y + 5, "ゲームスタート", 0x0000ff);
	DrawString(TitleMenu::kSelection3X + 65, TitleMenu::kSelection3Y + 15, "デスクトップに戻る", 0x0000ff);
	SetFontSize(128 + 32 + 32);//文字サイズ変更//タイトル
	//ChangeFont(Game::kFontNameJp);//フォント変更
	DrawString(Game::kScreenWidth /2 - 400 + 5, Game::kScreenHeight / 2 - 200 + 5 , "赤ずきんの財宝", 0x00000);//タイトル
	DrawString(Game::kScreenWidth /2 - 400, Game::kScreenHeight/2 - 200, "赤ずきんの財宝", 0xffff00);//タイトル
	SetFontSize(32);//文字サイス変更

	//A
	DrawRectRotaGraph(230, 300,
		m_buttonXLeft, m_buttonXTop, m_buttonXRigth, m_buttonXBottom, 5, 0, m_hButtonUi, true, false);
	DrawString(230 + 50, 290, "ジャンプ & 決定", m_colorX);

	//カーソルの位置を描画
	m_pCursor->Draw();

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void SceneTitle::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//画面が最大に明るく
	}
}

void SceneTitle::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//画面が最大に暗く
	}
}






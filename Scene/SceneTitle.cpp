#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMain2.h"
#include "SceneResult.h"
#include "TitleCursor.h"
#include "TitleCollision.h"
#include <DxLib.h>
#include "game.h"
#include "Image.h"
#include <Pad.h>

namespace
{
	constexpr int kAnimationFrame = 3;
	constexpr int kCharaImageRightPos = 112; //右移動

}

SceneTitle::SceneTitle():
	m_hImagePlayer(-1),
	m_hImageMap(-1),
	m_hMusicBgm1(-1),
	m_charaImagePos(0),
	m_frameCount(0),
	m_sceneChangeCountDemo(0),
	m_sceneChangeCountStage1(0),
	m_sceneChangeCountEnd(0),
	m_imagePos(0.0f,0.0f),
	m_isSceneFocus1(false),
	m_isSceneFocus2(false),
	m_isSceneFocus3(false),
	m_pCursor(nullptr),
	m_pCollsion(nullptr)
{
	m_pCursor = new TitleCursor;
	m_pCollsion = new TitleCollision;
}

SceneTitle::~SceneTitle()
{
	DeleteGraph(m_hImagePlayer);
	DeleteGraph(m_hImageMap);

	DeleteSoundMem(m_hMusicBgm1);
}

void SceneTitle::Init()
{
	m_hImagePlayer = LoadGraph(Image::kPlayerImage);
	m_hImageMap    = LoadGraph(Image::kMapFirst);

	m_hMusicBgm1 = LoadSoundMem(FX::kBgm1);
	PlaySoundMem(m_hMusicBgm1, DX_SOUNDTYPE_STREAMSTYLE);
	// 音量の設定
	ChangeVolumeSoundMem(255 / 3, m_hMusicBgm1);

	m_imagePos.x   = Game::kScreenWidth / 2;
	m_imagePos.y   = Game::kScreenHeight / 2 - 250;

	//m_charaImagePos = (1344 );
}
void SceneTitle::End()
{
	delete m_pCollsion;
	delete m_pCursor;
}

SceneBase* SceneTitle::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	m_pCursor->Update();
	m_pCollsion->Update();
	Pad::update();

	if (m_pCollsion->CollsionDemo())//シーン切り替え::チュートリアル
	{
		m_isSceneFocus1 = true;//フォーカスを合わせた場合
		if (padState & PAD_INPUT_2)
		{
			m_sceneChangeCountDemo += 5;//長押し時間
			if (m_sceneChangeCountDemo == 300)//長押し決定
			{
				m_sceneChangeCountDemo = 0;
				return(new SceneMain);//シーン切り替え
				//return(new SceneResult);//シーン切り替え
			}
		}
		else
		{
			m_sceneChangeCountDemo = 0;//長押しをやめたらメーターをリセット
		}
	}
	else
	{
		m_isSceneFocus1 = false;//フォーカスを外した場合
		m_sceneChangeCountDemo = 0;//メーターをリセット
	}

	if (m_pCollsion->CollsionStage1())//シーン切り替え::ゲームプレイ
	{
		m_isSceneFocus2 = true;//フォーカスを合わせた場合
		if (padState & PAD_INPUT_2)
		{
			m_sceneChangeCountStage1 += 5;//長押し時間
			if (m_sceneChangeCountStage1 == 300)//長押し決定
			{
				m_sceneChangeCountStage1 = 0;
				return(new SceneMain2);//シーン切り替え
			}
		}
		else
		{
			m_sceneChangeCountStage1 = 0;//長押しをやめたらメーターをリセット
		}
	}
	else
	{
		m_isSceneFocus2 = false;//フォーカスを外した場合
		m_sceneChangeCountStage1 = 0;//メーターをリセット
	}

	if (m_pCollsion->CollsionEnd())//シーン切り替え::デスクトップに戻る
	{
		m_isSceneFocus3 = true;//フォーカスを合わせた場合
		if (padState & PAD_INPUT_2)
		{
			m_sceneChangeCountEnd += 5;//長押し時間
			if (m_sceneChangeCountEnd == 300)//長押し決定
			{
				m_sceneChangeCountEnd = 0;
				DxLib_End();//ゲーム終了
			}
		}
		else
		{
			m_sceneChangeCountEnd = 0;//長押しをやめたらメーターをリセット
		}
	}
	else
	{
		m_isSceneFocus3 = false;//フォーカスを外した場合
		m_sceneChangeCountEnd = 0;//メーターをリセット
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

	return this;
}

void SceneTitle::Draw()
{
	DrawExtendGraph(0 + 100, 0 + 100,Game::kScreenWidth  - 100, Game::kScreenHeight - 100,m_hImageMap,true);
	DrawRectRotaGraph(m_imagePos.x, m_imagePos.y,
		m_charaImagePos, 133, 112, 133, 18, 0, m_hImagePlayer, true, true);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);//透過
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x0000ff, true);//背景
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	//チュートリアル
	DrawBox(TitleMenu::kSelection1X, TitleMenu::kSelection1Y, TitleMenu::kSelectionBottom1X, TitleMenu::kSelectionBottom1Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection1X, TitleMenu::kSelection1Y, TitleMenu::kSelectionBottom1X + m_sceneChangeCountDemo - 300
		, TitleMenu::kSelectionBottom1Y, 0xff0000, true);
	//ステージ1
	DrawBox(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, TitleMenu::kSelectionBottom2X, TitleMenu::kSelectionBottom2Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, TitleMenu::kSelectionBottom2X + m_sceneChangeCountStage1 - 300
		, TitleMenu::kSelectionBottom2Y, 0xff0000, true);
	//デスクトップに戻る
	DrawBox(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, TitleMenu::kSelectionBottom3X, TitleMenu::kSelectionBottom3Y, 0xffffff, true);
	DrawBox(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, TitleMenu::kSelectionBottom3X + m_sceneChangeCountEnd - 300
		, TitleMenu::kSelectionBottom3Y, 0xff0000, true);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	//枠組み
	DrawBox(TitleMenu::kSelection1X - 1, TitleMenu::kSelection1Y - 1, TitleMenu::kSelectionBottom1X + 1, TitleMenu::kSelectionBottom1Y + 1, 0x0000ff, false);
	DrawBox(TitleMenu::kSelection2X -1, TitleMenu::kSelection2Y - 1, TitleMenu::kSelectionBottom2X + 1, TitleMenu::kSelectionBottom2Y + 1, 0x0000ff, false);
	DrawBox(TitleMenu::kSelection3X - 1, TitleMenu::kSelection3Y - 1, TitleMenu::kSelectionBottom3X + 1, TitleMenu::kSelectionBottom3Y + 1, 0x0000ff, false);

	if (m_isSceneFocus1)
	{
		DrawBox(TitleMenu::kSelection1X - 1, TitleMenu::kSelection1Y - 1, TitleMenu::kSelectionBottom1X + 1, TitleMenu::kSelectionBottom1Y + 1, 0xff00ff, false);
	}
	if (m_isSceneFocus2)
	{

		DrawBox(TitleMenu::kSelection2X - 1, TitleMenu::kSelection2Y - 1, TitleMenu::kSelectionBottom2X + 1, TitleMenu::kSelectionBottom2Y + 1, 0xff00ff, false);
	}
	if (m_isSceneFocus3)
	{
		DrawBox(TitleMenu::kSelection3X - 1, TitleMenu::kSelection3Y - 1, TitleMenu::kSelectionBottom3X + 1, TitleMenu::kSelectionBottom3Y + 1, 0xff00ff, false);
	}

	//文字
	DrawString(TitleMenu::kSelection1X, TitleMenu::kSelection1Y, "チュートリアル", 0x0000ff);
	DrawString(TitleMenu::kSelection2X, TitleMenu::kSelection2Y, "ゲームスタート", 0x0000ff);
	DrawString(TitleMenu::kSelection3X, TitleMenu::kSelection3Y, "デスクトップに戻る", 0x0000ff);

	m_pCursor->Draw();
}






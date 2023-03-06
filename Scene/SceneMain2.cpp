#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver.h"
#include "DrawMapStage1.h"
#include "PlayerNew.h"
#include "Collision.h"
#include "SelectMenu.h"
#include "TitleCursorGame.h"
#include "GameSceneCollision.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>
#include "Pad.h"

SceneMain2::SceneMain2():
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hMusicBgm1(-1),
	Color1(0),//選択画面の色
	Color2(0),
	Color3(0),
	m_isGameClear(false),//ゲームをクリアした場合
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr),
	m_pMenu(nullptr),
	m_pCursor(nullptr),
	m_pCursorCollision(nullptr)
{

	m_pStage     = new DrawMapStage1;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision;
	m_pMenu      = new SelectMenu;
	m_pCursor    = new TitleCursorGame;
	m_pCursorCollision = new GameSceneCollision;
}

SceneMain2::~SceneMain2()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
	delete m_pCursorCollision;
}

void SceneMain2::Init()
{
	//m_pPlayer->Init();
	m_pCollision->Init();
	m_pStage->Init();
	//m_pEnemy->Init();

	// 再生形式をファイルからストリーム再生する、に設定
	//SetCreateSoundDataType(DX_SOUNDDATATYPE_FILE);
	m_hMusicBgm1 = LoadSoundMem(FX::kBgm2);
	//PlaySoundMem(m_hMusicBgm1, DX_SOUNDTYPE_STREAMSTYLE);
	// 音量の設定
	ChangeVolumeSoundMem(255 / 3 , m_hMusicBgm1);

	//プレイヤー画像
	//m_hPlayer = LoadGraph(Image::kPlayerImage);
	//m_hPlayerIdle = LoadGraph(Image::kPlayerImageIdle);
	m_hPlayerLighting = LoadGraph(Image::kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(Image::kPlayerHealthBer);

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

}

void SceneMain2::End()
{
	m_pPlayer->End();
	m_pStage->End();

	//m_pEnemy->End();
	//プレイヤー画像
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);

	DeleteSoundMem(m_hMusicBgm1);
}

SceneBase* SceneMain2::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (!m_isGameClear)//クリアしていない場合は処理する
	{
		if (!m_pMenu->m_isMenu)
		{
			m_pCollision->Update();
		}
	}

	m_pMenu->Update();


	if (m_pCollision->m_isStageClear)//ステージをクリアした場合
	{
		m_isGameClear = true;
		//return(new SceneMain3);
	}

	if (m_pCollision->m_isDeadSceneChange)//敵やトラップに当たって死んだ場合
	{
		printfDx("敵やトラップに当たって死んだ");
		return(new SceneGameOver);
	}

	if (m_isGameClear)//ゲームをクリアしたら
	{
		m_pCursor->Update();//カーソルの更新処理
		m_pCursorCollision->Update();//カーソルと選択範囲の当たり判定

		//カーソルが当たっていない場合の文字背景の色
		Color1 = Color::kWhite;
		Color2 = Color::kWhite;
		Color3 = Color::kWhite;

		if (m_pCursorCollision->CollsionDemo())//カーソルと選択範囲に当たっていたら
		{
			Color1 = Color::kRed;//カーソルが当たっている場合の文字背景の色
			if (padState & PAD_INPUT_2)//Xボタン
			{
				return(new SceneMain3);//新しいステージに移動
			}
		}
		if (m_pCursorCollision->CollsionStage1())//カーソルと選択範囲に当たっていたら
		{
			Color2 = Color::kRed;//カーソルが当たっている場合の文字背景の色
			if (padState & PAD_INPUT_2)//Xボタン
			{
				return(new SceneMain2);//同じステージを繰り返す
			}
		}
		if (m_pCursorCollision->CollsionEnd())//カーソルと選択範囲に当たっていたら
		{
			Color3 = Color::kRed;//カーソルが当たっている場合の文字背景の色
			if (padState & PAD_INPUT_2)//Xボタン
			{
				return(new SceneTitle);//タイトル画面に移動
			}
		}
	}


	if (CheckHitKey(KEY_INPUT_Z))//緊急時タイトルに戻る
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneMain2::Draw()
{
	m_pStage->Draw();//ステージを描画
	//プレイヤー、エネミーを表示
	m_pCollision->Draw();
	if (m_pMenu->m_isMenu)
	{
		m_pMenu->Draw();

	}
	if (m_isGameClear)//ゲームをクリアした場合
	{
		GameClear();//どの画面に移動するか確認
	}
	/*
	//加工用スクリーンハンドルをセットする
	SetDrawScreen(m_hTempScreen);

	m_pStage->Draw();//ステージを描画

	//プレイヤー、エネミーを表示
	m_pCollision->Draw();

	m_timer = GetRand(1000);

	SetDrawScreen(DX_SCREEN_BACK);
	DrawGraph(0, 0, m_hTempScreen, false);

	if (m_timer == 500)
	{
		GraphFilter(m_hTempScreen, DX_GRAPH_FILTER_GAUSS, 16, 1400);

		SetDrawBlendMode(DX_BLENDMODE_ADD, 192);

		DrawGraph(m_timer, 0, m_hTempScreen, false);
		GraphFilter(m_hTempScreen, DX_GRAPH_FILTER_GAUSS, 32, 1400);
		DrawGraph(m_timer, 0, m_hTempScreen, false);

		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
	*/
}

//クリアした時の選択画面表示
void SceneMain2::GameClear()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0x00ffff, true);//中
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0xffffff, false);//枠組み

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//色を薄くする
	DrawBox(SceneSelect::kSelectLeft,SceneSelect::kSelectTop,SceneSelect::kSelectRight,SceneSelect::kSelectBottom, Color1, true);
	DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, Color2, true);
	DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, Color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//色を戻す

	DrawString(SceneSelect::kSelectLeft + 75, SceneSelect::kSelectTop    + 5 , "Next Sgage", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft2 + 100, SceneSelect::kSelectTop2 + 5,  "Retry", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft3 + 45, SceneSelect::kSelectTop3  + 5,  "Back to TitleScreen", 0x0000ff);

	m_pCursor->Draw();
}

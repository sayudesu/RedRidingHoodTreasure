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
	m_hSoundSelect(-1),//ボタン押した場合のサウンド
	m_hSoundSelect2(-1),//ボタン押した場合のサウンド
	m_soundCount(-1),//サウンド再生までのカウント
	m_soundCount2(-1),//サウンド再生までのカウント
	m_soundCount3(-1),
	m_color1(0),//選択画面の色
	m_color2(0),
	m_color3(0),
	m_fadeValue(0.0f),
	m_isFadeIn(false),//フェイドインしたかどうか
	m_isFadeOut(false),//フェイドアウトしたかどうか
	m_isSceneStage(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneRetry(false),
	m_isSceneTitle(false),//画面が暗くなった後にシーンの切り替え
	m_isGameClear(false),//ゲームをクリアした場合
	m_isSceneDead(false),//死んだらシーン切り替え
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

	//サウンド削除
	DeleteSoundMem(m_hSoundSelect);
	DeleteSoundMem(m_hSoundSelect2);
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
	m_hSoundSelect = LoadSoundMem(FX::kSelect);//ボタン押した場合のサウンドを読み込み
	m_hSoundSelect2 = LoadSoundMem(FX::kSelect2);//ボタン押した場合のサウンドを読み込み
	ChangeVolumeSoundMem(255 / 3 , m_hMusicBgm1);

	//プレイヤー画像
	//m_hPlayer = LoadGraph(Image::kPlayerImage);
	//m_hPlayerIdle = LoadGraph(Image::kPlayerImageIdle);
	m_hPlayerLighting = LoadGraph(Image::kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(Image::kPlayerHealthBer);

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

	m_fadeValue = 255.0f;

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

	if (!m_isFadeIn)FadeIn();//フェイドイン
	
	if (m_isFadeIn)//画面が最大値明るくなったら
	{
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
			//printfDx("敵やトラップに当たって死んだ");
			m_isSceneDead = true;//死んだ
		}

		if (m_isGameClear)//ゲームをクリアしたら
		{
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
	}


	if (m_isSceneTitle)//選択をしたら
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneTitle);//タイトル画面に移動
		}
	}
	else if (m_isSceneStage)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain3);//新しいステージに移動
		}
	}
	else if (m_isSceneRetry)
	{
		FadeOut();
		if (m_isFadeOut) 
		{
			return(new SceneMain2);//同じステージを繰り返す
		}
	}
	else if (m_isSceneDead)//死んだ場合のシーン切り替え
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneGameOver);
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

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeValue);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
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
	//背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0x00ffff, true);//中
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawBox(500, 300, Game::kScreenWidth - 500, Game::kScreenHeight - 300, 0xffffff, false);//枠組み
	//文字背景
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);//色を薄くする
	DrawBox(SceneSelect::kSelectLeft,SceneSelect::kSelectTop,SceneSelect::kSelectRight,SceneSelect::kSelectBottom, m_color1, true);
	DrawBox(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2, SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2, m_color2, true);
	DrawBox(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3, SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3, m_color3, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);//色を戻す
	//文字
	DrawString(SceneSelect::kSelectLeft + 75, SceneSelect::kSelectTop    + 5 , "Next Sgage", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft2 + 100, SceneSelect::kSelectTop2 + 5,  "Retry", 0x0000ff);
	DrawString(SceneSelect::kSelectLeft3 + 75, SceneSelect::kSelectTop3  + 5,  "Back to Title", 0x0000ff);

	m_pCursor->Draw();
}

void SceneMain2::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//画面が最大に明るく
	}
}

void SceneMain2::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//画面が最大に暗く
	}
}
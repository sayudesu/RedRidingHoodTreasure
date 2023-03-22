#include "SceneMain2.h"
#include "SceneMain3.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver.h"
#include "DrawMapStage1.h"
#include "PlayerNew.h"
#include "Collision.h"
#include "SelectMenu.h"
#include "Fireworks.h"
#include "SlideSelect.h"
#include "Chest.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>
#include "Pad.h"

SceneMain2::SceneMain2() :
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hFadeImage(-1),
	m_hCopy(-1),
	m_hMusicBgm(-1),//BGM用ハンドル
	m_stageCount(0),//ステージが始まるまでのカウント
	m_stageCountSeconds(0),
	m_fadeValue(0.0f),
	m_isStageCount(false),
	m_isFadeIn(false),//フェイドインしたかどうか
	m_isFadeOut(false),//フェイドアウトしたかどうか
	m_isSceneStage(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneRetry(false),
	m_isSceneTitle(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneDead(false),//死んだらシーン切り替え
	m_isSceneMenuRetry(false),
	m_isSceneMenuTitle(false),
	m_isGameClear(false),
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr),
	m_pMenu(nullptr),
	m_pSlidSelect(nullptr),
	m_pFireworks(nullptr),
	m_pChest(nullptr)
{
	m_pStage     = new DrawMapStage1;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision;
	m_pMenu      = new SelectMenu;
	m_pSlidSelect = new SlideSelect;
	m_pFireworks = new Fireworks;
	m_pChest = new Chest;
}

SceneMain2::~SceneMain2()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
	delete m_pSlidSelect;
	delete m_pFireworks;
	delete m_pChest;

}

void SceneMain2::Init()
{
	m_pCollision->Init();
	m_pStage->Init();
	m_pFireworks->Init();
	m_hMusicBgm = LoadSoundMem(Sound::kBgmStage);
	m_hCopy = LoadGraph(Image::kCountTime1);
	m_hFadeImage = LoadGraph(Image::kFade);//フェイド処理

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

	m_stageCount = 60 * 3;//ステージ開始カウント
	m_fadeValue = 255.0f;//画面の色

}

void SceneMain2::End()
{
	m_pPlayer->End();
	m_pStage->End();
	m_pFireworks->End();

	//プレイヤー画像
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hCopy);

	StopSoundFile();//再生中のサウンドを止める
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneMain2::Update()
{
	//ゲームクリア後の選択を受け取る
	GetSceneStage(m_pSlidSelect->SetSceneStage());
	GetSceneRetry(m_pSlidSelect->SetSceneRetry());
	GetSceneTitle(m_pSlidSelect->SetSceneTitle());
	GetSceneDead(m_pSlidSelect->SetSceneDead());

	GetMenuRetry(m_pMenu->SetSceneRetry());
	GetMenuTitle(m_pMenu->SetSceneTitle());

	if (!m_isFadeIn)FadeIn();//フェイドイン
	if (m_stageCount == 60 * 3)
	{
		m_stageCountSeconds = 3;
	}
	if (m_stageCount == 60 * 2)
	{
		m_stageCountSeconds = 2;
	}
	if (m_stageCount == 60)
	{
		m_stageCountSeconds = 1;
	}

	if (m_isFadeIn)//画面が最大値明るくなったら
	{
		if (m_stageCount == 0)
		{
			m_isStageCount = false;
			if (!m_isGameClear)//クリアしていない場合は処理する
			{
				if (!m_pMenu->m_isMenu)//メニューを開いていない場合
				{
					m_pCollision->Update();
				}
			}
		}
		else
		{
			m_stageCount--;
			m_isStageCount = true;
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
			//ここにカーソル判定処理
			m_pSlidSelect->Collsion();
		}
	}
	
	//サウンド
	if (CheckSoundMem(m_hMusicBgm) == 0)//鳴っていなかったら
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//サウンドを再生
		ChangeVolumeSoundMem(SoundVolume::BGM, m_hMusicBgm);//音量調整
	}

	if (m_isSceneStage)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain3);//新しいステージに移動
		}
	}
	else if (/*m_pMenu->SetSceneRetry() ||*/m_isSceneMenuRetry|| m_isSceneRetry)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain2);//同じステージを繰り返す
		}
	}
	else if (/*m_pMenu->SetSceneTitle() ||*/m_isSceneMenuTitle|| m_isSceneTitle)//選択をしたら
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneTitle);//タイトル画面に移動
		}
	}

	if (m_isSceneDead)//死んだ場合のシーン切り替え
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

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
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
	if (m_stageCount != 0)
	{
		DrawExtendGraph(0,0, Game::kScreenWidth, Game::kScreenHeight, m_hCopy, true);
	}
	if (m_isStageCount)
	{
		SetFontSize(128 + 32 + 32);//文字サイズ変更//タイトル
		DrawFormatString(Game::kScreenWidth/2, Game::kScreenHeight/2, 0xffffff, "%d", m_stageCountSeconds);
		SetFontSize(32);//文字サイズ変更//タイトル
	}
}

//クリアした時の選択画面表示
void SceneMain2::GameClear()
{
	m_pFireworks->Update();
	m_pSlidSelect->Slider();//選択画面の処理

	m_pFireworks->Draw();
	SetFontSize(128 + 32 + 32);//文字サイズ変更//タイトル
	DrawString(SceneSelect::kSelectLeft - 200 + 2, SceneSelect::kSelectTop - 300 + 2, "ゲームクリア", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft - 200, SceneSelect::kSelectTop - 300, "ゲームクリア", Color::kYellow);
	SetFontSize(32);//文字サイズ変更//タイトル
	m_pSlidSelect->Draw();//描画処理

	m_pChest->Stage1Draw();
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
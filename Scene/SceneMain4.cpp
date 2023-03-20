#include "SceneMain4.h"
#include "SceneTitle.h"
#include "SceneResult2.h"
#include "SceneGameOver3.h"
#include "DrawMapStage2.h"
#include "PlayerNew.h"
#include "Collision3.h"
#include "SelectMenu.h"
#include "SlideSelect.h"
#include "Fireworks.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>

SceneMain4::SceneMain4():
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hFadeImage(-1),
	m_hCopy(-1),
	m_hMusicBgm(-1),
	m_stageCount(0),//ステージが始まるまでのカウント
	m_stageCountSeconds(0),
	m_fadeValue(0.0f),
	m_isFadeIn(false),//フェイドインしたかどうか
	m_isFadeOut(false),//フェイドアウトしたかどうか
	m_isSceneResult(false),//画面が暗くなった後にシーンの切り替え
	m_isSceneRetry(false),
	m_isSceneTitle(false),//画面が暗くなった後にシーンの切り替え
	m_isGameClear(false),//ゲームをクリアした場合
	m_isSceneDead(false),//死んだらシーン切り替え
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr),
	m_pMenu(nullptr),
	m_pSlidSelect(nullptr),
	m_pFireworks(nullptr)
{
	m_pStage     = new DrawMapStage2;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision3;
	m_pMenu      = new SelectMenu;
	m_pSlidSelect = new SlideSelect;
	m_pFireworks = new Fireworks;
}

SceneMain4::~SceneMain4()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
}

void SceneMain4::Init()
{
	
	m_pCollision->Init();
	m_pStage->Init();

	m_hMusicBgm = LoadSoundMem(Sound::kBgmStage2);//サウンド読み込み

	m_hFadeImage = LoadGraph(Image::kFade);//フェイド処理
	m_hCopy = LoadGraph(Image::kCountTime3);

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

	m_stageCount = 60 * 3;//ステージ開始カウント
	m_fadeValue = 255.0f;
}

void SceneMain4::End()
{
	m_pPlayer->End();
	m_pStage->End();

	//m_pEnemy->End();
	//プレイヤー画像
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hCopy);
	StopSoundFile();//再生中のサウンドを止める
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneMain4::Update()
{
	//ゲームクリア後の選択を受け取る
	GetSceneStage(m_pSlidSelect->SetSceneStage());
	GetSceneRetry(m_pSlidSelect->SetSceneRetry());
	GetSceneTitle(m_pSlidSelect->SetSceneTitle());
	GetSceneDead(m_pSlidSelect->SetSceneDead());

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
		if (!m_isGameClear)//クリアしていない場合は処理する
		{
			if (m_stageCount == 0)
			{
				m_isStageCount = false;
				if (!m_pMenu->m_isMenu)
				{
					m_pCollision->Update();
				}
			}
			else
			{
				m_stageCount--;
				m_isStageCount = true;
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

	if (m_isSceneTitle)//選択をしたら
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneTitle);//タイトル画面に移動
		}
	}
	if (m_isSceneResult||m_isGameClear)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneResult2);//新しいステージに移動
		}
	}
	else if (m_isSceneRetry)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain4);//同じステージを繰り返す
		}
	}
	else if (m_isSceneDead)//死んだ場合のシーン切り替え
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneGameOver3);
		}
	}

	if (CheckHitKey(KEY_INPUT_Z))//緊急時タイトルに戻る
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneMain4::Draw()
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
		//GameClear();//どの画面に移動するか確認
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, static_cast<int>(m_fadeValue));
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

	if (m_stageCount != 0)
	{
		DrawExtendGraph(0, 0, Game::kScreenWidth, Game::kScreenHeight, m_hCopy, true);
	}
	if (m_isStageCount)
	{
		SetFontSize(128 + 32 + 32);//文字サイズ変更//タイトル
		DrawFormatString(Game::kScreenWidth / 2, Game::kScreenHeight / 2, 0xffffff, "%d", m_stageCountSeconds);
		SetFontSize(32);//文字サイズ変更//タイトル
	}

}

void SceneMain4::GameClear()
{
	m_pFireworks->Update();
	//m_pSlidSelect->Slider();//選択画面の処理

	m_pFireworks->Draw();
	SetFontSize(128 + 32 + 32);//文字サイズ変更//タイトル
	DrawString(SceneSelect::kSelectLeft - 200 + 2, SceneSelect::kSelectTop - 300 + 2, "ゲームクリア", Color::kBlue);
	DrawString(SceneSelect::kSelectLeft - 200, SceneSelect::kSelectTop - 300, "ゲームクリア", Color::kYellow);
	SetFontSize(32);//文字サイズ変更//タイトル
	//m_pSlidSelect->Draw();//描画処理
}

void SceneMain4::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//画面が最大に明るく
	}
}

void SceneMain4::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//画面が最大に暗く
	}
}
#include "SceneMain3.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver2.h"
#include "DrawMapStage2.h"
#include "PlayerNew.h"
#include "Collision2.h"
#include "SelectMenu.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>

SceneMain3::SceneMain3():
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemyFireBall(-1),
	m_hMusicBgm(-1),
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
	m_pMenu(nullptr)
{
	m_pStage     = new DrawMapStage2;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision2;
	m_pMenu      = new SelectMenu;
}

SceneMain3::~SceneMain3()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pMenu;
}

void SceneMain3::Init()
{
	
	m_pCollision->Init();
	m_pStage->Init();

	m_hMusicBgm = LoadSoundMem(Sound::kBgmStage2);//サウンド読み込み

	m_hPlayerLighting = LoadGraph(Image::kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(Image::kPlayerHealthBer);
	//エネミー画像
	m_hEnemyFireBall = LoadGraph(Image::kEnemyFireBall);

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);

	m_fadeValue = 255.0f;
}

void SceneMain3::End()
{
	m_pPlayer->End();
	m_pStage->End();

	//m_pEnemy->End();
	//プレイヤー画像
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	//エネミー画像
	DeleteGraph(m_hEnemyFireBall);

	StopSoundFile();//再生中のサウンドを止める
	DeleteSoundMem(m_hMusicBgm);
}

SceneBase* SceneMain3::Update()
{

	if (!m_isFadeIn)FadeIn();//フェイドイン

	if (m_isFadeIn)//画面が最大値明るくなったら
	{
		if (!m_pMenu->m_isMenu)//メニューを開いて無かったら
		{
			m_pCollision->Update();
		}

		m_pMenu->Update();//メニューの状態を更新しながら確認

		if (m_pCollision->m_isStageClear)//ステージをクリアした場合
		{
			m_isSceneResult = true;
			//return(new SceneResult);
		}

		if (m_pCollision->m_isDeadSceneChange)//敵やトラップに当たって死んだ場合
		{
			m_isSceneDead = true;
			//printfDx("敵やトラップに当たって死んだ");
			//return(new SceneGameOver2);
		}
	}

	//サウンド
	if (CheckSoundMem(m_hMusicBgm) == 0)//鳴っていなかったら
	{
		PlaySoundMem(m_hMusicBgm, DX_PLAYTYPE_BACK);//サウンドを再生
		ChangeVolumeSoundMem(100, m_hMusicBgm);//音量調整
	}

	if (m_isSceneResult)
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneResult);//新しいステージに移動
		}
	}
	else if (m_isSceneDead)//死んだ場合のシーン切り替え
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneGameOver2);
		}
	}
	else if (m_pMenu->SetSceneRetry())//繰り返す場合のシーン切り替え
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneMain3);
		}
	}
	else if (m_pMenu->SetSceneTitle())//タイトルに戻る場合のシーン切り替え
	{
		FadeOut();
		if (m_isFadeOut)
		{
			return(new SceneTitle);
		}
	}

	if (CheckHitKey(KEY_INPUT_Z))
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneMain3::Draw()
{
	m_pStage->Draw();//ステージを描画
	//プレイヤー、エネミーを表示
	m_pCollision->Draw();

	if (m_pMenu->m_isMenu)
	{
		m_pMenu->Draw();
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_fadeValue);
	DrawBox(0, 0, Game::kScreenWidth, Game::kScreenHeight, 0x000000, true);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void SceneMain3::FadeIn()
{
	m_fadeValue -= Scene::kFadeSpeed;
	if (m_fadeValue <= 0)
	{
		m_isFadeIn = true;//画面が最大に明るく
	}
}

void SceneMain3::FadeOut()
{
	m_fadeValue += Scene::kFadeSpeed;
	if (m_fadeValue >= 255)
	{
		m_isFadeOut = true;//画面が最大に暗く
	}
}
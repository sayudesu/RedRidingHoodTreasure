#include "SceneMain2.h"
#include "SceneTitle.h"
#include "SceneResult.h"
#include "SceneGameOver.h"
#include "DrawMapStage2.h"
#include "PlayerNew.h"
#include "Collision.h"
#include "EnemyStage1.h"
#include "PlayerAnimation.h"
#include "game.h"
#include "Image.h"
#include <Dxlib.h>

SceneMain2::SceneMain2():
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemyFireBall(-1),
	m_hMusicBgm1(-1),
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr),
	m_pEnemy(nullptr)
{
	m_pStage     = new DrawMapStage2;
	m_pPlayer    = new PlayerNew;
	m_pCollision = new Collision;
	m_pEnemy     = new EnemyStage1;
}

SceneMain2::~SceneMain2()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
	delete m_pEnemy;
}

void SceneMain2::Init()
{
	m_pPlayer->Init();
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
	//エネミー画像
	m_hEnemyFireBall = LoadGraph(Image::kEnemyFireBall);

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);
	//エネミー画像
	m_pEnemy->SetHandleFireBall(m_hEnemyFireBall);
}

void SceneMain2::End()
{
	m_pPlayer->End();
	m_pStage->End();

	//m_pEnemy->End();
	//プレイヤー画像
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	//エネミー画像
	DeleteGraph(m_hEnemyFireBall);

	DeleteSoundMem(m_hMusicBgm1);
}

SceneBase* SceneMain2::Update()
{
	m_pCollision->Update();
	//m_pEnemy->Update();
	//m_pPlayer->Update();

	if (m_pCollision->m_isStageClear)//ステージをクリアした場合
	{
		return(new SceneResult);
	}

	if (m_pPlayer->SetDead())//敵やトラップに当たって死んだ場合
	{
		printfDx("敵やトラップに当たって死んだ");
		return(new SceneGameOver);
	}

	if (CheckHitKey(KEY_INPUT_Z))
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
	//m_pEnemy->Draw();
	//m_pAnimation->Draw();//アニメーションを再生
}

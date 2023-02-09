#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneMain2.h"
#include "SceneResult.h"
#include "PlayerMapMove.h"
//#include "Player.h"
#include "Enemy.h"
#include "ShotBase.h"
#include "game.h"
#include <DxLib.h>
#include <Image.h>

SceneMain::SceneMain() :
	m_test(0),
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemy(-1),
	m_hMapFirst(-1),
	m_hMapSecond(-1),
	m_hMapThird(-1),
	m_hMapFourth(-1),
	m_hMapFifth(-1),
	m_hMapChip(-1),
	m_hMapChipSecond(-1),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr)
{
	m_pPlayer = new PlayerMapMove;
	//m_pPlayer = new Player;
	m_pEnemy = new Enemy;
}

SceneMain::~SceneMain()
{
	delete m_pPlayer;
	delete m_pEnemy;
}

void SceneMain::Init()
{
	m_pPlayer->Init();
	
	//プレイヤー画像
	m_hPlayer = LoadGraph(Image::kPlayerImage);
	m_hPlayerIdle = LoadGraph(Image::kPlayerImageIdle);
	m_hPlayerLighting = LoadGraph(Image::kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(Image::kPlayerHealthBer);

	//エネミー画像
	m_hEnemy = LoadGraph(Image::kEnemyEye);

	//マップ画像
	m_hMapFirst  = LoadGraph(Image::kMapFirst);
	m_hMapSecond = LoadGraph(Image::kMapSecond);
	m_hMapThird  = LoadGraph(Image::kMapThird);
	m_hMapFourth = LoadGraph(Image::kMapFourth);
	m_hMapFifth = LoadGraph(Image::kMapFifth);
	m_hMapChip = LoadGraph(Image::kMapChip);
	m_hMapChipSecond = LoadGraph(Image::kMapChipSecond);

	//プレイヤー画像
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);
	m_pPlayer->SetHandleLighting(m_hPlayerLighting);
	m_pPlayer->SetHandleHealthBer(m_hPlayerHealthBer);

	//エネミー画像
	m_pEnemy->SetHandle(m_hEnemy);

	//マップ画像
	m_pPlayer->SetHandleMapFirst (m_hMapFirst);
	m_pPlayer->SetHandleMapSecond(m_hMapSecond);
	m_pPlayer->SetHandleMapThird (m_hMapThird);
	m_pPlayer->SetHandleMapFourth(m_hMapFourth);
	m_pPlayer->SetHandleMapFifth(m_hMapFifth);
	m_pPlayer->SetHnadleMapChip(m_hMapChip);
	m_pPlayer->SetHnadleMapChipSecond(m_hMapChipSecond);

}
void SceneMain::End()
{
	m_pPlayer->End();
	m_pEnemy->End();

	DeleteGraph(m_test);

	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hPlayerLighting);
	DeleteGraph(m_hPlayerHealthBer);

	DeleteGraph(m_hEnemy);

	DeleteGraph(m_hMapFirst);
	DeleteGraph(m_hMapSecond);
	DeleteGraph(m_hMapThird);
	DeleteGraph(m_hMapFourth);
	DeleteGraph(m_hMapFifth);

	DeleteGraph(m_hMapChip);
	DeleteGraph(m_hMapChipSecond);
}

SceneBase* SceneMain::Update()
{

	m_pPlayer->Update();
	if(m_pPlayer->GetLifeEnemy())
	{
		m_pEnemy->Update();
	}

	if (m_pPlayer->GetStageClear())
	{
		return(new SceneMain2);
	}

	if (m_pPlayer->IsDead())
	{
		return(new SceneTitle);
	}
	else if (m_pPlayer->IsTitle())
	{
		return(new SceneMain);
	}

	return this;
}

void SceneMain::Draw()
{

	//SetDrawScreen(m_test);


	m_pPlayer->Draw();

	if (m_pPlayer->GetLifeEnemy())
	{
		m_pEnemy->Draw();
	}

	//SetDrawScreen(DX_SCREEN_BACK);

	//int shakeX = 0; /*GetRand(4) - 2; */
	//int shakeY = 0;/*GetRand(4) - 2; */
//	DrawGraph(shakeX, shakeY, m_test, true);
	

}

//敵とプレイヤーの衝突判定
bool SceneMain::Check(int firstLeft, int firstTop, int firstRight, int firstBottom,
	int SecondLeft, int SecondTop, int SecondRight, int SecondBottom)
{
	if ((firstRight > SecondLeft) &&
		(firstLeft < SecondRight))
	{
		if ((firstBottom > SecondTop) &&
			(firstTop < SecondBottom))
		{
			printfDx("判定有効");
			return true;
		}
	}
	return false;
}








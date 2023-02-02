#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "Player.h"
#include "Enemy.h"
#include "game.h"
#include <DxLib.h>

namespace
{
	//プレイヤー
	const char* const kPlayerImage = "Data/red hood itch free Copy-Sheet.png";
	const char* const kPlayerImageIdle = "Data/idle sheet-Sheet.png";
	//光
	const char* const kPlayerLighting = "Data/lighting2.png";
	//体力
	const char* const kPlayerHealthBer = "Data/HP2.png";
	//マップ
	const char* const kMapFirst  = "Data/Map/plx-1.png";
	const char* const kMapSecond = "Data/Map/plx-2.png";
	const char* const kMapThird  = "Data/Map/plx-3.png";
	const char* const kMapFourth = "Data/Map/plx-4.png";
	//マップチップ
	const char* const kMapChip = "Data/Map/jungle tileset.png";

}


SceneMain::SceneMain() :
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemy(-1),
	m_hMapFirst(-1),
	m_hMapSecond(-1),
	m_hMapThird(-1),
	m_hMapFourth(-1),
	m_hMapChip(-1),
	m_pPlayer(nullptr),
	m_pEnemy(nullptr)
{
	m_pPlayer = new Player;
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
	m_pEnemy->Init();

	m_hPlayer = LoadGraph(kPlayerImage);
	m_hPlayerIdle = LoadGraph(kPlayerImageIdle);
	m_hPlayerLighting = LoadGraph(kPlayerLighting);
	m_hPlayerHealthBer = LoadGraph(kPlayerHealthBer);

	m_hEnemy = LoadGraph(kPlayerImage);

	m_hMapFirst  = LoadGraph(kMapFirst);
	m_hMapSecond = LoadGraph(kMapSecond);
	m_hMapThird  = LoadGraph(kMapThird);
	m_hMapFourth = LoadGraph(kMapFourth);

	m_hMapChip = LoadGraph(kMapChip);

	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);
	m_pPlayer->SetHandleLighting(m_hPlayerLighting);
	m_pPlayer->SetHandleHealthBer(m_hPlayerHealthBer);

	m_pEnemy->SetHandle(m_hEnemy);

	m_pPlayer->SetHandleMapFirst (m_hMapFirst);
	m_pPlayer->SetHandleMapSecond(m_hMapSecond);
	m_pPlayer->SetHandleMapThird (m_hMapThird);
	m_pPlayer->SetHandleMapFourth(m_hMapFourth);

	m_pPlayer->SetHnadleMapChip(m_hMapChip);
}
void SceneMain::End()
{
	m_pPlayer->End();
	m_pEnemy->End();
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
	DeleteGraph(m_hPlayerLighting);
	DeleteGraph(m_hPlayerHealthBer);

	DeleteGraph(m_hEnemy);

	DeleteGraph(m_hMapFirst);
	DeleteGraph(m_hMapSecond);
	DeleteGraph(m_hMapThird);
	DeleteGraph(m_hMapFourth);

	DeleteGraph(m_hMapChip);
}

SceneBase* SceneMain::Update()
{

	m_pPlayer->Update();
	m_pEnemy->Update();
	return this;
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
	m_pEnemy->Draw();
}

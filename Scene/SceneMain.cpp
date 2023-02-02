#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "Player.h"
#include "Enemy.h"
#include "game.h"
#include <DxLib.h>

namespace
{
	const char* const kPlayerImage = "Data/red hood itch free Copy-Sheet.png";
	const char* const kPlayerImageIdle = "Data/idle sheet-Sheet.png";
	const char* const kPlayerLighting = "Data/lighting2.png";
	const char* const kPlayerHealthBer = "Data/HP2.png";
}


SceneMain::SceneMain() :
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_hPlayerLighting(-1),
	m_hPlayerHealthBer(-1),
	m_hEnemy(-1),
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

	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);
	m_pPlayer->SetHandleLighting(m_hPlayerLighting);
	m_pPlayer->SetHandleHealthBer(m_hPlayerHealthBer);
	m_pEnemy->SetHandle(m_hEnemy);
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

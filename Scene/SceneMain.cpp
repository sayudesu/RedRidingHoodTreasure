#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "Player.h"
#include "game.h"
#include <DxLib.h>

namespace
{
	const char* const kPlayerImage = "Data/red hood itch free Copy-Sheet.png";
	const char* const kPlayerImageIdle = "Data/idle sheet-Sheet.png";
}


SceneMain::SceneMain() :
	m_hPlayer(-1),
	m_hPlayerIdle(-1),
	m_pPlayer(nullptr)
{
	m_pPlayer = new Player;
}

SceneMain::~SceneMain()
{
	delete m_pPlayer;
}

void SceneMain::Init()
{
	m_pPlayer->Init();

	m_hPlayer = LoadGraph(kPlayerImage);
	m_hPlayerIdle = LoadGraph(kPlayerImageIdle);
	m_pPlayer->SetHandle(m_hPlayer);
	m_pPlayer->SetHandleIdle(m_hPlayerIdle);
}
void SceneMain::End()
{
	m_pPlayer->End();
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerIdle);
}

SceneBase* SceneMain::Update()
{

	m_pPlayer->Update();

	return this;
}

void SceneMain::Draw()
{
	m_pPlayer->Draw();
}

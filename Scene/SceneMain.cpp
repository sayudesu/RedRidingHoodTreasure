#include "SceneTitle.h"
#include "SceneMain.h"
#include "SceneResult.h"
#include "Player.h"
#include "game.h"
#include <DxLib.h>

namespace
{
	const char* const kPlayerImage = "Data/run turnaround-Sheet.png";
}


SceneMain::SceneMain() :
	m_hPlayer(-1),
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
	m_pPlayer->SetHandle(m_hPlayer);
}
void SceneMain::End()
{
	m_pPlayer->End();
	DeleteGraph(m_hPlayer);
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

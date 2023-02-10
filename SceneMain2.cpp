#include "SceneMain2.h"
#include "SceneTitle.h"
#include "DrawMapStage2.h"
#include "PlayerNew.h"
#include "Collision.h"
#include "game.h"
#include <Dxlib.h>

SceneMain2::SceneMain2():
	m_pStage(nullptr),
	m_pPlayer(nullptr),
	m_pCollision(nullptr)
{
	m_pStage = new DrawMapStage2;
	m_pPlayer = new PlayerNew;
	m_pCollision = new Collision;
}

SceneMain2::~SceneMain2()
{
	delete m_pStage;
	delete m_pPlayer;
	delete m_pCollision;
}

void SceneMain2::Init()
{
	m_pPlayer->Init();
	m_pCollision->Init();
}

void SceneMain2::End()
{
	m_pPlayer->End();
}

SceneBase* SceneMain2::Update()
{
	m_pPlayer->Update();
	m_pCollision->Update();

	m_pPlayer->GetGravity(m_pCollision->GetGravity());

	if (CheckHitKey(KEY_INPUT_Z))
	{
		return(new SceneTitle);
	}
	return this;
}

void SceneMain2::Draw()
{
	m_pStage->Draw();
	m_pPlayer->Draw();
	m_pCollision->Draw();
}

#include "ShotBase.h"
#include "game.h"
#include <DxLib.h>

ShotBase::ShotBase() :
	m_isExist(false),
	m_rad(0.0f),
	m_posSave(0.0f, 0.0f),
	m_pos(0.0f,0.0f),
	m_vec(0.0f, 0.0f),
	m_size(0.0f, 0.0f)
{
	m_size.x = 10.0f;
	m_size.y = 5.0f;
}

ShotBase::~ShotBase()
{
}

void ShotBase::Init()
{
}

void ShotBase::Start(Vec2 pos)
{
	m_isExist = true;

	//pos.x = 0.0f;
	//pos.y = 0.0f;

	m_pos = pos;
}

void ShotBase::Update()
{
	//コントローラー操作
	DINPUT_JOYSTATE input;
	const int padState = GetJoypadDirectInputState(DX_INPUT_PAD1, &input);

	if (input.Buttons[5] >= 10) {

		m_posSave.x = input.Rx;
		m_posSave.y = input.Ry;
	}

	m_pos.x += cosf(m_rad) * 50;
	m_pos.y += sinf(m_rad) * 50;

	/*
	m_pos.x += m_posSave.x / 10;
	m_pos.y += m_posSave.y / 10;
	*/


	OutSide();
	if (!m_isExist) return;
}

void ShotBase::Draw()
{
	DrawOval((int)m_pos.x, (int)m_pos.y, m_size.x, m_size.y, GetColor(255,255,255), true);
	DrawCircle(m_pos.x, m_pos.y, 100, GetColor(255, 0, 0), true);
}

void ShotBase::OutSide()
{
	DrawString(Game::kScreenWidth / 2 , Game::kScreenHeight / 2, "弾削除", 0xff000a);

	if (m_pos.x <= 0)
	{
		m_isExist = false;

	}
	if (m_pos.x >= Game::kScreenWidth)
	{
		m_isExist = false;
	}
	if (m_pos.y <= 0)
	{
		m_isExist = false;
	}
	if (m_pos.y >= Game::kScreenHeight)
	{
		m_isExist = false;
	}
}

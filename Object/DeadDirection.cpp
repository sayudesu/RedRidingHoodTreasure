#include "DeadDirection.h"
#include "Image.h"
#include <Dxlib.h>

DeadDirection::DeadDirection():
	m_hPlayer(0),
	m_hPlayerDead(0),
	m_hEffectScreen(0),
	m_snowCount(0),
	m_snowDrop(0),
	m_left(0),
	m_top(0),
	m_angle(0.0f),
	m_snowPos()
{
	m_hEffectScreen = MakeScreen(Game::kScreenWidth, Game::kScreenHeight, true);
	for (int i = 0; i < Dead::kSnowNum; i++)
	{
		m_snowPos[i] = { static_cast<float>(GetRand(Game::kScreenWidth)),0.0f};
	}

	m_left = Game::kScreenWidth / 2;
	m_top = Game::kScreenHeight / 2;

	m_hPlayer = LoadGraph(Image::kPlayerImage);
	m_hPlayerDead = DerivationGraph(112 + 8,133 * 10 + 32,112,133, m_hPlayer);//�n�ʉ摜����ꕔ�𒊏o
	//�摜�̂P�L�������̑傫��
	//��112
	//�c133
}

DeadDirection::~DeadDirection()
{
	DeleteGraph(m_hPlayer);
	DeleteGraph(m_hPlayerDead);
}

void DeadDirection::Update()
{
	m_angle += 0.001f;
	if (m_snowDrop != Dead::kSnowNum)
	{
		m_snowCount++;
	}

	if (m_snowCount == 40)
	{
		m_snowDrop++;
		m_snowCount = 0;
	}

	for (int i = 0; i < m_snowDrop; i++)
	{
		m_snowPos[i].y += Dead::kSnowSpeed;//���ɗ��Ƃ�
		m_snowPos[i].x -= 3.0f;//����������

		if (m_snowPos[i].y > Game::kScreenHeight||
			m_snowPos[i].x < 0)//��ʊO�܂ŗ��������ɖ߂�X���������_���ɂ܂����ɗ��Ƃ�
		{
			m_snowPos[i] = { static_cast<float>(GetRand(Game::kScreenWidth)),0.0f};
		}
	}

}

void DeadDirection::DrawPlayerDead()
{

}

void DeadDirection::Draw()
{

	SetDrawScreen(m_hEffectScreen);
	//ClearDrawScreen();
	BeginAADraw();

	for (int i = 0; i < m_snowDrop; i++)
	{
		DrawCircleAA(m_snowPos[i].x, m_snowPos[i].y, 10.0f, 32, 0xff0000, true);
		//DrawCircleAA(m_snowPos[i].x, m_snowPos[i].y, 10.0f, 32, GetColor(GetRand(255), GetRand(255), GetRand(255)), true);
	}

	EndAADraw();

	SetDrawScreen(DX_SCREEN_BACK);
	// ��ʂ̃N���A
	ClearDrawScreen();
	DrawRotaGraph(m_left,m_top,
		20, m_angle,
		m_hPlayerDead,true, false);
	//DrawExtendGraph(m_left, m_top, m_right, m_bottom, m_hPlayerDead, true);//����m�F�p
	//DrawGraph(100, 100, m_hPlayerDead, true);//DX_SCREEN_BACK

	//���Z��������
	SetDrawBlendMode(DX_BLENDMODE_ADD, 192);

	DrawGraph(0, 0, m_hEffectScreen, true);
	//��ʂ��ڂ���
	GraphFilter(m_hEffectScreen, DX_GRAPH_FILTER_GAUSS, 16, 800);
	for (int i = 0; i < 8; i++)
	{
		DrawGraph(GetRand(4) - 2, GetRand(4) - 2, m_hEffectScreen, false);
	}

	GraphFilter(m_hEffectScreen, DX_GRAPH_FILTER_GAUSS, 32, 2400);
	for (int i = 0; i < 8; i++)
	{
		DrawGraph(GetRand(8) - 4, GetRand(8) - 4, m_hEffectScreen, false);
	}
	//���ɖ߂�
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

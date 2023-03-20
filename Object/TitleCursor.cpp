#include "TitleCursor.h"
#include "game.h"
#include <Dxlib.h>

TitleCursor::TitleCursor():
	m_padPos(0.0f,0.0f),
	m_isMenu(false)
{
	m_padPos.x = static_cast<float>(Game::kScreenWidth / 2);
	m_padPos.y = static_cast<float>(Game::kScreenHeight / 2 + 100);
	m_isMenu = true;
}

TitleCursor::~TitleCursor()
{
}

void TitleCursor::Init()
{
	
}

void TitleCursor::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	if (!m_isMenu)//���j���[����鎞�ɃJ�[�\���̈ʒu�������l�ɖ߂�
	{
		m_padPos.x = static_cast<float>(Game::kScreenWidth) / 2;
		m_padPos.y = static_cast<float>(Game::kScreenHeight) / 2 - 30;
	}
	PosSet();

	if (padState & PAD_INPUT_RIGHT)//�E
	{
		m_padPos.x += 10;
	}
	if (padState & PAD_INPUT_LEFT)//�E
	{
		m_padPos.x -= 10;
	}
	if (padState & PAD_INPUT_UP)//�E
	{
		m_padPos.y -= 10;
	}
	if (padState & PAD_INPUT_DOWN)//�E
	{
		m_padPos.y += 10;
	}
}

void TitleCursor::Draw()
{
	//�I��
	DrawSelection();
	//�p�b�h�̃J�[�\����\��
	DrawPadCursor();
}

//�v���C���[�̍s���͈�
void TitleCursor::PosSet()
{
	if (m_padPos.x < 0.0f) m_padPos.x = 1.0f;
	if (m_padPos.x > Game::kScreenWidth) m_padPos.x = static_cast<float>(Game::kScreenWidth) - 1.0f;
	if (m_padPos.y < 0.0f) m_padPos.y = 1.0f;
	if (m_padPos.y > Game::kScreenHeight) m_padPos.y = static_cast<float>(Game::kScreenHeight) - 1.0f;
}

void TitleCursor::DrawPadCursor()
{
	DrawCircle(static_cast<int>(m_padPos.x), static_cast<int>( m_padPos.y), 20, 0x00ffff, false);
	// �`��u�����h���[�h���A���t�@�u�����h�i�T�O���j�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawCircle(static_cast<int>(m_padPos.x), static_cast<int>(m_padPos.y), 19, 0xffff00, true);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
void TitleCursor::DrawSelection()
{

}
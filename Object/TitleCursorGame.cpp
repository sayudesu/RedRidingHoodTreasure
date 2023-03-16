#include "TitleCursorGame.h"
#include "game.h"
#include <Dxlib.h>

TitleCursorGame::TitleCursorGame() :
	m_mouseX(0),
	m_mouseY(0),
	m_padPos(0.0f, 0.0f)
{
	m_padPos.x = Game::kScreenWidth / 2;
	m_padPos.y = Game::kScreenHeight / 2 + 30;
}

TitleCursorGame::~TitleCursorGame()
{
}

void TitleCursorGame::Init()
{

}

void TitleCursorGame::Update()
{
	int padState = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	GetMousePoint(&m_mouseX, &m_mouseY);
	//m_padPos.x = m_mouseX;
	//m_padPos.y = m_mouseY;
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

void TitleCursorGame::Draw()
{
	//�I��
	DrawSelection();
	//�p�b�h�̃J�[�\����\��
	DrawPadCursor();
}

//�v���C���[�̍s���͈�
void TitleCursorGame::PosSet()
{
	if (m_padPos.x < 0.0f) m_padPos.x = 1.0f;
	if (m_padPos.x > Game::kScreenWidth) m_padPos.x = static_cast<float>(Game::kScreenWidth) - 1.0f;
	if (m_padPos.y < 0.0f) m_padPos.y = 1.0f;
	if (m_padPos.y > Game::kScreenHeight) m_padPos.y = static_cast<float>(Game::kScreenHeight) - 1.0f;
}

void TitleCursorGame::DrawPadCursor()
{
	DrawCircle(m_padPos.x, m_padPos.y, 20, 0x00ffff, false);
	// �`��u�����h���[�h���A���t�@�u�����h�i�T�O���j�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	DrawCircle(m_padPos.x, m_padPos.y, 19, 0xffff00, true);
	// �`��u�����h���[�h���m�[�u�����h�ɂ���
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
void TitleCursorGame::DrawSelection()
{

}
#include "ClearDirection.h"
#include "Image.h"
#include <Dxlib.h>

ClearDirection::ClearDirection():
	m_hMapChip(-1),
	m_hChest(-1),
	m_frameCount(0),m_chestNum(0),
	m_chestLeft(),m_chestTop(),
	m_chestRight(), m_chestBottom(),
	m_isChest()
{
	//�`�F�X�g�摜
	m_hMapChip = LoadGraph(Image::kMapTiles);
	m_hChest = DerivationGraph(288, 272, 32, 32, m_hMapChip);//�n�ʉ摜����ꕔ�𒊏o

	for (int i = 0; i < Clear::kChestNum; i++)
	{
		//�`�F�X�g�����ʒu
		m_chestLeft[i] = GetRand(Game::kScreenWidth);
		m_chestTop[i] = -150;
		m_chestRight[i] = m_chestLeft[i] + 100;
		m_chestBottom[i] = m_chestTop[i] + 100;
		//�`�F�X�g��\�����邩�ǂ���
		m_isChest[i] = false;
	}

}

ClearDirection::~ClearDirection()
{
}

void ClearDirection::Update()
{
	UpdatePlayer();
	UpdateChest();
}

void ClearDirection::Draw()
{
	DrawChest();
	DrawPlayer();
}

void ClearDirection::UpdatePlayer()
{
}

void ClearDirection::DrawPlayer()
{
}

void ClearDirection::UpdateChest()
{
	m_frameCount++;//�`�F�X�g�𑝂₷���߂̃t���[���J�E���g

	if (m_frameCount == 30)//0.5�b��1�ǉ�
	{
		if(m_chestNum < Clear::kChestNum)m_chestNum++;//�`�F�X�g��ǉ�
		m_frameCount = 0;//�J�E���g������
	}

	for (int i = 0; i < m_chestNum; i++)
	{
		m_chestTop[i] += 10;//���ɗ���
		m_chestBottom[i] += 10;// ���ɗ���

		m_isChest[i] = true;//�`��\��

		if (m_chestTop[i] > Game::kScreenHeight + 50)m_isChest[i] = false;//��ʊO�ɏo���`�F�X�g�͔�\��

		if (!m_isChest[i])//��\���`�F�X�g
		{
			m_chestLeft[i] = GetRand(Game::kScreenWidth);//X�������_��
			m_chestTop[i] = -150;//�����l�ɖ߂�
			m_chestRight[i] = m_chestLeft[i] + 100;//�����l�ɖ߂�
			m_chestBottom[i] = m_chestTop[i] + 100;//�����l�ɖ߂�
		}
	}
}

void ClearDirection::DrawChest()
{
	
	for (int i = 0; i < Clear::kChestNum; i++)
	{
		if (m_isChest[i])//�`�F�X�g����ʂɂ��邩�ǂ���
		{
			//�`�F�X�g
			DrawRotaGraph(m_chestLeft[i], m_chestTop[i],5, DX_PI,m_hChest, true, false);
		}
	}
}


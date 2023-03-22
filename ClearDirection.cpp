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
	m_hMapChip = LoadGraph(Image::kMapTiles);
	m_hChest = DerivationGraph(288, 272, 32, 32, m_hMapChip);//’n–Ê‰æ‘œ‚©‚çˆê•”‚ğ’Šo

	for (int i = 0; i < Clear::kChestNum; i++)
	{
		m_chestLeft[i] = GetRand(Game::kScreenWidth);
		m_chestTop[i] = -150;
		m_chestRight[i] = m_chestLeft[i] + 100;
		m_chestBottom[i] = m_chestTop[i] + 100;
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
	m_frameCount++;

	if (m_frameCount == 30)
	{
		if(m_chestNum < Clear::kChestNum)m_chestNum++;
		m_frameCount = 0;
	}

	for (int i = 0; i < m_chestNum; i++)
	{
		m_chestTop[i] += 10;
		m_chestBottom[i] += 10;

		m_isChest[i] = true;

		if (m_chestTop[i] > Game::kScreenHeight)m_isChest[i] = false;

		if (!m_isChest[i])
		{
			m_chestLeft[i] = GetRand(Game::kScreenWidth);
			m_chestTop[i] = -150;
			m_chestRight[i] = m_chestLeft[i] + 100;
			m_chestBottom[i] = m_chestTop[i] + 100;
		}
	}
}

void ClearDirection::DrawChest()
{
	
	for (int i = 0; i < Clear::kChestNum; i++)
	{
		if (m_isChest[i])
		{
			DrawRotaGraph(m_chestLeft[i], m_chestTop[i],5, DX_PI,m_hChest, true, false);
		}
	}
}


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
	//チェスト画像
	m_hMapChip = LoadGraph(Image::kMapTiles);
	m_hChest = DerivationGraph(288, 272, 32, 32, m_hMapChip);//地面画像から一部を抽出

	for (int i = 0; i < Clear::kChestNum; i++)
	{
		//チェスト初期位置
		m_chestLeft[i] = GetRand(Game::kScreenWidth);
		m_chestTop[i] = -150;
		m_chestRight[i] = m_chestLeft[i] + 100;
		m_chestBottom[i] = m_chestTop[i] + 100;
		//チェストを表示するかどうか
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
	m_frameCount++;//チェストを増やすためのフレームカウント

	if (m_frameCount == 30)//0.5秒に1つ追加
	{
		if(m_chestNum < Clear::kChestNum)m_chestNum++;//チェストを追加
		m_frameCount = 0;//カウント初期化
	}

	for (int i = 0; i < m_chestNum; i++)
	{
		m_chestTop[i] += 10;//下に落下
		m_chestBottom[i] += 10;// 下に落下

		m_isChest[i] = true;//描画表示

		if (m_chestTop[i] > Game::kScreenHeight + 50)m_isChest[i] = false;//画面外に出たチェストは非表示

		if (!m_isChest[i])//非表示チェスト
		{
			m_chestLeft[i] = GetRand(Game::kScreenWidth);//Xをランダム
			m_chestTop[i] = -150;//初期値に戻す
			m_chestRight[i] = m_chestLeft[i] + 100;//初期値に戻す
			m_chestBottom[i] = m_chestTop[i] + 100;//初期値に戻す
		}
	}
}

void ClearDirection::DrawChest()
{
	
	for (int i = 0; i < Clear::kChestNum; i++)
	{
		if (m_isChest[i])//チェストが画面にあるかどうか
		{
			//チェスト
			DrawRotaGraph(m_chestLeft[i], m_chestTop[i],5, DX_PI,m_hChest, true, false);
		}
	}
}


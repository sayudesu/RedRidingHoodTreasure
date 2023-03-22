#pragma once
#include "game.h"
class ClearDirection
{
public:
	ClearDirection();
	~ClearDirection();

	void Update();
	void Draw();

	void UpdatePlayer();
	void DrawPlayer();

	void UpdateChest();
	void DrawChest();

private:
	int m_hMapChip;
	int m_hChest;

	int m_frameCount;
	int m_chestNum;

	int m_chestLeft[Clear::kChestNum];
	int m_chestTop[Clear::kChestNum];
	int m_chestRight[Clear::kChestNum];
	int m_chestBottom[Clear::kChestNum];

	bool m_isChest[Clear::kChestNum];
};


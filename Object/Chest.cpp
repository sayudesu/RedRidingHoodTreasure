#include <Dxlib.h>
#include "Chest.h"
#include "Image.h"
#include "game.h"

namespace ChestPos
{
	constexpr int kLeft = 500;
	constexpr int kTop = 320;
	constexpr int kRight = kLeft + 80;
	constexpr int kBottom = kTop + 80;
}

Chest::Chest():
	m_hMapChip1(-1),
	m_hBox(-1),
	m_boxPuls(0)
{
	m_hMapChip1 = LoadGraph(Image::kMapTiles);
	m_hBox = DerivationGraph(288 + 32, 272, 32, 32, m_hMapChip1);//ínñ âÊëúÇ©ÇÁàÍïîÇíäèo
}

Chest::~Chest()
{
}

void Chest::Stage1Draw()
{

	DrawExtendGraph(ChestPos::kLeft, ChestPos::kTop, ChestPos::kRight, ChestPos::kBottom, m_hBox, true);


}

void Chest::Stage2Draw()
{
	DrawExtendGraph(ChestPos::kLeft, ChestPos::kTop, ChestPos::kRight, ChestPos::kBottom, m_hBox, true);
	DrawExtendGraph(ChestPos::kLeft + 80, ChestPos::kTop, ChestPos::kRight + 80, ChestPos::kBottom, m_hBox, true);
}

void Chest::Stage3UDraw()
{
	DrawExtendGraph(ChestPos::kLeft, ChestPos::kTop, ChestPos::kRight, ChestPos::kBottom, m_hBox, true);
	DrawExtendGraph(ChestPos::kLeft + 80, ChestPos::kTop, ChestPos::kRight + 80, ChestPos::kBottom, m_hBox, true);
	DrawExtendGraph(ChestPos::kLeft + 80 + 80, ChestPos::kTop, ChestPos::kRight + 80 + 80, ChestPos::kBottom, m_hBox, true);
}

#include "PlayerImage.h"

#include "PlayerImage.h"
#include <Dxlib.h>



namespace
{
	const char* const kPlayerImage = "Data/square.png";
}

PlayerImage::PlayerImage() :
	m_hPlayer(-1)
{
	
}

void PlayerImage::Init()
{
	m_hPlayer = LoadGraph(kPlayerImage);
}

void PlayerImage::End()
{
	DeleteGraph(m_hPlayer);
}

void PlayerImage::Draw()
{
}



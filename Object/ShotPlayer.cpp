#include "ShotPlayer.h"
#include "game.h"

ShotPlayer::ShotPlayer()
{

}

void ShotPlayer::Start(Vec2 pos)
{
	ShotBase::Start(pos);

	m_vec.x = 0.0f;
	m_vec.y = 0.0f;
}

void ShotPlayer::Update()
{
	if (!m_isExist) return;

	m_pos += m_vec;

	if (m_pos.x >= Game::kScreenWidth)
	{
		m_isExist = false;
	}
}

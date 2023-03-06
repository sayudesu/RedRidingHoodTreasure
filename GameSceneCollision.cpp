#include "GameSceneCollision.h"
#include "TitleCursorGame.h"
#include "game.h"
#include <Dxlib.h>

GameSceneCollision::GameSceneCollision() :
	m_pCursor(nullptr)
{
	m_pCursor = new TitleCursorGame;
}

GameSceneCollision::~GameSceneCollision()
{
	delete m_pCursor;
}

void GameSceneCollision::Init()
{
}

void GameSceneCollision::Update()
{
	m_pCursor->Update();
}

void GameSceneCollision::Draw()
{
}

bool GameSceneCollision::CollsionDemo()
{
	bool result = false;
	//printfDx("%f\n", m_pCursor->GetCursor().x);

	if ((m_pCursor->GetCursor().x > SceneSelect::kSelectLeft - 19) &&//19‚ÍZ‚Ì”¼Œa
		(m_pCursor->GetCursor().x < SceneSelect::kSelectRight + 19) &&
		(m_pCursor->GetCursor().y > SceneSelect::kSelectTop - 19) &&
		(m_pCursor->GetCursor().y < SceneSelect::kSelectBottom + 19))
	{
		result = true;
		float fl = 19 * 19;

		// ¶
		if (m_pCursor->GetCursor().x < SceneSelect::kSelectLeft)
		{
			// ¶ã
			if ((m_pCursor->GetCursor().y < SceneSelect::kSelectTop))
			{
				if ((DistanceSqrf(SceneSelect::kSelectLeft, SceneSelect::kSelectTop,
					m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
				{
					result = false;
				}
			}
			else
			{
				// ¶‰º
				if ((m_pCursor->GetCursor().y > SceneSelect::kSelectBottom))
				{
					if ((DistanceSqrf(SceneSelect::kSelectLeft, SceneSelect::kSelectBottom,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
			}
		}
		else
		{
			// ‰E
			if (m_pCursor->GetCursor().x > SceneSelect::kSelectRight)
			{
				// ‰Eã
				if ((m_pCursor->GetCursor().y < SceneSelect::kSelectTop))
				{
					if ((DistanceSqrf(SceneSelect::kSelectRight, SceneSelect::kSelectTop,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
				else
				{
					// ‰E‰º
					if ((m_pCursor->GetCursor().y > SceneSelect::kSelectBottom))
					{
						if ((DistanceSqrf(SceneSelect::kSelectRight, SceneSelect::kSelectBottom,
							m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
						{
							result = false;
						}
					}
				}
			}
		}

	}

	return result;
}

float GameSceneCollision::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool GameSceneCollision::CollsionStage1()
{
	bool result = false;

	if ((m_pCursor->GetCursor().x > SceneSelect::kSelectLeft2 - 19) &&//19‚ÍZ‚Ì”¼Œa
		(m_pCursor->GetCursor().x < SceneSelect::kSelectRight2 + 19) &&
		(m_pCursor->GetCursor().y > SceneSelect::kSelectTop2 - 19) &&
		(m_pCursor->GetCursor().y < SceneSelect::kSelectBottom2 + 19))
	{
		result = true;
		float fl = 19 * 19;

		// ¶
		if (m_pCursor->GetCursor().x < SceneSelect::kSelectLeft2)
		{
			// ¶ã
			if ((m_pCursor->GetCursor().y < SceneSelect::kSelectTop2))
			{
				if ((DistanceSqrfStage1(SceneSelect::kSelectLeft2, SceneSelect::kSelectTop2,
					m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
				{
					result = false;
				}
			}
			else
			{
				// ¶‰º
				if ((m_pCursor->GetCursor().y > SceneSelect::kSelectBottom2))
				{
					if ((DistanceSqrfStage1(SceneSelect::kSelectLeft2, SceneSelect::kSelectBottom2,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
			}
		}
		else
		{
			// ‰E
			if (m_pCursor->GetCursor().x > SceneSelect::kSelectRight2)
			{
				// ‰Eã
				if ((m_pCursor->GetCursor().y < SceneSelect::kSelectTop2))
				{
					if ((DistanceSqrfStage1(SceneSelect::kSelectRight2, SceneSelect::kSelectTop2,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
				else
				{
					// ‰E‰º
					if ((m_pCursor->GetCursor().y > SceneSelect::kSelectBottom2))
					{
						if ((DistanceSqrfStage1(SceneSelect::kSelectRight2, SceneSelect::kSelectBottom2,
							m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
						{
							result = false;
						}
					}
				}
			}
		}

	}

	return result;
}



float GameSceneCollision::DistanceSqrfStage1(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool GameSceneCollision::CollsionEnd()
{
	bool result = false;

	if ((m_pCursor->GetCursor().x > SceneSelect::kSelectLeft3 - 19) &&//19‚ÍZ‚Ì”¼Œa
		(m_pCursor->GetCursor().x < SceneSelect::kSelectRight3 + 19) &&
		(m_pCursor->GetCursor().y > SceneSelect::kSelectTop3 - 19) &&
		(m_pCursor->GetCursor().y < SceneSelect::kSelectBottom3 + 19))
	{
		result = true;
		float fl = 19 * 19;

		// ¶
		if (m_pCursor->GetCursor().x < SceneSelect::kSelectLeft3)
		{
			// ¶ã
			if ((m_pCursor->GetCursor().y < SceneSelect::kSelectTop3))
			{
				if ((DistanceSqrfEnd(SceneSelect::kSelectLeft3, SceneSelect::kSelectTop3,
					m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
				{
					result = false;
				}
			}
			else
			{
				// ¶‰º
				if ((m_pCursor->GetCursor().y > SceneSelect::kSelectBottom3))
				{
					if ((DistanceSqrfEnd(SceneSelect::kSelectLeft3, SceneSelect::kSelectBottom3,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
			}
		}
		else
		{
			// ‰E
			if (m_pCursor->GetCursor().x > SceneSelect::kSelectRight3)
			{
				// ‰Eã
				if ((m_pCursor->GetCursor().y < SceneSelect::kSelectTop3))
				{
					if ((DistanceSqrfEnd(SceneSelect::kSelectRight3, SceneSelect::kSelectTop3,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
				else
				{
					// ‰E‰º
					if ((m_pCursor->GetCursor().y > SceneSelect::kSelectBottom3))
					{
						if ((DistanceSqrfEnd(SceneSelect::kSelectRight3, SceneSelect::kSelectBottom3,
							m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
						{
							result = false;
						}
					}
				}
			}
		}

	}

	return result;
}

float GameSceneCollision::DistanceSqrfEnd(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

#include "TitleCollision.h"
#include "TitleCursor.h"
#include "game.h"
#include <Dxlib.h>
namespace
{
	constexpr int circleRadius = 19;//‰~‚Ì”¼Œa
}
TitleCollision::TitleCollision():
	m_pCursor(nullptr)
{
	m_pCursor = new TitleCursor;
}

TitleCollision::~TitleCollision()
{
	delete m_pCursor;
}

void TitleCollision::Init()
{
}

void TitleCollision::Update()
{
	m_pCursor->Update();
}

void TitleCollision::Draw()
{
}

bool TitleCollision::CollsionDemo()
{
	bool result = false;
	//printfDx("%f\n", m_pCursor->GetCursor().x);

	if ((m_pCursor->GetCursor().x > TitleMenu::kSelection1X - circleRadius) &&//19‚ÍZ‚Ì”¼Œa
		(m_pCursor->GetCursor().x < TitleMenu::kSelectionBottom1X + circleRadius) &&
		(m_pCursor->GetCursor().y > TitleMenu::kSelection1Y - circleRadius) &&
		(m_pCursor->GetCursor().y < TitleMenu::kSelectionBottom1Y+ circleRadius))
	{
		result = true;
		float fl = 19 * 19;

		// ¶
		if (m_pCursor->GetCursor().x < TitleMenu::kSelection1X)
		{
			// ¶ã
			if ((m_pCursor->GetCursor().y < TitleMenu::kSelection1Y))
			{
				if ((DistanceSqrf(TitleMenu::kSelection1X, TitleMenu::kSelection1Y,
					m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
				{
					result = false;
				}
			}
			else
			{
				// ¶‰º
				if ((m_pCursor->GetCursor().y > TitleMenu::kSelectionBottom1Y))
				{
					if ((DistanceSqrf(TitleMenu::kSelection1X, TitleMenu::kSelectionBottom1Y,
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
			if (m_pCursor->GetCursor().x > TitleMenu::kSelectionBottom1X)
			{
				// ‰Eã
				if ((m_pCursor->GetCursor().y < TitleMenu::kSelection1Y))
				{
					if ((DistanceSqrf(TitleMenu::kSelectionBottom1X, TitleMenu::kSelection1Y,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
				else
				{
					// ‰E‰º
					if ((m_pCursor->GetCursor().y > TitleMenu::kSelectionBottom1Y))
					{
						if ((DistanceSqrf(TitleMenu::kSelectionBottom1X, TitleMenu::kSelectionBottom1Y,
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

float TitleCollision::DistanceSqrf(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool TitleCollision::CollsionStage1()
{
	bool result = false;

	if ((m_pCursor->GetCursor().x > TitleMenu::kSelection2X - circleRadius) &&//19‚ÍZ‚Ì”¼Œa
		(m_pCursor->GetCursor().x < TitleMenu::kSelectionBottom2X + circleRadius) &&
		(m_pCursor->GetCursor().y > TitleMenu::kSelection2Y - circleRadius) &&
		(m_pCursor->GetCursor().y < TitleMenu::kSelectionBottom2Y + circleRadius))
	{
		result = true;
		float fl = 19 * 19;

		// ¶
		if (m_pCursor->GetCursor().x < TitleMenu::kSelection2X)
		{
			// ¶ã
			if ((m_pCursor->GetCursor().y < TitleMenu::kSelection2Y))
			{
				if ((DistanceSqrfStage1(TitleMenu::kSelection2X, TitleMenu::kSelection2Y,
					m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
				{
					result = false;
				}
			}
			else
			{
				// ¶‰º
				if ((m_pCursor->GetCursor().y > TitleMenu::kSelectionBottom2Y))
				{
					if ((DistanceSqrfStage1(TitleMenu::kSelection2X, TitleMenu::kSelectionBottom2Y,
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
			if (m_pCursor->GetCursor().x > TitleMenu::kSelectionBottom2X)
			{
				// ‰Eã
				if ((m_pCursor->GetCursor().y < TitleMenu::kSelection2Y))
				{
					if ((DistanceSqrfStage1(TitleMenu::kSelectionBottom2X, TitleMenu::kSelection2Y,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
				else
				{
					// ‰E‰º
					if ((m_pCursor->GetCursor().y > TitleMenu::kSelectionBottom2Y))
					{
						if ((DistanceSqrfStage1(TitleMenu::kSelectionBottom2X, TitleMenu::kSelectionBottom2Y,
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



float TitleCollision::DistanceSqrfStage1(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

bool TitleCollision::CollsionEnd()
{
	bool result = false;

	if ((m_pCursor->GetCursor().x > TitleMenu::kSelection3X - circleRadius) &&//19‚ÍZ‚Ì”¼Œa
		(m_pCursor->GetCursor().x < TitleMenu::kSelectionBottom3X + circleRadius) &&
		(m_pCursor->GetCursor().y > TitleMenu::kSelection3Y - circleRadius) &&
		(m_pCursor->GetCursor().y < TitleMenu::kSelectionBottom3Y + circleRadius))
	{
		result = true;
		float fl = 19 * 19;

		// ¶
		if (m_pCursor->GetCursor().x < TitleMenu::kSelection3X)
		{
			// ¶ã
			if ((m_pCursor->GetCursor().y < TitleMenu::kSelection3Y))
			{
				if ((DistanceSqrfEnd(TitleMenu::kSelection3X, TitleMenu::kSelection3Y,
					m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
				{
					result = false;
				}
			}
			else
			{
				// ¶‰º
				if ((m_pCursor->GetCursor().y > TitleMenu::kSelectionBottom3Y))
				{
					if ((DistanceSqrfEnd(TitleMenu::kSelection3X, TitleMenu::kSelectionBottom3Y,
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
			if (m_pCursor->GetCursor().x > TitleMenu::kSelectionBottom3X)
			{
				// ‰Eã
				if ((m_pCursor->GetCursor().y < TitleMenu::kSelection3Y))
				{
					if ((DistanceSqrfEnd(TitleMenu::kSelectionBottom3X, TitleMenu::kSelection3Y,
						m_pCursor->GetCursor().x, m_pCursor->GetCursor().y) >= fl))
					{
						result = false;
					}
				}
				else
				{
					// ‰E‰º
					if ((m_pCursor->GetCursor().y > TitleMenu::kSelectionBottom3Y))
					{
						if ((DistanceSqrfEnd(TitleMenu::kSelectionBottom3X, TitleMenu::kSelectionBottom3Y,
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

float TitleCollision::DistanceSqrfEnd(const float t_x1, const float t_y1, const float t_x2, const float t_y2)
{
	float dx = t_x2 - t_x1;
	float dy = t_y2 - t_y1;

	return (dx * dx) + (dy * dy);
}

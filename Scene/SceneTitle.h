#pragma once
#include "SceneBase.h"

class SceneTitle : public SceneBase
{
public:
	SceneTitle()
	{
		m_isEnd = false;
	}
	virtual ~SceneTitle() {}

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	virtual bool IsEnd() { return m_isEnd; }
private:

	bool m_isEnd;

};

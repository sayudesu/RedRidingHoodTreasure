#pragma once
#include "SceneBase.h"

class SceneResult : public SceneBase
{
public:
	SceneResult()
	{
		m_isEnd = false;
	}
	virtual ~SceneResult() {}

	virtual void Init();
	virtual void End();

	virtual SceneBase* Update() override;
	virtual void Draw();

	virtual bool IsEnd() { return m_isEnd; }
private:

	bool m_isEnd;

};

